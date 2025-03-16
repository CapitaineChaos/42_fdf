/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_base_mat4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:43:41 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:44:15 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_identity_mat4(t_mat4 *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				m->m[i][j] = 1.0;
			else
				m->m[i][j] = 0.0;
			j++;
		}
		i++;
	}
}

t_mat4	create_identity_mat4(void)
{
	t_mat4	identity;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				identity.m[i][j] = 1.0;
			else
				identity.m[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (identity);
}
