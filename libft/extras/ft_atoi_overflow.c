/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:05:41 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/12 18:32:45 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"

int	ft_atoi_overflow(const char *str, int *res)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str++ - '0');
		if (nbr * sign > INT_MAX || nbr * sign < INT_MIN)
			return (1);
	}
	nbr *= sign;
	*res = (int)nbr;
	return (0);
}
