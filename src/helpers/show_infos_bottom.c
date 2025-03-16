/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_infos_bottom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:55:47 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 16:40:59 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_ffects_commands(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	mlx_string_put(mlx, win, x, y + 60, 0xFFFFFF, "Distance    :");
	mlx_string_put(mlx, win, x + 100, y + 60, 0xAA99CC, "(T | R)");
	float_to_str(fdf, fdf->cur_proj->camera.distance, (int [2]){x, y + 80}, 2);
	mlx_string_put(mlx, win, x, y, 0xFFFFFF, "Fov       :");
	mlx_string_put(mlx, win, x + 100, y, 0xAA99CC, "(F | G)");
	float_to_str(fdf, fdf->cur_proj->fov, (int [2]){x, y + 20}, 2);
}

static void	show_cam_dat(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	mlx_string_put(mlx, win, x, y, 0x888888, "View");
	y = y + 15;
	mlx_string_put(mlx, win, x, y, 0x888888, "pX");
	float_to_str(fdf, fdf->cur_proj->canvas.offset_x,
		(int [2]){x + 30, y}, 2);
	mlx_string_put(mlx, win, x, y + 15, 0x888888, "pY");
	float_to_str(fdf, fdf->cur_proj->canvas.offset_y,
		(int [2]){x + 30, y + 15}, 2);
	mlx_string_put(mlx, win, x, y + 30, 0x888888, "Zm");
	float_to_str(fdf, fdf->cur_proj->canvas.zoom,
		(int [2]){x + 30, y + 30}, 2);
}

void	show_infos_bottom(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 10;
	y = fdf->win.height - 120;
	show_angles_scene(fdf, x, y);
	show_angles_object(fdf, x, y + 70);
	show_pos_object(fdf, x + 90, y);
	show_pos_scene(fdf, x + 90, y + 70);
	show_obj_scale(fdf, x + 180, y);
	show_cam_dat(fdf, x + 180, y + 70);
	x = fdf->win.width - 250;
	if (fdf->mapinfo.v_mode == V_CONIC)
		draw_ffects_commands(fdf, x, y);
}
