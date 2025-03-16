/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:56:06 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 15:16:46 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	redefine_line(t_line *l, float u1, float u2)
{
	t_pt3i	orig_pt0;
	t_pt3i	orig_pt1;

	orig_pt0 = l->pt_0;
	orig_pt1 = l->pt_1;
	l->pt_0.x = orig_pt0.x + u1 * (orig_pt1.x - orig_pt0.x);
	l->pt_0.y = orig_pt0.y + u1 * (orig_pt1.y - orig_pt0.y);
	l->pt_1.x = orig_pt0.x + u2 * (orig_pt1.x - orig_pt0.x);
	l->pt_1.y = orig_pt0.y + u2 * (orig_pt1.y - orig_pt0.y);
}

static void	detect_edge(t_line *l, t_fdf *fdf, float *pq, int edge)
{
	if (edge == 0)
	{
		pq[0] = -((float)l->pt_1.x - (float)l->pt_0.x);
		pq[1] = (float)l->pt_0.x - 0.0f;
	}
	else if (edge == 1)
	{
		pq[0] = ((float)l->pt_1.x - (float)l->pt_0.x);
		pq[1] = (float)(fdf->win.width - 1) - (float)l->pt_0.x;
	}
	else if (edge == 2)
	{
		pq[0] = -((float)l->pt_1.y - (float)l->pt_0.y);
		pq[1] = (float)l->pt_0.y - 0.0f;
	}
	else
	{
		pq[0] = ((float)l->pt_1.y - (float)l->pt_0.y);
		pq[1] = (float)(fdf->win.height - 1) - (float)l->pt_0.y;
	}
}

static int	detect_line_pos(float *pq, float *u1, float *u2)
{
	float	r;
	float	p;
	float	q;

	p = pq[0];
	q = pq[1];
	if (p < 0)
	{
		r = q / p;
		if (r > *u2)
			return (0);
		else if (r > *u1)
			*u1 = r;
	}
	else if (p > 0)
	{
		r = q / p;
		if (r < *u1)
			return (0);
		else if (r < *u2)
			*u2 = r;
	}
	else if (q < 0)
		return (0);
	return (1);
}

int	liang_barsky_clip(t_line *line, t_fdf *fdf, float u1, float u2)
{
	float	pq[2];
	int		edge;
	int		pos;

	edge = 0;
	while (edge < 4)
	{
		detect_edge(line, fdf, pq, edge);
		pos = detect_line_pos(pq, &u1, &u2);
		if (!pos)
			return (0);
		edge++;
	}
	if (u2 < u1)
		return (0);
	redefine_line(line, u1, u2);
	return (1);
}
