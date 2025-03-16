/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:45:19 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/11 22:19:38 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static const char	*get_start_charset(const char *s, const char *charset)
{
	while (*s && ft_strchr(charset, *s))
		s++;
	return (s);
}

static size_t	get_nb(const char *s, const char *charset)
{
	int	nb;

	nb = 0;
	while (*s)
	{
		s = get_start_charset(s, charset);
		if (*s)
			nb++;
		s = ft_strchr_charset(s, charset);
		if (!s)
			return (nb);
	}
	return (nb);
}

static void	*free_tab(char **tab, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	get_wdlen(const char *s, const char *charset)
{
	size_t	len;
	char	*end;

	end = ft_strchr_charset(s, charset);
	if (!end)
		end = (char *)s + ft_strlen(s);
	len = (size_t)(end - s);
	return (len);
}

char	**ft_split_charset(char const *s, const char *charset)
{
	size_t	nbstr;
	size_t	wdlen;
	size_t	i;
	char	**tab;

	if (!s)
		return (NULL);
	nbstr = get_nb(s, charset);
	tab = (char **)malloc((nbstr + 1) * sizeof (char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nbstr)
	{
		s = get_start_charset(s, charset);
		wdlen = get_wdlen(s, charset);
		tab[i] = ft_substr(s, 0, wdlen);
		if (!tab[i])
			return (free_tab(tab, i));
		s = s + wdlen;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
