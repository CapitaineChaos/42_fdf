/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:35:23 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 15:05:09 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_visual_commands(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	mlx_string_put(mlx, win, x, y, 0xFFFFFF,
		"Rotation     : ");
	mlx_string_put(mlx, win, x + 100, y, 0xAA99CC,
		"X (2 | 8)   Y (7 | 9)   Z (4 | 6)");
	mlx_string_put(mlx, win, x, y + 20, 0xFFFFFF,
		"Translation  : ");
	mlx_string_put(mlx, win, x + 100, y + 20, 0xAA99CC,
		"XY (Arrows), Z (5 | 0)");
	mlx_string_put(mlx, win, x, y + 40, 0xFFFFFF,
		"Scale        : ");
	mlx_string_put(mlx, win, x + 100, y + 40, 0xAA99CC,
		"Z (1 | 3)");
	mlx_string_put(mlx, win, x, y + 60, 0xFFFFFF,
		"Cmds         : ");
	mlx_string_put(mlx, win, x + 100, y + 60, 0xAA99CC,
		"Quit (ESC)");
}

static void	draw_view_commands(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	mlx_string_put(mlx, win, x, y, 0x888888, "View :");
	if (fdf->mapinfo.v_mode == V_ISOMETRIC)
	{
		draw_triangle_right(fdf, 10, (t_pt2){x, y + 10}, 0xFFFF00);
		mlx_string_put(mlx, win, x + 15, y + 20, 0x33FF33, "(I)sometric");
	}
	else
		mlx_string_put(mlx, win, x + 15, y + 20, 0xFFFFFF, "(I)sometric");
	if (fdf->mapinfo.v_mode == V_CONIC)
	{
		draw_triangle_right(fdf, 10, (t_pt2){x, y + 30}, 0xFFFF00);
		mlx_string_put(mlx, win, x + 15, y + 40, 0x33FF33, "(C)onic");
	}
	else
		mlx_string_put(mlx, win, x + 15, y + 40, 0xFFFFFF, "(C)onic");
}

static void	draw_modes_commands(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	mlx_string_put(mlx, win, x, y, 0x888888, "Mode :");
	if (fdf->mapinfo.r_mode == M_OBJECT)
	{
		draw_triangle_right(fdf, 10, (t_pt2){x, y + 10}, 0xFFFF00);
		mlx_string_put(mlx, win, x + 15, y + 20, 0x33FF33, "(O)bject");
	}
	else
		mlx_string_put(mlx, win, x + 15, y + 20, 0xFFFFFF, "(O)bject");
	if (fdf->mapinfo.r_mode == M_SCENE)
	{
		draw_triangle_right(fdf, 10, (t_pt2){x, y + 30}, 0xFFFF00);
		mlx_string_put(mlx, win, x + 15, y + 40, 0x33FF33, "(S)cene");
	}
	else
		mlx_string_put(mlx, win, x + 15, y + 40, 0xFFFFFF, "(S)cene");
}

static void	draw_color_commands(t_fdf *fdf, void *m, void *w, int *c)
{
	mlx_string_put(m, w, c[0], c[1], 0x888888, "Colors :");
	if (fdf->mapinfo.c_mode == C_RANDOM)
	{
		draw_triangle_right(fdf, 10, (t_pt2){c[0], c[1] + 10}, 0xFFFF00);
		mlx_string_put(m, w, c[0] + 15, c[1] + 20, 0x33FF33, "ra(N)dom");
	}
	else
		mlx_string_put(m, w, c[0] + 15, c[1] + 20, 0xFFFFFF, "ra(N)dom");
	if (fdf->mapinfo.c_mode == C_AUTO)
	{
		draw_triangle_right(fdf, 10, (t_pt2){c[0], c[1] + 30}, 0xFFFF00);
		mlx_string_put(m, w, c[0] + 15, c[1] + 40, 0x33FF33, "(A)utomatic");
	}
	else
		mlx_string_put(m, w, c[0] + 15, c[1] + 40, 0xFFFFFF, "(A)utomatic");
	if (fdf->mapinfo.c_mode == C_LAPINOU)
	{
		draw_triangle_right(fdf, 10, (t_pt2){c[0], c[1] + 50}, 0xFFFF00);
		mlx_string_put(m, w, c[0] + 15, c[1] + 60, 0x33FF33, "(L)apinou42");
	}
	else
		mlx_string_put(m, w, c[0] + 15, c[1] + 60, 0xFFFFFF, "(L)apinou42");
}

void	show_infos_top(t_fdf *fdf)
{
	draw_view_commands(fdf, 20, 20);
	draw_modes_commands(fdf, 140, 20);
	draw_color_commands(fdf, fdf->win.mlx, fdf->win.win, (int [2]){260, 20});
	draw_visual_commands(fdf, fdf->win.width - 320, 20);
}
