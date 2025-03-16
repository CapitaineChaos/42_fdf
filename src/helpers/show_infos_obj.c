/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_infos_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:31:27 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 16:39:32 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_angles_scene(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;
	t_quat	*rot;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	rot = &fdf->cur_proj->transform.rot_model;
	mlx_string_put(mlx, win, x, y, 0x888888, "Scene angles");
	y = y + 15;
	mlx_string_put(mlx, win, x, y, 0x888888, "X");
	angle_to_str(fdf, rot->x, x + 30, y);
	mlx_string_put(mlx, win, x, y + 15, 0x888888, "Y");
	angle_to_str(fdf, rot->y, x + 30, y + 15);
	mlx_string_put(mlx, win, x, y + 30, 0x888888, "Z");
	angle_to_str(fdf, rot->z, x + 30, y + 30);
}

void	show_angles_object(t_fdf *fdf, int x, int y)
{
	double	roll;
	double	pitch;
	double	yaw;
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	roll = fdf->cur_proj->transform.rot_model_local_euler.x;
	pitch = fdf->cur_proj->transform.rot_model_local_euler.y;
	yaw = fdf->cur_proj->transform.rot_model_local_euler.z;
	mlx_string_put(mlx, win, x, y, 0x888888, "Object angles");
	y = y + 15;
	mlx_string_put(mlx, win, x, y, 0x888888, "X");
	angle_to_str(fdf, roll, x + 30, y);
	mlx_string_put(mlx, win, x, y + 15, 0x888888, "Y");
	angle_to_str(fdf, pitch, x + 30, y + 15);
	mlx_string_put(mlx, win, x, y + 30, 0x888888, "Z");
	angle_to_str(fdf, yaw, x + 30, y + 30);
}

void	show_pos_object(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;
	t_mat4	*trs;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	trs = &fdf->cur_proj->transform.trs_model_local;
	mlx_string_put(mlx, win, x, y, 0x888888, "Object pos");
	y = y + 15;
	mlx_string_put(mlx, win, x, y, 0x888888, "X");
	float_to_str(fdf, trs->m[0][3], (int [2]){x + 30, y}, 2);
	mlx_string_put(mlx, win, x, y + 15, 0x888888, "Y");
	float_to_str(fdf, trs->m[1][3], (int [2]){x + 30, y + 15}, 2);
	mlx_string_put(mlx, win, x, y + 30, 0x888888, "Z");
	float_to_str(fdf, trs->m[2][3], (int [2]){x + 30, y + 30}, 2);
}

void	show_pos_scene(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;
	t_mat4	*trs;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	trs = &fdf->cur_proj->transform.trs_model;
	mlx_string_put(mlx, win, x, y, 0x888888, "Scene pos");
	y = y + 15;
	mlx_string_put(mlx, win, x, y, 0x888888, "X");
	float_to_str(fdf, trs->m[0][3], (int [2]){x + 30, y}, 2);
	mlx_string_put(mlx, win, x, y + 15, 0x888888, "Y");
	float_to_str(fdf, trs->m[1][3], (int [2]){x + 30, y + 15}, 2);
	mlx_string_put(mlx, win, x, y + 30, 0x888888, "Z");
	float_to_str(fdf, trs->m[2][3], (int [2]){x + 30, y + 30}, 2);
}

void	show_obj_scale(t_fdf *fdf, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->win.mlx;
	win = fdf->win.win;
	mlx_string_put(mlx, win, x, y, 0x888888, "Obj scale");
	y = y + 15;
	mlx_string_put(mlx, win, x, y, 0x888888, "X");
	float_to_str(fdf, fdf->cur_proj->scale.x, (int [2]){x + 30, y}, 2);
	mlx_string_put(mlx, win, x, y + 15, 0x888888, "Y");
	float_to_str(fdf, fdf->cur_proj->scale.y, (int [2]){x + 30, y + 15}, 2);
	mlx_string_put(mlx, win, x, y + 30, 0x888888, "Z");
	float_to_str(fdf, 1 * fdf->cur_proj->scale.z, (int [2]){x + 30, y + 30}, 2);
}
