/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:12:54 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:48:18 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	acc_rot_global(t_quat *orientation, t_vec3 axis, double angle)
{
	t_quat	delta;

	delta = quat_angle(axis, angle);
	*orientation = quat_multiply(delta, *orientation);
	quat_normalize(orientation);
}

void	acc_rot_local(t_quat *orientation, t_vec3 axis, double angle)
{
	t_quat	delta;

	delta = quat_angle(axis, angle);
	*orientation = quat_multiply(*orientation, delta);
	quat_normalize(orientation);
}

void	init_identity_quaternion(t_quat *q)
{
	q->x = 0.0;
	q->y = 0.0;
	q->z = 0.0;
	q->w = 1.0;
}

t_quat	quat_angle(t_vec3 axis, double angle)
{
	t_quat	q;
	double	half;
	double	s;

	half = angle / 2.0;
	s = sin(half);
	q.x = axis.x * s;
	q.y = axis.y * s;
	q.z = axis.z * s;
	q.w = cos(half);
	return (q);
}

t_mat4	quat_to_mat4(t_quat q)
{
	t_mat4	mat;

	mat.m[0][0] = 1.0 - 2.0 * (q.y * q.y + q.z * q.z);
	mat.m[0][1] = 2.0 * (q.x * q.y - q.z * q.w);
	mat.m[0][2] = 2.0 * (q.x * q.z + q.y * q.w);
	mat.m[0][3] = 0.0;
	mat.m[1][0] = 2.0 * (q.x * q.y + q.z * q.w);
	mat.m[1][1] = 1.0 - 2.0 * (q.x * q.x + q.z * q.z);
	mat.m[1][2] = 2.0 * (q.y * q.z - q.x * q.w);
	mat.m[1][3] = 0.0;
	mat.m[2][0] = 2.0 * (q.x * q.z - q.y * q.w);
	mat.m[2][1] = 2.0 * (q.y * q.z + q.x * q.w);
	mat.m[2][2] = 1.0 - 2.0 * (q.x * q.x + q.y * q.y);
	mat.m[2][3] = 0.0;
	mat.m[3][0] = 0.0;
	mat.m[3][1] = 0.0;
	mat.m[3][2] = 0.0;
	mat.m[3][3] = 1.0;
	return (mat);
}
