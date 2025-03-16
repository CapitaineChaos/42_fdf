/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:15:50 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/extras.h"

size_t	ft_nblen(long long int nb, size_t base_len)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (ft_unblen(-1 * nb, base_len) + 1);
	return (ft_unblen(nb, base_len));
}
