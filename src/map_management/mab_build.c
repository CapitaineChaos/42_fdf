/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mab_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:35:50 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 15:46:08 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	build_map(t_fdf *fdf)
{
	t_elem	*elem;
	t_vec4	*pts;
	int		*colors;
	int		i;

	pts = get_map_pts(fdf);
	colors = get_map_int(fdf);
	elem = fdf->map_raw;
	i = 0;
	while (elem)
	{
		pts[i].x = (double)elem->col;
		pts[i].y = (double)elem->line;
		pts[i].z = (double)elem->value;
		pts[i].w = 1.0;
		colors[i] = elem->color;
		elem = elem->next;
		i++;
	}
	fdf->map_pts = pts;
	fdf->map_colors = colors;
	return (i);
}
