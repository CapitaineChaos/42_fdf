/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:48:51 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 22:25:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_define_rotation_mode(t_fdf *fdf, int keycode)
{
	if (keycode == M_SCENE)
	{
		if (fdf->mapinfo.r_mode == M_SCENE)
			return ;
		fdf->mapinfo.r_mode = M_SCENE;
	}
	else if (keycode == M_OBJECT)
	{
		if (fdf->mapinfo.r_mode == M_OBJECT)
			return ;
		fdf->mapinfo.r_mode = M_OBJECT;
	}
	if (fdf->state == REDRAW_STOP)
		fdf->state = REDRAW_VIEW_ONLY;
}

void	do_define_view_mode(t_fdf *fdf, int keycode)
{
	if (keycode == V_ISOMETRIC)
	{
		fdf->cur_proj = &fdf->projs[0];
		fdf->mapinfo.v_mode = V_ISOMETRIC;
	}
	else if (keycode == V_CONIC)
	{
		fdf->cur_proj = &fdf->projs[1];
		fdf->mapinfo.v_mode = V_CONIC;
	}
	else if (keycode == V_EYEFISH)
	{
		fdf->cur_proj = &fdf->projs[2];
		fdf->mapinfo.v_mode = V_EYEFISH;
	}
	reset_pan_zoom(fdf);
	fdf->state = REDRAW_FULL_AUTO;
}
