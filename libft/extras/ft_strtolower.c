/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:24:45 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/extras.h"

static void	ft_tolower_wrapper(unsigned int index, char *s)
{
	(void) index;
	*s = (char)ft_tolower(*s);
	return ;
}

void	ft_strtolower(char *str)
{
	ft_striteri(str, &ft_tolower_wrapper);
}
