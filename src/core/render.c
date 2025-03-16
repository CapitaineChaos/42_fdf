/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:31:37 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:57:22 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	global_render(t_fdf *fdf)
{
	if (fdf->state == REDRAW_STOP)
		return ;
	if (fdf->state == REDRAW_FULL_AUTO)
		compute_display_points(fdf, 1);
	else if (fdf->state == REDRAW_FULL_NO_AUTO)
		compute_display_points(fdf, 0);
	else if (fdf->state == REDRAW_VIEW_ONLY)
		compute_display_points(fdf, 2);
	ft_memset(fdf->img.dat, 0, fdf->img.size_line * fdf->img.height);
	render_view(fdf, fdf->map_view);
	mlx_put_image_to_window(fdf->win.mlx, fdf->win.win, fdf->img.ptr, 0, 0);
	show_infos_top(fdf);
	show_infos_bottom(fdf);
	fdf->state = REDRAW_STOP;
}

static void	render_h_line(t_fdf *fdf, int i, int pt[2], t_vec4 *view)
{
	t_line	line;

	line.pt_0.x = pt[0];
	line.pt_0.y = pt[1];
	line.pt_0.z = fdf->map_pts[i].z;
	line.pt_1.x = view[i + 1].x;
	line.pt_1.y = view[i + 1].y;
	line.pt_1.z = fdf->map_pts[i + 1].z;
	line.gcolor0 = fdf->map_colors[i];
	line.gcolor1 = fdf->map_colors[i + 1];
	if (liang_barsky_clip(&line, fdf, 0.0f, 1.0f))
		bressenham_path(fdf, &line, TRUE);
}

static void	render_v_line(t_fdf *fdf, int i, int pt[2], t_vec4 *view)
{
	t_line	l;

	l.pt_0.x = pt[0];
	l.pt_0.y = pt[1];
	l.pt_0.z = fdf->map_pts[i].z;
	l.pt_1.x = view[i + fdf->mapinfo.nb_x].x;
	l.pt_1.y = view[i + fdf->mapinfo.nb_x].y;
	l.pt_1.z = fdf->map_pts[i + fdf->mapinfo.nb_x].z;
	l.gcolor0 = fdf->map_colors[i];
	l.gcolor1 = fdf->map_colors[i + fdf->mapinfo.nb_x];
	if (liang_barsky_clip(&l, fdf, 0.0f, 1.0f))
		bressenham_path(fdf, &l, TRUE);
}

void	render_view(t_fdf *fdf, t_vec4 *view)
{
	int		i;
	int		x;
	int		y;
	int		x0;
	int		y0;

	i = 0;
	while (i < fdf->mapinfo.nb)
	{
		y = i / fdf->mapinfo.nb_x;
		x = i % fdf->mapinfo.nb_x;
		x0 = view[i].x;
		y0 = view[i].y;
		if (x < fdf->mapinfo.nb_x - 1)
			render_h_line(fdf, i, (int [2]){x0, y0}, view);
		if (y < fdf->mapinfo.nb_y - 1)
			render_v_line(fdf, i, (int [2]){x0, y0}, view);
		i++;
	}
}
