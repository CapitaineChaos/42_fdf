/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:57:37 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 22:24:53 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_rotate_x(t_fdf *fdf, float delta)
{
	t_quat	*rot_m;

	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		rot_m = &fdf->cur_proj->transform.rot_model;
		fdf->cur_proj->transform.rot_model_euler.x += delta;
		acc_rot_global(rot_m, (t_vec3){1.0, 0.0, 0.0}, delta);
	}
	else
	{
		rot_m = &fdf->cur_proj->transform.rot_model_local;
		fdf->cur_proj->transform.rot_model_local_euler.x += delta;
		acc_rot_local(rot_m, (t_vec3){1.0, 0.0, 0.0}, delta);
	}
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_rotate_y(t_fdf *fdf, float delta)
{
	t_quat	*rot_m;

	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		rot_m = &fdf->cur_proj->transform.rot_model;
		fdf->cur_proj->transform.rot_model_euler.y += delta;
		acc_rot_global(rot_m, (t_vec3){0.0, 1.0, 0.0}, delta);
	}
	else
	{
		rot_m = &fdf->cur_proj->transform.rot_model_local;
		fdf->cur_proj->transform.rot_model_local_euler.y += delta;
		acc_rot_local(rot_m, (t_vec3){0.0, 1.0, 0.0}, delta);
	}
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_rotate_z(t_fdf *fdf, float delta)
{
	t_quat	*rot_m;

	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		rot_m = &fdf->cur_proj->transform.rot_model;
		fdf->cur_proj->transform.rot_model_euler.z += delta;
		acc_rot_global(rot_m, (t_vec3){0.0, 0.0, 1.0}, delta);
	}
	else
	{
		rot_m = &fdf->cur_proj->transform.rot_model_local;
		fdf->cur_proj->transform.rot_model_local_euler.z += delta;
		acc_rot_local(rot_m, (t_vec3){0.0, 0.0, 1.0}, delta);
	}
	fdf->state = REDRAW_FULL_NO_AUTO;
}
