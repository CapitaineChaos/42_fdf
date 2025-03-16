/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:03:51 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:25:19 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_keyb(t_keyb *keyb)
{
	keyb->l_alt = FALSE;
	keyb->r_alt = FALSE;
	keyb->l_ctrl = FALSE;
	keyb->r_ctrl = FALSE;
	keyb->l_shift = FALSE;
	keyb->r_shift = FALSE;
}

static void	init_graphics(t_fdf *fdf)
{
	fdf->mapinfo.nb_x = -1;
	fdf->mapinfo.nb_y = -1;
	fdf->mapinfo.nb = 0;
	fdf->win.width = 0;
	fdf->win.height = 0;
	if (WIDTH > 300 && HEIGHT > 300)
	{
		fdf->win.height = HEIGHT;
		fdf->win.width = WIDTH;
	}
	fdf->frame_count = 0;
}

void	init_bounds(t_fdf *fdf)
{
	fdf->mapinfo.bounds.x_min = 0.0;
	fdf->mapinfo.bounds.x_max = 0.0;
	fdf->mapinfo.bounds.y_min = 0.0;
	fdf->mapinfo.bounds.y_max = 0.0;
	fdf->mapinfo.bounds.z_min = 0.0;
	fdf->mapinfo.bounds.z_max = 0.0;
}

void	init_ptrs(t_fdf *fdf)
{
	fdf->win.mlx = NULL;
	fdf->win.win = NULL;
	fdf->img.ptr = NULL;
	fdf->img.dat = NULL;
	fdf->map_pts = NULL;
	fdf->map_colors = NULL;
	fdf->map_raw = NULL;
	fdf->map_view = NULL;
	fdf->last_raw_elem = NULL;
	fdf->cur_proj = NULL;
}

void	init_fdf(t_fdf *fdf)
{
	init_ptrs(fdf);
	fdf->state = TRUE;
	fdf->mapinfo.gcolor_l = 0xFFFFFF;
	fdf->mapinfo.gcolor_z = 0xFFFFFF;
	fdf->mapinfo.gcolor_u = 0xFFFFFF;
	fdf->mouse.x = 0;
	fdf->mouse.y = 0;
	fdf->mouse.prev_x = 0;
	fdf->mouse.prev_y = 0;
	fdf->mouse.button = 0;
	fdf->mouse.prev_button = 0;
	init_keyb(&fdf->keyb);
	init_graphics(fdf);
	init_bounds(fdf);
}
