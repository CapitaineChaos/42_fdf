/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:24:03 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_str(const char *str, t_format *ft, int *count)
{
	*count += ft_cputnchar_fd(' ', ft->nb_before, 1);
	*count += ft_cputstrn_fd((char *)str, ft->copy_len, 1);
	*count += ft_cputnchar_fd(' ', ft->nb_after, 1);
}

void	process_str(va_list args, t_format *ft, int *count)
{
	char	*str;

	if (ft->precision == 0)
	{
		set_strparams(0, -1, ft);
		apply_str("", ft, count);
		return ;
	}
	str = (char *)va_arg(args, char *);
	if (!str)
	{
		if (ft->precision >= 6 || ft->precision == -1)
		{
			set_strparams(6, 6, ft);
			apply_str("(null)", ft, count);
			return ;
		}
		set_strparams(0, -1, ft);
		apply_str("", ft, count);
		return ;
	}
	set_strparams(ft_strlen(str), ft->precision, ft);
	apply_str(str, ft, count);
}

void	process_pct(va_list args, t_format *ft, int *count)
{
	char	s[2];

	(void) args;
	s[0] = '%';
	s[1] = '\0';
	ft->width = 0;
	set_strparams(1, -1, ft);
	apply_str((const char *)s, ft, count);
}

void	process_chr(va_list args, t_format *ft, int *count)
{
	char	c;
	char	s[2];

	c = (char)va_arg(args, int);
	s[0] = c;
	s[1] = '\0';
	set_strparams(1, -1, ft);
	apply_str((const char *)s, ft, count);
}

size_t	simple_str(const char *str, int *count)
{
	size_t		len;
	const char	*end;

	end = str;
	while (*end && *end != '%')
		end++;
	len = (size_t)(end - str);
	*count += ft_cputstrn_fd((char *) str, len, 1);
	return (len);
}
