/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:33:57 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 14:56:53 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_maps(t_fdf *fdf)
{
	if (fdf->map_pts != NULL)
	{
		free(fdf->map_pts);
		fdf->map_pts = NULL;
	}
	if (fdf->map_colors != NULL)
	{
		free(fdf->map_colors);
		fdf->map_colors = NULL;
	}
	if (fdf->map_view != NULL)
	{
		free(fdf->map_view);
		fdf->map_view = NULL;
	}
	if (fdf->map_raw != NULL)
	{
		free_raw_elems(fdf->map_raw);
		fdf->map_raw = NULL;
	}
}

void	free_mlx_elements(t_fdf *fdf)
{
	mlx_destroy_window(fdf->win.mlx, fdf->win.win);
	if (fdf->img.ptr)
	{
		mlx_destroy_image(fdf->win.mlx, fdf->img.ptr);
		fdf->img.ptr = NULL;
	}
	if (fdf->win.mlx)
	{
		mlx_destroy_display(fdf->win.mlx);
		free(fdf->win.mlx);
		fdf->win.mlx = NULL;
	}
}

void	free_raw_elems(t_elem *elem)
{
	t_elem	*next;

	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}

void	free_rawline(char **line)
{
	char	*templine;
	int		i;

	i = 0;
	while (line[i] != NULL)
	{
		templine = line[i];
		i++;
		free (templine);
	}
	free (line);
}
