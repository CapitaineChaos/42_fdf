/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:44:30 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_handlefct	get_handle(char c)
{
	if (c == 'c')
		return (process_chr);
	if (c == 's')
		return (process_str);
	if (c == 'p')
		return (process_ptr);
	if (c == 'd' || c == 'i')
		return (process_nbr);
	if (c == 'u')
		return (process_unb);
	if (c == 'x' || c == 'X')
		return (process_hex);
	if (c == '%')
		return (process_pct);
	return (NULL);
}

const char	*extract_flags(const char *str, t_format *format)
{
	format->flags.dash = 0;
	format->flags.zero = 0;
	format->flags.sharp = 0;
	format->flags.space = 0;
	format->flags.plus = 0;
	str++;
	while (ft_strchr("-0# +", *str))
	{
		if (*str == '-')
			format->flags.dash = 1;
		if (*str == '0')
			format->flags.zero = 1;
		if (*str == '#')
			format->flags.sharp = 1;
		if (*str == ' ')
			format->flags.space = 1;
		if (*str == '+')
			format->flags.plus = 1;
		str++;
	}
	if (format->flags.dash)
		format->flags.zero = 0;
	if (format->flags.plus)
		format->flags.space = 0;
	return (str);
}

const char	*extract_dims(const char *str, t_format *format)
{
	format->width = 0;
	format->sign = '\0';
	format->hex = '\0';
	format->fill = ' ';
	format->precision = -1;
	if (*str == '\0')
		return (str);
	format->width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		format->precision = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	if (format->precision > 0)
		format->flags.zero = 0;
	format->argtype = *str;
	return (str);
}

int	extract_format(const char *str, va_list args, t_format *ft, int *count)
{
	const char	*suite;
	t_handlefct	h_function;
	int			len;

	suite = extract_flags(str, ft);
	suite = extract_dims(suite, ft);
	suite++;
	len = (int)(suite - str);
	h_function = get_handle(ft->argtype);
	if (!ft->argtype)
		ft->argtype = 's';
	if (h_function)
		h_function(args, ft, count);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;
	t_format	format;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			str += simple_str(str, &count);
		else
			str += extract_format(str, args, &format, &count);
	}
	va_end(args);
	return (count);
}
