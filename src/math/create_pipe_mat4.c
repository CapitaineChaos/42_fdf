/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:18:41 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:39:31 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	create_canvas_mat4(t_fdf *fdf, t_canvas cv)
{
	t_mat4	tr;
	t_mat4	zm;
	t_mat4	pan;
	t_mat4	zoom_transform;
	t_mat4	result;

	tr = create_translate_mat4(-fdf->win.width / 2.0, -fdf->win.height / 2.0);
	zm = create_zoom_mat4(cv.zoom);
	zm = mat4_mul(zm, tr);
	tr = create_translate_mat4(fdf->win.width / 2.0, fdf->win.height / 2.0);
	zoom_transform = mat4_mul(tr, zm);
	pan = create_translate_mat4(cv.offset_x, cv.offset_y);
	result = mat4_mul(pan, zoom_transform);
	return (result);
}

t_mat4	create_viewport_mat4(float width, float height, double zoom)
{
	t_mat4	viewport;

	viewport = create_identity_mat4();
	viewport.m[0][0] = zoom * width / 2.0;
	viewport.m[0][3] = width / 2.0;
	viewport.m[1][1] = zoom * height / 2.0;
	viewport.m[1][3] = height / 2.0;
	return (viewport);
}

t_mat4	create_scale_mat4(t_vec3 v)
{
	t_mat4	scale;

	scale = create_identity_mat4();
	scale.m[0][0] = v.x;
	scale.m[1][1] = v.y;
	scale.m[2][2] = v.z;
	return (scale);
}

t_mat4	create_zoom_mat4(double z)
{
	t_mat4	zoom;

	zoom = create_identity_mat4();
	zoom.m[0][0] = z;
	zoom.m[1][1] = z;
	return (zoom);
}

t_mat4	create_translate_mat4(double tx, double ty)
{
	t_mat4	trs;

	trs = create_identity_mat4();
	trs.m[0][3] = tx;
	trs.m[1][3] = ty;
	return (trs);
}
