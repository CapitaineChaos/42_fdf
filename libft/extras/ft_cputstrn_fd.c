/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cputstrn_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:37:31 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/extras.h"

ssize_t	ft_cputstrn_fd(char *s, size_t n, int fd)
{
	ssize_t	len;
	ssize_t	clen;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (i < n)
	{
		clen = ft_cputchar_fd(s[i], fd);
		if (clen > 0)
			len++;
		i++;
	}
	return (len);
}
