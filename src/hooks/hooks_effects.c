/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:04:32 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:01:18 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_change_fov(t_fdf *fdf, float delta)
{
	fdf->cur_proj->fov += delta;
	fdf->state = REDRAW_FULL_NO_AUTO;
	if (fdf->cur_proj->fov + delta > 0.2)
	{
		if (fdf->cur_proj->fov + delta < M_PI - 0.2)
		{
			fdf->cur_proj->fov += delta;
			fdf->state = REDRAW_FULL_NO_AUTO;
		}
	}
}

void	do_change_distance(t_fdf *fdf, float delta)
{
	if (fdf->mapinfo.v_mode == V_ISOMETRIC)
		return ;
	else if (fdf->cur_proj->camera.distance + delta > 0.1)
	{
		fdf->cur_proj->camera.distance += delta;
		fdf->state = REDRAW_FULL_NO_AUTO;
	}
}

void	create_new_colors(t_fdf *fdf)
{
	fdf->mapinfo.gcolor_l = random_bright_color(fdf);
	fdf->mapinfo.gcolor_z = random_bright_color(fdf);
	fdf->mapinfo.gcolor_u = random_bright_color(fdf);
}

void	do_change_color(t_fdf *fdf, int keycode)
{
	if (keycode == C_RANDOM)
	{
		create_new_colors(fdf);
		fdf->mapinfo.c_mode = C_RANDOM;
	}
	else if (keycode == C_AUTO)
	{
		if (fdf->mapinfo.c_mode == C_AUTO)
			return ;
		fdf->mapinfo.c_mode = C_AUTO;
	}
	else if (keycode == C_LAPINOU)
	{
		if (fdf->mapinfo.c_mode == C_LAPINOU)
			return ;
		fdf->mapinfo.gcolor_l = 0x33DDFF;
		fdf->mapinfo.gcolor_z = 0x005500;
		fdf->mapinfo.gcolor_u = 0xFFFF11;
		fdf->mapinfo.c_mode = C_LAPINOU;
	}
	if (fdf->state == REDRAW_STOP)
		fdf->state = REDRAW_VIEW_ONLY;
}
