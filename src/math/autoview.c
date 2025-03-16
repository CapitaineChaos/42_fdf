/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autoview.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:19:47 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 20:34:42 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	compute_scale(t_bounds bounds)
{
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = 2.0 * 0.8 / (bounds.x_max - bounds.x_min);
	scale_y = 2.0 * 0.8 / (bounds.y_max - bounds.y_min);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale);
}

static void	seek_bounds(t_fdf *fdf, t_mat4 proj_view_mv, t_bounds *bounds)
{
	int		n;
	int		i;
	t_vec4	p;

	n = fdf->mapinfo.nb;
	i = 0;
	while (i < n)
	{
		p = mat4_apply(proj_view_mv, fdf->map_pts[i]);
		if (p.w != 0.0)
		{
			p.x /= p.w;
			p.y /= p.w;
			p.z /= p.w;
		}
		if (p.x < bounds->x_min)
			bounds->x_min = p.x;
		if (p.x > bounds->x_max)
			bounds->x_max = p.x;
		if (p.y < bounds->y_min)
			bounds->y_min = p.y;
		if (p.y > bounds->y_max)
			bounds->y_max = p.y;
		i++;
	}
}

t_mat4	compute_autoview_mat4(t_fdf *fdf, t_mat4 proj_view_mv)
{
	t_bounds	bounds;
	double		scale;
	double		tx;
	double		ty;
	t_mat4		adjustment;

	bounds.x_min = 1e9;
	bounds.y_min = 1e9;
	bounds.x_max = -1e9;
	bounds.y_max = -1e9;
	bounds.z_min = 0.0;
	bounds.z_max = 0.0;
	seek_bounds(fdf, proj_view_mv, &bounds);
	scale = compute_scale(bounds);
	tx = -scale * ((bounds.x_min + bounds.x_max) / 2.0);
	ty = -scale * ((bounds.y_min + bounds.y_max) / 2.0);
	adjustment = create_translate_mat4(tx, ty);
	adjustment.m[0][0] = scale;
	adjustment.m[1][1] = scale;
	return (adjustment);
}
