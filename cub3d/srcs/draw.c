/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:18:49 by sashin            #+#    #+#             */
/*   Updated: 2021/05/20 22:42:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_background(t_info *info)
{
	int		i;

	i = 0;
	while (i < (info->win.res_x * info->win.res_y) / 2)
		info->img.adr[i++] = info->cub.ceilling;
	while (i < (info->win.res_x * info->win.res_y))
		info->img.adr[i++] = info->cub.floor;
}


void			draw_wall(t_info *info, double fov_v)
{
	int			start;
	double		height;
	double		y0;
	double		y1;
	double		i;

	height = (double)info->win.res_y / (2. * info->hit.dist * tan(fov_v / 2.0));
	y0 = ((info->win.res_y - height) / 2.);
	y1 = y0 + height;
	while (y0 <= --y1 && y1 >= 0)
	{
		if (y1 > info->win.res_y)
			continue ;
		if (info->hit.dir == EAST)
		{
			i = floor(64 * (info->hit.y - floor(info->hit.y))) + 64 * floor(64 * ((y1 - y0) / height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.east[(int)i];
		}
		else if (info->hit.dir == WEST)
		{
			i = floor(64 * (info->hit.y - floor(info->hit.y))) + 64 * floor(64 * ((y1 - y0) / height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.west[(int)i];
		}
		else if (info->hit.dir ==NORTH)
		{
			i = floor(64 * (info->hit.x - floor(info->hit.x))) + 64 * floor(64 * ((y1 - y0) / height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.north[(int)i];
		}
		else if (info->hit.dir == SOUTH)
		{
			i = floor(64 * (info->hit.x - floor(info->hit.x))) + 64 * floor(64 * ((y1 - y0) / height));
			info->img.adr[(info->win.res_x * (int)y1) + info->ray.i] = info->cub.south[(int)i];
		}
	}
}
