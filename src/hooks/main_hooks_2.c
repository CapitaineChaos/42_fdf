/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hooks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:26:49 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:57:45 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main_hook_mouserelease(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 1)
		fdf->mouse.button = 0;
	return (0);
}

int	main_hook_mousemove(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse.button == 1)
	{
		if (x > fdf->win.width || x < 0 || y > fdf->win.height || y < 0)
		{
			fdf->mouse.button = 0;
			return (0);
		}
		do_translate_view(fdf, x - fdf->mouse.prev_x, y - fdf->mouse.prev_y);
		fdf->mouse.prev_x = x;
		fdf->mouse.prev_y = y;
	}
	return (0);
}

int	main_hook_mouseclick(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1)
	{
		fdf->mouse.prev_x = x;
		fdf->mouse.prev_y = y;
		fdf->mouse.button = 1;
	}
	else if (button == 4)
		do_scale_view(fdf, 1.0 / 0.9, x, y);
	else if (button == 5)
		do_scale_view(fdf, 0.9, x, y);
	return (0);
}
