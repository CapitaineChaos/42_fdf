/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:37:39 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 15:46:32 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_rawmap(t_fdf *fdf, int r_code)
{
	if (r_code == 1)
	{
		ft_printf_fd(2, "Error : bad map file.\n");
		free_maps(fdf);
		return (1);
	}
	if (fdf->mapinfo.nb_x < 0 || fdf->mapinfo.nb_y < 0)
	{
		ft_printf_fd(2, "Error : map is empty.\n");
		free_maps(fdf);
		return (1);
	}
	if (fdf->mapinfo.nb_x * fdf->mapinfo.nb_y < 2)
	{
		ft_printf_fd(2, "Error : insufficient points to draw.\n");
		free_maps(fdf);
		return (1);
	}
	return (0);
}

int	check_built_map(t_fdf *fdf, int r_code)
{
	if (r_code != fdf->mapinfo.nb)
	{
		ft_printf_fd(2, "Error : abnormal map size.\n");
		free_maps(fdf);
		return (1);
	}
	if (fdf->mapinfo.nb < 1)
	{
		ft_printf_fd(2, "Error : abnormally low number of points.\n");
		free_maps(fdf);
		return (1);
	}
	return (0);
}
