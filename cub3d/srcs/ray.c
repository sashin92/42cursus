/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:05 by sashin            #+#    #+#             */
/*   Updated: 2021/05/14 16:26:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_dir(t_info *info)
{
	double	rad;
	double	d;

	rad = (((2 * info->ray.i) / info->win.res_x) - 1) * (M_PI / 180) * FOV_2;
	info->ray.x = info->dir.x * cos(rad) - info->dir.y * sin(rad);
	info->ray.y = info->dir.y * cos(rad) + info->dir.x * sin(rad);
	d = hypot(info->ray.x, info->ray.y);
	info->ray.x = info->ray.x / d;
	info->ray.y = info->ray.y / d;
	if (info->ray.x >= 0)
		info->ray.v = 1;
	else
		info->ray.v = 0;
	if (info->ray.y >= 0)
		info->ray.h = 1;
	else
		info->ray.h = 0;
}

void	ray_dda_ver(t_info *info)
{
	double	x;
	double	y;

	x = floor(info->pos.x) + info->ray.v;
	y = info->pos.y + (info->ray.y / info->ray.x) * (x - info->pos.x);
	while ((floor(y) > 0) && (floor(y) < info->map.y))
	{
		if (info->map.xy[(int)floor(y)][(int)(x - 1 + info->ray.v)] == '1')
		{
			info->hit.x = x;
			info->hit.y = y;
			info->hit.d = hypot(x - info->pos.x, y - info->pos.y);
			return ;
		}
		x = x + (2 * info->ray.v - 1);
		y = x + (2 * info->ray.v - 1) * info->ray.y / info->ray.x;
	}
}

void	ray_dda_hor(t_info *info)
{
	double	x;
	double	y;

	y = floor(info->pos.y) + info->ray.h;
	x = info->pos.x + (info->ray.x / info->ray.y) * (y - info->pos.y);
	while ((floor(x) > 0) && (floor(x) < info->map.x))
	{
		if (info->map.xy[(int)(y - 1 + info->ray.h)][(int)floor(x)] == '1')
		{
			info->hit.x = x;
			info->hit.y = y;
			info->hit.d = hypot(x - info->pos.x, y - info->pos.y);
			return ;
		}
		y = y + (2 * info->ray.h - 1);
		x = y + (2 * info->ray.h - 1) * info->ray.x / info->ray.y;
	}
}

void		ray_stack(t_info *info)
{
	
}

void		raycasting(t_info *info)
{
	int		bpp;
	int		sl;
	int		end;

	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.res_x, info->win.res_y);
	info->img.adr = mlx_get_data_addr(info->img.ptr, &bpp, &sl, &end);
	info->stack = malloc(sizeof(t_stack) * info->win.res_x);
	while (info->ray.i < info->win.res_x)
	{
		ray_dir(info);
		ray_dda_ver(info);
		ray_dda_hor(info);
		info->stack[info  ->ray.i].x = info->ray.x;
		info->stack[info->ray.i].y = info->ray.y;
		info->stack[info->ray.i].d = info->hit.d;
		info->ray.i++;
	}
}