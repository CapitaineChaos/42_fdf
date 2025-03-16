/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:42:19 by smaitre           #+#    #+#             */
/*   Updated: 2025/02/05 18:04:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static const char	*ft_strchriset(const char *s, const char *set)
{
	while (*s && ft_strchr(set, (int)*s) != NULL)
		s++;
	return (s);
}

static const char	*ft_strrchriset(const char *s, const char *set)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && ft_strchr(set, (int)s[len - 1]) != NULL)
		len--;
	return (s + len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1 || *s1 == '\0')
		return (ft_strdup(""));
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	s1 = ft_strchriset(s1, set);
	return (ft_substr(s1, 0, (size_t)(ft_strrchriset(s1, set) - s1)));
}
