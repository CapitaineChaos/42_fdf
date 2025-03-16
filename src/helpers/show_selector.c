/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:57:40 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:57:22 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_triangle_right(t_fdf *fdf, int size, t_pt2 pos, int color)
{
	t_pt3i		p0;
	t_pt3i		p1;
	t_pt3i		p2;
	t_line		line;

	p0.x = pos.x;
	p0.y = pos.y;
	p0.z = 0;
	p1.x = pos.x;
	p1.y = pos.y + size;
	p1.z = 0;
	p2.x = pos.x + size / sqrt(2.0);
	p2.y = pos.y + size / 2;
	p2.z = 0;
	line.gcolor0 = color;
	line.pt_0 = p0;
	line.pt_1 = p1;
	bressenham_path(fdf, &line, FALSE);
	line.pt_0 = p1;
	line.pt_1 = p2;
	bressenham_path(fdf, &line, FALSE);
	line.pt_0 = p2;
	line.pt_1 = p0;
	bressenham_path(fdf, &line, FALSE);
}
