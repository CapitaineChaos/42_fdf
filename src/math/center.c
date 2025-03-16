/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:59:19 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:36:17 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	compute_diag(t_fdf *fdf)
{
	t_bounds	b;
	double		diag;

	b = fdf->mapinfo.bounds;
	diag = sqrt((b.x_max - b.x_min) * (b.x_max - b.x_min)
			+ (b.y_max - b.y_min) * (b.y_max - b.y_min)
			+ (b.z_max - b.z_min) * (b.z_max - b.z_min));
	return (diag);
}

static void	rec_bounds(t_fdf *fdf, t_vec3 *v)
{
	if (v->x < fdf->mapinfo.bounds.x_min)
		fdf->mapinfo.bounds.x_min = v->x;
	if (v->x > fdf->mapinfo.bounds.x_max)
		fdf->mapinfo.bounds.x_max = v->x;
	if (v->y < fdf->mapinfo.bounds.y_min)
		fdf->mapinfo.bounds.y_min = v->y;
	if (v->y > fdf->mapinfo.bounds.y_max)
		fdf->mapinfo.bounds.y_max = v->y;
	if (v->z < fdf->mapinfo.bounds.z_min)
		fdf->mapinfo.bounds.z_min = v->z;
	if (v->z > fdf->mapinfo.bounds.z_max)
		fdf->mapinfo.bounds.z_max = v->z;
}

t_mat4	center_map_mat4(t_fdf *fdf)
{
	double	sum_x;
	double	sum_y;
	t_mat4	new;
	t_vec3	v;
	int		i;

	sum_x = 0.0;
	sum_y = 0.0;
	i = 0;
	while (i < fdf->mapinfo.nb)
	{
		sum_x += fdf->map_pts[i].x;
		sum_y += fdf->map_pts[i].y;
		rec_bounds(fdf, (t_vec3 *)&fdf->map_pts[i]);
		i++;
	}
	new = create_identity_mat4();
	v.x = -sum_x / fdf->mapinfo.nb;
	v.y = -sum_y / fdf->mapinfo.nb;
	v.z = 0.0;
	translate_mat4(&new, v);
	return (new);
}
