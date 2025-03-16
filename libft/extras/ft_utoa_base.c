/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:24:49 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/extras.h"

char	*ft_utoa_base(size_t nb, char *base)
{
	size_t	len;
	size_t	base_len;
	char	*snum;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (NULL);
	len = ft_unblen(nb, base_len);
	snum = (char *)malloc((len + 1) * sizeof (char));
	if (!snum)
		return (NULL);
	snum[len] = '\0';
	while (len--)
	{
		snum[len] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (snum);
}
