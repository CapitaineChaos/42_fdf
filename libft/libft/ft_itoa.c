/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:59:46 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_nblen(int n)
{
	int	len;

	len = n <= 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		sgn;

	sgn = 1;
	len = get_nblen(n);
	s = (char *)malloc((len + 1) * sizeof (char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		sgn = -1;
	}
	s[len] = '\0';
	if (n == 0)
		s[len - 1] = '0';
	while (n != 0)
	{
		s[len - 1] = (sgn * (n % 10)) + '0';
		len--;
		n = n / 10;
	}
	return (s);
}
