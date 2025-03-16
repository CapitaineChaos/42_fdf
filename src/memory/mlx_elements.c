/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:16:02 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/13 16:42:39 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_img(t_fdf *fdf, t_img *i)
{
	i->ptr = mlx_new_image(fdf->win.mlx, fdf->win.width, fdf->win.height);
	i->height = fdf->win.height;
	i->width = fdf->win.width;
	if (!i->ptr)
	{
		ft_printf_fd(2, "Erreur: Échec de la création de l'image\n");
		close_fdf(fdf);
	}
	i->dat = mlx_get_data_addr(i->ptr, &i->bpp, &i->size_line, &i->endian);
	if (!i->dat)
	{
		ft_printf_fd(2, "Erreur: Échec de la création de l'image\n");
		close_fdf(fdf);
	}
}

void	init_mlx_elements(t_fdf *fdf)
{
	fdf->win.mlx = mlx_init();
	if (!fdf->win.mlx)
		crash_fdf(fdf, 2);
	if (fdf->win.height <= 0 || fdf->win.width <= 0)
	{
		mlx_get_screen_size(fdf->win.mlx, &fdf->win.width, &fdf->win.height);
		fdf->win.height -= 150;
		fdf->win.width = fdf->win.height;
	}
	fdf->win.win = mlx_new_window(fdf->win.mlx,
			fdf->win.width, fdf->win.height, "FdF");
	if (!fdf->win.win)
		crash_fdf(fdf, 3);
	create_img(fdf, &fdf->img);
}
