/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hooks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:27:00 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 22:22:12 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main_hook_keypress(int keycode, t_fdf *fdf)
{
	hook_modes(keycode, fdf);
	hook_translate(keycode, fdf);
	hook_rotate(keycode, fdf);
	hook_effects(keycode, fdf);
	do_modif_keys(fdf, keycode, TRUE);
	if (keycode == XK_Escape)
		close_fdf(fdf);
	return (0);
}

int	main_hook_keyrelease(int keycode, t_fdf *fdf)
{
	do_modif_keys(fdf, keycode, FALSE);
	return (0);
}

int	main_hook_loop(t_fdf *fdf)
{
	fdf->frame_count++;
	if (fdf->frame_count % 10 == 0 && fdf->state != REDRAW_STOP)
	{
		global_render(fdf);
	}
	return (0);
}

int	main_hook_close(t_fdf *fdf)
{
	close_fdf(fdf);
	return (0);
}
