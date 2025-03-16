/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:20:54 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 15:17:49 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	interpolate_colors(int c0, int c1, double t)
{
	int	rgb[3];
	int	rgb0[3];
	int	rgb1[3];

	if (t < 0)
		t = 0;
	else if (t > 1)
		t = 1;
	rgb0[0] = (c0 >> 16) & 0xFF;
	rgb0[1] = (c0 >> 8) & 0xFF;
	rgb0[2] = c0 & 0xFF;
	rgb1[0] = (c1 >> 16) & 0xFF;
	rgb1[1] = (c1 >> 8) & 0xFF;
	rgb1[2] = c1 & 0xFF;
	rgb[0] = (int)(rgb0[0] + t * (rgb1[0] - rgb0[0]));
	rgb[1] = (int)(rgb0[1] + t * (rgb1[1] - rgb0[1]));
	rgb[2] = (int)(rgb0[2] + t * (rgb1[2] - rgb0[2]));
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

static void	set_values(double a, double b, double c, double *rgb_)
{
	rgb_[0] = a;
	rgb_[1] = b;
	rgb_[2] = c;
}

static void	set_rgb_values(double hue, double *rgb_)
{
	double	cx[2];

	cx[0] = 1.0;
	cx[1] = cx[0] * (1.0 - fabs(fmod(hue / 60.0, 2.0) - 1.0));
	if (hue < 60.0)
		set_values(cx[0], cx[1], 0.0, rgb_);
	else if (hue < 120.0)
		set_values(cx[1], cx[0], 0.0, rgb_);
	else if (hue < 180.0)
		set_values(0.0, cx[0], cx[1], rgb_);
	else if (hue < 240.0)
		set_values(0.0, cx[1], cx[0], rgb_);
	else if (hue < 300.0)
		set_values(cx[1], 0.0, cx[0], rgb_);
	else
		set_values(cx[0], 0.0, cx[1], rgb_);
}

int	random_bright_color(t_fdf *fdf)
{
	double	hue;
	double	rgb_[3];
	double	cx[2];
	int		rgb[3];

	hue = fdf->mapinfo.seed * 360.0;
	cx[0] = 1.0;
	cx[1] = cx[0] * (1.0 - fabs(fmod(hue / 60.0, 2.0) - 1.0));
	set_rgb_values(hue, rgb_);
	rgb[0] = (int)(rgb_[0] * 255);
	rgb[1] = (int)(rgb_[1] * 255);
	rgb[2] = (int)(rgb_[2] * 255);
	fdf->mapinfo.seed = fmodf(fdf->mapinfo.seed + 0.61803398875f, 1.0f);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
