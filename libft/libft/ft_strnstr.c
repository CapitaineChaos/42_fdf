/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:53:13 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i + len_little <= len)
	{
		if (big[i] == little[0])
		{
			if (ft_memcmp(big + i, little, len_little) == 0)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
