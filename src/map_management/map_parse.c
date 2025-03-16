/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:01:52 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:14:21 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_color(char *s, t_elem *elem)
{
	int	k;

	k = 0;
	if (s[0] && s[1] && s[0] == '0' && s[1] == 'x')
	{
		s += 2;
		while (s[k] != '\0')
		{
			elem->color <<= 4;
			if (s[k] >= '0' && s[k] <= '9')
				elem->color += s[k] - 48;
			else if (s[k] >= 'A' && s[k] <= 'Z')
				elem->color += s[k] - 55;
			else if (s[k] >= 'a' && s[k] <= 'z')
				elem->color += s[k] - 87;
			else
				return (1);
			if (k > 5)
				return (1);
			k++;
		}
		return (0);
	}
	return (1);
}

void	*abort_raw_col(t_elem *elem)
{
	t_elem	*next;

	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	return (NULL);
}

t_elem	*build_raw_col(char *s, int y, int x)
{
	t_elem	*new_elem;
	char	*str;
	int		ret;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return (NULL);
	new_elem->next = NULL;
	new_elem->line = y;
	new_elem->col = x;
	new_elem->color = 0;
	if (!ft_isdigit(*s) && *s != '-')
		return (abort_raw_col(new_elem));
	ret = ft_atoi_overflow(s, &new_elem->value);
	if (ret)
		return (abort_raw_col(new_elem));
	str = ft_strchr(s, ',');
	ret = 0;
	if (str)
		ret = parse_color(str + 1, new_elem);
	if (str && ret)
		return (abort_raw_col(new_elem));
	if (!str)
		new_elem->color = 0xFFFFFF;
	return (new_elem);
}

int	build_raw_line(t_fdf *fdf, char **line)
{
	int		x;
	t_elem	*new;

	if (!*line)
		return (free_rawline(line), 0);
	x = 0;
	while (line[x])
	{
		new = build_raw_col(line[x], fdf->mapinfo.nb_y, x);
		if (!new)
			return (free_rawline(line), -1);
		append_elem(fdf, new);
		x++;
	}
	free_rawline(line);
	ft_printf(".");
	if (fdf->mapinfo.nb_x != -1 && fdf->mapinfo.nb_x != x)
		return (-1);
	fdf->mapinfo.nb_x = x;
	fdf->mapinfo.nb_y++;
	return (x);
}

int	read_raw_map(char *map_name, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(map_name, 0);
	if (!fd)
		return (2);
	line = get_next_line(fd);
	ret = 0;
	fdf->mapinfo.nb_y = 0;
	ft_printf("Reading map: %s\n", map_name);
	while (line)
	{
		if (ret != -1)
			ret = build_raw_line(fdf, ft_split_charset(line, " \t\n\v"));
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	if (ret == -1)
		return (1);
	fdf->mapinfo.nb = fdf->mapinfo.nb_x * fdf->mapinfo.nb_y;
	ft_printf("\n");
	return (0);
}
