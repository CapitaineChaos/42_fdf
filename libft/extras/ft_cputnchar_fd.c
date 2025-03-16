/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cputnchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:23:50 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/extras.h"

ssize_t	ft_cputnchar_fd(char c, size_t nb, int fd)
{
	size_t	i;
	ssize_t	len;
	ssize_t	clen;

	i = 0;
	len = 0;
	while (i < nb)
	{
		clen = write(fd, &c, 1);
		if (clen > 0)
			len++;
		i++;
	}
	return (len);
}
