/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keybd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:01:40 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:33:23 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_modes(int keycode, t_fdf *fdf)
{
	if (keycode == M_OBJECT)
		do_define_rotation_mode(fdf, keycode);
	else if (keycode == M_SCENE)
		do_define_rotation_mode(fdf, keycode);
	else if (keycode == V_CONIC)
		do_define_view_mode(fdf, keycode);
	else if (keycode == V_ISOMETRIC)
		do_define_view_mode(fdf, keycode);
	else if (keycode == V_EYEFISH)
		do_define_view_mode(fdf, keycode);
	else if (keycode == SCL_DOWN)
		do_scale_z(fdf, -0.025);
	else if (keycode == SCL_UP)
		do_scale_z(fdf, 0.025);
}

void	hook_translate(int keycode, t_fdf *fdf)
{
	float	delta;

	delta = 0.025;
	if (keycode == TRS_XL)
		do_translate_x(fdf, -delta);
	else if (keycode == TRS_XR)
		do_translate_x(fdf, delta);
	else if (keycode == TRS_YL)
		do_translate_y(fdf, -delta);
	else if (keycode == TRS_YR)
		do_translate_y(fdf, delta);
	else if (keycode == TRS_ZL)
		do_translate_z(fdf, delta);
	else if (keycode == TRS_ZR)
		do_translate_z(fdf, -delta);
}

void	hook_rotate(int keycode, t_fdf *fdf)
{
	float	delta;

	delta = M_PI / 100;
	if (keycode == ROT_XL || keycode == 0x32)
		do_rotate_x(fdf, -delta);
	else if (keycode == ROT_XR || keycode == 0x38)
		do_rotate_x(fdf, delta);
	else if (keycode == ROT_YL || keycode == 0x37)
		do_rotate_y(fdf, delta);
	else if (keycode == ROT_YR || keycode == 0x39)
		do_rotate_y(fdf, -delta);
	else if (keycode == ROT_ZL || keycode == 0x34)
		do_rotate_z(fdf, -delta);
	else if (keycode == ROT_ZR || keycode == 0x36)
		do_rotate_z(fdf, delta);
}

void	hook_effects(int keycode, t_fdf *fdf)
{
	if (keycode == E_FOV_UP)
		do_change_fov(fdf, 0.1);
	else if (keycode == E_FOV_DOWN)
		do_change_fov(fdf, -0.1);
	else if (keycode == E_DISTANCE_UP)
		do_change_distance(fdf, 0.5);
	else if (keycode == E_DISTANCE_DOWN)
		do_change_distance(fdf, -0.5);
	else if (keycode == C_RANDOM
		|| keycode == C_AUTO
		|| keycode == C_LAPINOU)
		do_change_color(fdf, keycode);
	else if (keycode == C_RESETCANVAS)
		do_reset_canvas(fdf);
}

void	do_modif_keys(t_fdf *fdf, int keycode, t_bool press)
{
	if (keycode == M_LSHIFT)
		fdf->keyb.l_shift = press;
	else if (keycode == M_RSHIFT)
		fdf->keyb.r_shift = press;
	else if (keycode == M_LCTRL)
		fdf->keyb.l_ctrl = press;
	else if (keycode == M_RCTRL)
		fdf->keyb.r_ctrl = press;
	else if (keycode == M_LALT)
		fdf->keyb.l_alt = press;
	else if (keycode == M_RALT)
		fdf->keyb.r_alt = press;
}
