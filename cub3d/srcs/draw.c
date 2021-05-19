/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:18:49 by sashin            #+#    #+#             */
/*   Updated: 2021/05/20 01:35:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_vertical(t_info *info, double fov_v)
{
	int		start;
	double	height;
	double	y0;
	double	y1;
	double		i;

	height = (double)info->win.res_y / (2. * info->hit.dist * tan(fov_v / 2.0));
	y0 = (int)((info->win.res_y - height) / 2.);
	if (y0 < 0)
		y0 = 0;
	y1 = y0 + height - 1;
	if (y1 >= info->win.res_y)
		y1 = info->win.res_y - 1;

	mlx_get_color_value(info->mlx.ptr, info->cub.north[(int)i]);
	while (y0 <= y1)
	{
		if (info->hit.dir == 1)
		{
			i = floor(64 * (info->hit.y - floor(info->hit.y))) + 64 * floor(64 * (y1 - y0) / (height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.north[(int)i];
		}
		else if (info->hit.dir == 2)
		{
			i = floor(64 * (info->hit.y - floor(info->hit.y))) + 64 * floor(64 * (y1 - y0) / (height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.south[(int)i];
		}
		else if (info->hit.dir == 3)
		{
			i = floor(64 * (info->hit.x - floor(info->hit.x))) + 64 * floor(64 * (y1 - y0) / (height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.west[(int)i];
		}
		else if (info->hit.dir == 4)
		{
			i = floor(64 * (info->hit.x - floor(info->hit.x))) + 64 * floor(64 * (y1 - y0) / (height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.east[(int)i];
		}
		--y1;
	}
}
