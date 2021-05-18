/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:18:49 by sashin            #+#    #+#             */
/*   Updated: 2021/05/19 00:27:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		draw_grid(t_info *info)
{
	int		row_count;
	int		col_count;
	int		i;
	int		j;

	row_count = 1;
	col_count = 1;

	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.res_x, info->win.res_y);
	info->img.adr = (int *)mlx_get_data_addr(info->img.ptr, &info->img.bpp, &info->img.size_l, &info->img.endian);

	j = 0;
	while (j < info->win.res_y)
	{
		i = 0;
		while (i < info->win.res_x)
		{
			if (i % 4)
				info->img.adr[info->win.res_x * j + i] = 0x00FFFF;
			else
				info->img.adr[info->win.res_x * j + i] = 0x0000FF;
			++i;
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(info->mlx.ptr, info->win.ptr, info->img.ptr, 0, 0);
	return (0);
}