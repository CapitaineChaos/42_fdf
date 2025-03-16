/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:24:06 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_hex(unsigned long long nb, t_format *ft, int *count)
{
	char	*tmp;
	size_t	nb_spaces_before;
	size_t	nb_spaces_after;
	size_t	nb_zeros_before;
	size_t	nb_zeros_after;

	tmp = ft_utoa_base(nb, "0123456789abcdef");
	nb_zeros_before = ft->nb_before - 2 * (ft->hex != '\0');
	nb_zeros_after = ft->nb_after;
	set_strparams(ft->newstr_len, -1, ft);
	nb_spaces_before = ft->nb_before;
	nb_spaces_after = ft->nb_after;
	*count += ft_cputnchar_fd(' ', nb_spaces_before, 1);
	*count += ft_cputnchar_fd('0', (ft->hex != '\0'), 1);
	*count += ft_cputnchar_fd(ft->hex, (ft->hex != '\0'), 1);
	*count += ft_cputnchar_fd('0', nb_zeros_before, 1);
	if (ft->argtype == 'X')
		ft_strtoupper(tmp);
	*count += ft_cputstrn_fd(tmp, ft->nb_len, 1);
	*count += ft_cputnchar_fd('0', nb_zeros_after, 1);
	*count += ft_cputnchar_fd(' ', nb_spaces_after, 1);
	free(tmp);
	return ;
}

void	process_ptr(va_list args, t_format *ft, int *count)
{
	unsigned long long	nb;

	(void) ft;
	nb = (unsigned long long int)va_arg(args, unsigned long long int);
	if ((ft->flags.sharp || ft->argtype == 'p') && nb != 0)
		ft->hex = 'x';
	if (nb == 0)
	{
		set_strparams(5, -1, ft);
		apply_str("(nil)", ft, count);
		return ;
	}
	ft->nb_len = ft_unblen(nb, 16);
	set_nbrparams(2 * (ft->hex != '\0'), ft);
	apply_hex(nb, ft, count);
}

void	process_hex(va_list args, t_format *ft, int *count)
{
	unsigned long long	nb;

	(void) ft;
	nb = (unsigned long long)va_arg(args, unsigned int);
	if (ft->flags.sharp && nb != 0)
	{
		ft->hex = ft->argtype;
	}
	if (nb == 0 && ft->precision == 0)
	{
		set_strparams(0, ft->width, ft);
		apply_str("", ft, count);
		return ;
	}
	ft->nb_len = ft_unblen(nb, 16);
	set_nbrparams(2 * (ft->hex != '\0'), ft);
	apply_hex(nb, ft, count);
}
