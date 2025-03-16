/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:21:22 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:01:36 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat4	camera(t_fdf *fdf, t_pipe *p, t_mat4 view, t_bool a)
{
	t_proj	*proj;

	proj = fdf->cur_proj;
	p->dist = create_identity_mat4();
	p->dist.m[2][3] = -proj->camera.distance;
	p->view = mat4_mul(p->dist, view);
	p->proj = mat4_mul(proj->mat, p->view);
	if (a == 1)
	{
		proj->transform.adjustment = compute_autoview_mat4(fdf, p->proj);
	}
	p->adjust = mat4_mul(proj->transform.adjustment, p->proj);
	p->zoom = create_zoom_mat4(proj->camera.zoom);
	p->pan = create_translate_mat4(proj->camera.pan_x, proj->camera.pan_y);
	p->cam = mat4_mul(p->pan, p->zoom);
	return (mat4_mul(p->cam, p->adjust));
}

/**
 * 
 * M_total = Cnv x Vp x Cam x (Rg x Tg × ( (Tl × Tc) × Rl × (Tc⁻¹ × Tl⁻¹) ))
 * 
 */
void	compute_total_transform(t_fdf *fdf, t_pipe *p, t_trsfm *t, int a)
{
	init_identity_mat4(&p->total);
	p->t_cntr_n = fdf->mapinfo.center;
	p->t_cntr_i = invert_mat4_(p->t_cntr_n);
	p->r_local = quat_to_mat4(t->rot_model_local);
	p->r_centered = mat4_mul(p->t_cntr_i, mat4_mul(p->r_local, p->t_cntr_n));
	init_identity_mat4(&p->t_local);
	translate_mat4(&p->t_local, trans_mat4_to_vec3(t->trs_model_local));
	p->l_part = mat4_mul(p->r_centered, p->t_local);
	p->t_global = t->trs_model;
	p->total = mat4_mul(p->t_global, p->l_part);
	p->r_global = quat_to_mat4(t->rot_model);
	p->total = mat4_mul(p->r_global, p->total);
	p->m_scale = create_scale_mat4(fdf->cur_proj->scale);
	p->total = mat4_mul(p->total, p->m_scale);
	fdf->cur_proj->update_proj(fdf->cur_proj);
	p->total = camera(fdf, p, p->total, a);
	p->viewport = create_viewport_mat4(fdf->win.width, fdf->win.height, 1);
	p->total = mat4_mul(p->viewport, p->total);
	p->canvas2d = create_canvas_mat4(fdf, fdf->cur_proj->canvas);
	p->total = mat4_mul(p->canvas2d, p->total);
}
