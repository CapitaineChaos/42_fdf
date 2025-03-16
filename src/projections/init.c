/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:30:58 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 01:26:44 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_pan_zoom(t_fdf *fdf)
{
	fdf->cur_proj->camera.pan_x = 0.0;
	fdf->cur_proj->camera.pan_y = 0.0;
	fdf->cur_proj->camera.zoom = 1.0;
}

void	init_transform(t_proj *p)
{
	init_identity_mat4(&p->pipe.total);
	init_identity_quaternion(&p->transform.rot_model);
	init_identity_quaternion(&p->transform.rot_model_local);
	init_identity_mat4(&p->transform.trs_model);
	init_identity_mat4(&p->transform.trs_model_local);
}
