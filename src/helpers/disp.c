/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:23 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/16 00:01:51 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	float_to_str(t_fdf *fdf, float f, int cds[2], int precision)
{
	char	*str1;
	char	*str2;
	char	*inum;
	char	*fnum;
	int		nums[2];

	nums[0] = (int)f;
	nums[1] = (fabs(f) - (float)(abs((int)f))) * pow(10, precision);
	inum = ft_itoa(nums[0]);
	fnum = ft_itoa(nums[1]);
	if (f < 0 && nums[0] == 0 && nums[1] > 0)
	{
		str1 = ft_strjoin("-", inum);
		free(inum);
		inum = str1;
	}
	str1 = ft_strjoin(inum, ".");
	str2 = ft_strjoin(str1, fnum);
	mlx_string_put(fdf->win.mlx, fdf->win.win, cds[0], cds[1], 0xFFFFFF, str2);
	free(inum);
	free(fnum);
	free(str1);
	free(str2);
}

void	angle_to_str(t_fdf *fdf, float angle, int x, int y)
{
	int		ipart;
	int		fpart;

	angle = angle * 180.0 / M_PI;
	ipart = abs((int)angle);
	fpart = (fabs(angle) - (float)ipart) * 100;
	ipart = ipart % 360;
	angle = (float)ipart + fpart / 100.0;
	float_to_str(fdf, angle, (int [2]){x, y}, 2);
}
