/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:47:51 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	nb;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (dst_len >= siz)
		return (siz + src_len);
	nb = siz - dst_len - 1;
	if (src_len < nb)
		nb = src_len;
	if (nb > 0)
	{
		ft_memcpy(dest + dst_len, src, nb);
		dest[dst_len + nb] = '\0';
	}
	return (dst_len + src_len);
}
