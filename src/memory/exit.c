/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:30:56 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 00:20:01 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(void *params)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)params;
	free_mlx_elements(fdf);
	free_maps(fdf);
	exit(0);
}

int	crash_fdf(void *params, int err_code)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)params;
	if (err_code == 1)
		ft_printf_fd(2, "Malloc error.\nProgram terminated.\n");
	if (err_code == 2)
		ft_printf_fd(2, "MLX init error.\nProgram terminated.\n");
	if (err_code == 3)
		ft_printf_fd(2, "MLX window error.\nProgram terminated.\n");
	free_mlx_elements(fdf);
	free_maps(fdf);
	exit(1);
}
