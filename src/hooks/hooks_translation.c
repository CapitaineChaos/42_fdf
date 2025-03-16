/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:45:36 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:37:07 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_translate_x(t_fdf *fdf, float delta)
{
	t_vec3	v;
	t_mat4	*m;
	double	zoom_adj;
	double	zoom_cnv;

	zoom_adj = fdf->cur_proj->transform.adjustment.m[0][0];
	zoom_cnv = fdf->projs->canvas.zoom;
	delta = 0.1 * delta / (zoom_adj * zoom_cnv);
	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		v.x = delta * fdf->cur_proj->camera.distance;
		v.y = 0.0;
		v.z = 0.0;
		m = &fdf->cur_proj->transform.trs_model;
		translate_mat4(m, v);
	}
	else if (fdf->mapinfo.r_mode == M_OBJECT)
	{
		v.x = delta * fdf->cur_proj->camera.distance;
		v.y = 0.0;
		v.z = 0.0;
		m = &fdf->cur_proj->transform.trs_model_local;
		translate_mat4(m, v);
	}
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_translate_y(t_fdf *fdf, float delta)
{
	t_vec3	v;
	t_mat4	*m;
	double	zoom_adj;
	double	zoom_cnv;

	zoom_adj = fdf->cur_proj->transform.adjustment.m[0][0];
	zoom_cnv = fdf->projs->canvas.zoom;
	delta = 0.1 * delta / (zoom_adj * zoom_cnv);
	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		v.x = 0.0;
		v.y = delta * fdf->cur_proj->camera.distance;
		v.z = 0.0;
		m = &fdf->cur_proj->transform.trs_model;
		translate_mat4(m, v);
	}
	else if (fdf->mapinfo.r_mode == M_OBJECT)
	{
		v.x = 0.0;
		v.y = delta * fdf->cur_proj->camera.distance;
		v.z = 0.0;
		m = &fdf->cur_proj->transform.trs_model_local;
		translate_mat4(m, v);
	}
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_translate_z(t_fdf *fdf, float delta)
{
	t_vec3	v;
	t_mat4	*m;
	double	zoom_adj;
	double	zoom_cnv;

	zoom_adj = fdf->cur_proj->transform.adjustment.m[0][0];
	zoom_cnv = fdf->projs->canvas.zoom;
	delta = 0.1 * delta / (zoom_adj * zoom_cnv);
	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		v.x = 0.0;
		v.y = 0.0;
		v.z = delta * fdf->cur_proj->camera.distance;
		m = &fdf->cur_proj->transform.trs_model;
		translate_mat4(m, v);
	}
	else if (fdf->mapinfo.r_mode == M_OBJECT)
	{
		v.x = 0.0;
		v.y = 0.0;
		v.z = delta * fdf->cur_proj->camera.distance;
		m = &fdf->cur_proj->transform.trs_model_local;
		translate_mat4(m, v);
	}
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_translate_view(t_fdf *fdf, float delta_x, float delta_y)
{
	fdf->cur_proj->canvas.offset_x += delta_x;
	fdf->cur_proj->canvas.offset_y += delta_y;
	fdf->state = REDRAW_FULL_NO_AUTO;
}
