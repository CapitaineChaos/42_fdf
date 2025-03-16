/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:59:09 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:57:22 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_lineparams(t_line *line, t_prmline *p)
{
	p->dx = abs(line->pt_1.x - line->pt_0.x);
	p->dy = abs(line->pt_1.y - line->pt_0.y);
	p->sx = -1;
	if (line->pt_0.x < line->pt_1.x)
		p->sx = 1;
	p->sy = -1;
	if (line->pt_0.y < line->pt_1.y)
		p->sy = 1;
	p->err = p->dx - p->dy;
	p->max = p->dy;
	if (p->dx > p->dy)
		p->max = p->dx;
	p->x = line->pt_0.x;
	p->y = line->pt_0.y;
}

static void	set_err(t_prmline *p)
{
	p->e2 = 2 * p->err;
	if (p->e2 > -p->dy)
	{
		p->err -= p->dy;
		p->x += p->sx;
	}
	if (p->e2 < p->dx)
	{
		p->err += p->dx;
		p->y += p->sy;
	}
}

static int	get_tcolor(t_fdf *fdf, t_line *line, double t)
{
	int			color;
	float		z;
	float		ratio;
	t_mapinfo	*mapi;

	mapi = &fdf->mapinfo;
	z = line->pt_0.z + t * (line->pt_1.z - line->pt_0.z);
	if (mapi->c_mode == C_AUTO)
		color = interpolate_colors(line->gcolor0, line->gcolor1, t);
	else
	{
		if (z == 0)
			color = mapi->gcolor_z;
		else if (z > 0)
		{
			ratio = z / fabs(mapi->bounds.z_max);
			color = interpolate_colors(mapi->gcolor_z, mapi->gcolor_u, ratio);
		}
		else
		{
			ratio = (-z) / fabs(mapi->bounds.z_min);
			color = interpolate_colors(mapi->gcolor_z, mapi->gcolor_l, ratio);
		}
	}
	return (color);
}

void	bressenham_path(t_fdf *c, t_line *line, t_bool use_gradient)
{
	t_prmline	p;
	double		t;
	int			i;
	char		*dst;

	set_lineparams(line, &p);
	i = 0;
	t = 0.0;
	while (t <= 1.0)
	{
		dst = c->img.dat + (p.y * c->img.size_line + p.x * (c->img.bpp / 8));
		if (use_gradient)
			*(unsigned int *)dst = get_tcolor(c, line, t);
		else
			*(unsigned int *)dst = line->gcolor0;
		set_err(&p);
		i++;
		t = (double)i / (double)p.max;
	}
}
