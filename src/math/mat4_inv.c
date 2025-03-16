/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:55:41 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:37:46 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	minor_det(t_mat4 m, int row, int col)
{
	double	a[9];
	int		index;
	int		i;
	int		j;

	index = 0;
	i = -1;
	while (++i < 4)
	{
		if (i == row)
			continue ;
		j = -1;
		while (++j < 4)
		{
			if (j == col)
				continue ;
			a[index++] = m.m[i][j];
		}
	}
	return (a[0] * (a[4] * a[8] - a[5] * a[7])
		- a[1] * (a[3] * a[8] - a[5] * a[6])
		+ a[2] * (a[3] * a[7] - a[4] * a[6]));
}

t_mat4	compute_cofactor_matrix(t_mat4 m)
{
	t_mat4	cof;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			cof.m[i][j] = minor_det(m, i, j);
			if ((i + j) & 1)
				cof.m[i][j] *= -1;
			j++;
		}
		i++;
	}
	return (cof);
}

t_mat4	invert_mat4_(t_mat4 m)
{
	t_mat4	cof;
	double	det;
	t_mat4	adj;

	cof = compute_cofactor_matrix(m);
	det = m.m[0][0] * cof.m[0][0]
		+ m.m[0][1] * cof.m[1][0]
		+ m.m[0][2] * cof.m[2][0]
		+ m.m[0][3] * cof.m[3][0];
	if (det == 0)
		return (create_identity_mat4());
	adj = transpose_mat4(cof);
	scale_mat4_by(&adj, 1.0 / det);
	return (adj);
}
