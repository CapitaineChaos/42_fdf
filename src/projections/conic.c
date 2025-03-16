/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:42:21 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 21:51:58 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_fov(t_proj *p)
{
	if (p->fov < 0.1)
		p->fov = 0.1;
	if (p->fov > M_PI - 0.1)
		p->fov = M_PI - 0.1;
}

void	update_conic_proj(t_proj *p)
{
	double	tan_half_fov;

	adjust_fov(p);
	tan_half_fov = tan(p->fov / 2.0);
	p->mat.m[0][0] = 1.0 / ((p->scale.x / p->scale.y) * tan_half_fov);
	p->mat.m[0][1] = 0.0;
	p->mat.m[0][2] = 0.0;
	p->mat.m[0][3] = 0.0;
	p->mat.m[1][0] = 0.0;
	p->mat.m[1][1] = 1.0 / tan_half_fov;
	p->mat.m[1][2] = 0.0;
	p->mat.m[1][3] = 0.0;
	p->mat.m[2][0] = 0.0;
	p->mat.m[2][1] = 0.0;
	p->mat.m[2][2] = -(p->far + p->near) / (p->far - p->near);
	p->mat.m[2][3] = -(2.0 * p->far * p->near) / (p->far - p->near);
	p->mat.m[3][0] = 0.0;
	p->mat.m[3][1] = 0.0;
	p->mat.m[3][2] = -1.0;
	p->mat.m[3][3] = 0.0;
}

void	reset_conic_proj(t_fdf *fdf, t_proj *p)
{
	t_quat	*q;

	p->camera.pan_x = 0.0;
	p->camera.pan_y = 0.0;
	p->camera.zoom = 1.0;
	p->camera.distance = compute_diag(fdf) * 1.5;
	p->scale.x = 1.0;
	p->scale.y = 1.0;
	p->scale.z = 0.1;
	p->fov = M_PI / 3.0;
	p->near = compute_diag(fdf) / 10.0;
	p->far = compute_diag(fdf) * 3.0;
	p->transform.rot_model_euler = (t_vec3){0.0, 0.0, 0.0};
	p->transform.rot_model_local_euler = (t_vec3){1.0, 0.15, 0.85};
	p->transform.rot_camera_euler = (t_vec3){0.0, 0.0, 0.0};
	p->transform.rot_camera_local_euler = (t_vec3){0.0, 0.0, 0.0};
	q = &p->transform.rot_model_local;
	acc_rot_local(q, (t_vec3){1.0, 0.0, 0.0}, 1.0);
	acc_rot_local(q, (t_vec3){0.0, 1.0, 0.0}, 0.15);
	acc_rot_local(q, (t_vec3){0.0, 0.0, 1.0}, 0.85);
}

t_proj	init_conic_view(t_fdf *fdf)
{
	t_proj	conic;

	init_transform(&conic);
	conic.canvas.offset_x = 0.0;
	conic.canvas.offset_y = 0.0;
	conic.canvas.zoom = 1.0;
	reset_conic_proj(fdf, &conic);
	conic.update_proj = &update_conic_proj;
	conic.reset_proj = &reset_conic_proj;
	init_identity_mat4(&conic.mat);
	return (conic);
}
