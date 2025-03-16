/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:19:00 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 01:23:26 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_display_points(t_fdf *fdf, int prm)
{
	t_vec4	res;
	t_proj	*proj;
	int		i;

	proj = fdf->cur_proj;
	if ((prm & 2) != 2)
		compute_total_transform(fdf, &proj->pipe, &proj->transform, prm);
	i = 0;
	while (i < fdf->mapinfo.nb)
	{
		res = mat4_apply(proj->pipe.total, fdf->map_pts[i]);
		if (res.w != 0.0)
		{
			res.x /= res.w;
			res.y /= res.w;
			res.z /= res.w;
			res.w = 1.0;
		}
		fdf->map_view[i] = res;
		i++;
	}
}
