/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:43:24 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:53:55 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_iso_proj(t_proj *p)
{
	p->mat.m[0][0] = 1.0;
	p->mat.m[0][1] = 0.0;
	p->mat.m[0][2] = 0.0;
	p->mat.m[0][3] = 0.0;
	p->mat.m[1][0] = 0.0;
	p->mat.m[1][1] = 1.0;
	p->mat.m[1][2] = 0.0;
	p->mat.m[1][3] = 0.0;
	p->mat.m[2][0] = 0.0;
	p->mat.m[2][1] = 0.0;
	p->mat.m[2][2] = 1.0 / (p->far - p->near);
	p->mat.m[2][3] = 0.0;
	p->mat.m[3][0] = 0.0;
	p->mat.m[3][1] = 0.0;
	p->mat.m[3][2] = 0.0;
	p->mat.m[3][3] = 1.0;
}

void	reset_iso_proj(t_fdf *fdf, t_proj *p)
{
	t_quat	*q;

	(void)fdf;
	p->scale.x = 1.0;
	p->scale.y = 1.0;
	p->scale.z = 0.1;
	p->fov = 1.0f;
	p->near = compute_diag(fdf) / 10.0;
	p->far = compute_diag(fdf) * 3.0;
	p->camera.distance = compute_diag(fdf) * 0.05;
	p->camera.pan_x = 0.0;
	p->camera.pan_y = 0.0;
	p->camera.zoom = 1.0;
	p->transform.rot_model_euler = (t_vec3){0.0, 0.0, 0.0};
	p->transform.rot_model_local_euler = (t_vec3){0.0, 0.0, 0.0};
	p->transform.rot_camera_euler = (t_vec3){0.0, 0.0, 0.0};
	p->transform.rot_camera_local_euler = (t_vec3){0.0, 0.0, 0.0};
	p->transform.rot_model_local_euler.x = 35.264 * M_PI / 180.0;
	p->transform.rot_model_local_euler.z = 45.0 * M_PI / 180.0;
	q = &p->transform.rot_model_local;
	acc_rot_local(q, (t_vec3){1.0, 0.0, 0.0}, 35.264 * M_PI / 180.0);
	acc_rot_local(q, (t_vec3){0.0, 1.0, 0.0}, 0.0 * M_PI / 180.0);
	acc_rot_local(q, (t_vec3){0.0, 0.0, 1.0}, 45.0 * M_PI / 180.0);
}

t_proj	init_iso_view(t_fdf *fdf)
{
	t_proj	iso;

	init_transform(&iso);
	iso.canvas.offset_x = 0.0;
	iso.canvas.offset_y = 0.0;
	iso.canvas.zoom = 1.0;
	reset_iso_proj(fdf, &iso);
	iso.update_proj = &update_iso_proj;
	return (iso);
}
