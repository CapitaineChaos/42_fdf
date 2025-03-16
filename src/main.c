/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:19:29 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/15 22:26:21 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	start_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win.win, 17, 0, main_hook_close, fdf);
	mlx_hook(fdf->win.win, 2, 1L << 0, main_hook_keypress, fdf);
	mlx_hook(fdf->win.win, 3, 1L << 1, main_hook_keyrelease, fdf);
	mlx_mouse_hook(fdf->win.win, main_hook_mouseclick, fdf);
	mlx_hook(fdf->win.win, 6, 1L << 6, main_hook_mousemove, fdf);
	mlx_hook(fdf->win.win, 5, 1L << 3, main_hook_mouserelease, fdf);
	mlx_loop_hook(fdf->win.mlx, main_hook_loop, fdf);
	mlx_hook(fdf->win.win, 12, 1L << 15, main_hook_loop, fdf);
	mlx_loop(fdf->win.mlx);
}

static int	start_map(t_fdf *fdf, char *map)
{
	int	r_code;

	r_code = read_raw_map(map, fdf);
	if (check_rawmap(fdf, r_code))
		return (1);
	r_code = build_map(fdf);
	if (check_built_map(fdf, r_code))
		return (1);
	fdf->map_view = get_map_pts(fdf);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		ft_memset(&fdf, 0, sizeof(t_fdf));
		init_fdf(&fdf);
		if (start_map(&fdf, av[1]))
			return (1);
		init_mlx_elements(&fdf);
		fdf.mapinfo.center = center_map_mat4(&fdf);
		fdf.mapinfo.r_mode = M_OBJECT;
		fdf.mapinfo.v_mode = V_ISOMETRIC;
		fdf.mapinfo.c_mode = C_AUTO;
		fdf.projs[0] = init_iso_view(&fdf);
		fdf.projs[1] = init_conic_view(&fdf);
		fdf.cur_proj = &fdf.projs[0];
		fdf.state = REDRAW_FULL_AUTO;
		start_hooks(&fdf);
	}
	return (0);
}
