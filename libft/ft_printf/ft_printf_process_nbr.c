/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:24:06 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_nbr(long nb, t_format *ft, int *count)
{
	char	*tmp;
	size_t	nb_spaces_before;
	size_t	nb_spaces_after;
	size_t	nb_zeros_before;
	size_t	nb_zeros_after;

	if (nb < 0)
		nb = -nb;
	tmp = ft_ltoa(nb);
	nb_zeros_before = ft->nb_before - (int)(ft->sign != '\0');
	nb_zeros_after = ft->nb_after;
	set_strparams(ft->newstr_len, -1, ft);
	nb_spaces_before = ft->nb_before;
	nb_spaces_after = ft->nb_after;
	*count += ft_cputnchar_fd(' ', nb_spaces_before, 1);
	*count += ft_cputnchar_fd(ft->sign, (int)(ft->sign != '\0'), 1);
	*count += ft_cputnchar_fd('0', nb_zeros_before, 1);
	*count += ft_cputstrn_fd(tmp, ft->nb_len, 1);
	*count += ft_cputnchar_fd('0', nb_zeros_after, 1);
	*count += ft_cputnchar_fd(' ', nb_spaces_after, 1);
	free(tmp);
	return ;
}

void	process_unb(va_list args, t_format *ft, int *count)
{
	long	nb;

	(void) ft;
	nb = (long)va_arg(args, unsigned int);
	if (nb == 0 && ft->precision == 0)
	{
		set_strparams(0, ft->width, ft);
		apply_str((char *){&ft->sign}, ft, count);
		return ;
	}
	ft->nb_len = ft_unblen(nb, 10);
	set_nbrparams(0, ft);
	apply_nbr(nb, ft, count);
}

void	process_nbr(va_list args, t_format *ft, int *count)
{
	long	nb;
	int		flag;

	(void) ft;
	nb = (long)va_arg(args, int);
	if (nb < 0)
		ft->sign = '-';
	if (nb >= 0 && ft->flags.plus)
		ft->sign = '+';
	if (nb >= 0 && ft->flags.space)
		ft->sign = ' ';
	flag = (int)(ft->sign != '\0');
	if (nb == 0 && ft->precision == 0)
	{
		set_strparams(flag, ft->width, ft);
		apply_str((char *){&ft->sign}, ft, count);
		return ;
	}
	ft->nb_len = ft_nblen(nb, 10);
	if (nb < 0)
		ft->nb_len -= 1;
	set_nbrparams(flag, ft);
	apply_nbr(nb, ft, count);
}
