/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:36:14 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	tonum(char c)
{
	return ((int)(c - '0'));
}

int	ft_atoi(const char *nptr)
{
	int		signe;
	long	nb;

	signe = 1;
	nb = 0;
	while (ft_isspace((unsigned char)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit((unsigned char)*nptr))
	{
		nb = nb * 10 + tonum(*nptr);
		nptr++;
	}
	return ((int)(signe * nb));
}
