/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:05 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 23:21:39 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quat_normalize(t_quat *q)
{
	double	norm;

	norm = sqrt(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w);
	if (norm == 0)
	{
		q->x = 0.0;
		q->y = 0.0;
		q->z = 0.0;
		q->w = 1.0;
		return ;
	}
	q->x /= norm;
	q->y /= norm;
	q->z /= norm;
	q->w /= norm;
}

t_quat	quat_multiply(t_quat a, t_quat b)
{
	t_quat	res;

	res.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	res.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	res.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	res.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	return (res);
}
