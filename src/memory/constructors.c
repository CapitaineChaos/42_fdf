/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:26:58 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:56:25 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt2	*get_map_view(t_fdf *fdf)
{
	t_pt2	*map;

	map = (t_pt2 *)malloc(fdf->mapinfo.nb * sizeof(t_pt2));
	if (!map)
		crash_fdf(fdf, 1);
	return (map);
}

t_vec4	*get_map_pts(t_fdf *fdf)
{
	t_vec4	*map;

	map = (t_vec4 *)malloc(fdf->mapinfo.nb * sizeof(t_vec4));
	if (!map)
		crash_fdf(fdf, 1);
	ft_memset(map, 0, fdf->mapinfo.nb * sizeof(t_vec4));
	return (map);
}

int	*get_map_int(t_fdf *fdf)
{
	int	*map;

	map = (int *)malloc((fdf->mapinfo.nb) * sizeof(int));
	if (!map)
		crash_fdf(fdf, 1);
	return (map);
}
