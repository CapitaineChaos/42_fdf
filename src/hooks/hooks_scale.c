/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:55:48 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 22:24:45 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_scale_z(t_fdf *fdf, float delta)
{
	fdf->cur_proj->scale.z += delta;
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_scale_view(t_fdf *fdf, float delta, int x, int y)
{
	(void)x;
	(void)y;
	fdf->cur_proj->canvas.zoom *= delta;
	fdf->state = REDRAW_FULL_NO_AUTO;
}

void	do_reset_canvas(t_fdf *fdf)
{
	fdf->cur_proj->canvas.offset_x = 0.0;
	fdf->cur_proj->canvas.offset_y = 0.0;
	fdf->cur_proj->canvas.zoom = 1.0;
	fdf->state = REDRAW_FULL_AUTO;
}
