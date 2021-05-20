/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:05 by sashin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/20 22:36:55 by sashin           ###   ########.fr       */
=======
/*   Updated: 2021/05/20 02:41:47 by sashin           ###   ########.fr       */
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



<<<<<<< HEAD
void	ray_dda_step(t_info *info)
=======
double deg_to_rad(double deg)
{
	double	rad;

	rad = deg * M_PI / 180.0;
	return (rad);
}

int rad_step(double rad)
{
	if (fabs(rad) <= EPS)
		return (0);
	if (rad > 0)
		return (1);
	else
		return (-1);
}

double	l2dist(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;

	dx = fabs(x1 - x0);
	dy = fabs(y1 - y0);
	return (sqrt(dx * dx + dy * dy));
}

void	get_wall(t_info *info)
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
{
	info->ray.xstep = rad_step(cos(info->ray.angle));
	info->ray.ystep = rad_step(sin(info->ray.angle));

	if (info->ray.xstep > 0)
		info->ray.x = floor(info->pos.x) + 1.;
	else if (info->ray.xstep < 0)
		info->ray.x = ceil(info->pos.x) - 1.;
	else
		info->ray.x = info->pos.x;
	if (info->ray.ystep > 0)
		info->ray.y = floor(info->pos.y) + 1.;
	else if (info->ray.ystep < 0)
		info->ray.y = ceil(info->pos.y) - 1.;
	else
		info->ray.y = info->pos.y;
}

void	calc_wall(t_info *info)
{
	double f;
	double g;
	double dist_v;
	double dist_h;
	int mapx;
	int mapy;

	ray_dda_step(info);
	while (1)
	{
		if (info->ray.xstep != 0)
			f = tan(info->ray.angle) * (info->ray.x - info->pos.x) + info->pos.y;
		if (info->ray.ystep != 0)
			g = (1. / tan(info->ray.angle)) * (info->ray.y - info->pos.y) + info->pos.x;

		dist_v = l2dist(info->pos.x, info->pos.y, info->ray.x, f);
		dist_h = l2dist(info->pos.x, info->pos.y, g, info->ray.y);

		if (dist_v < dist_h)
		{
			mapx = (info->ray.xstep == 1) ? (int)(info->ray.x) : (int)(info->ray.x) - 1;
			mapy = (int)floor(f);
			info->hit.key = HIT_VERTICAL;
		}
		else if (dist_v > dist_h)
		{
			mapx = (int)floor(g);
			mapy = (info->ray.ystep == 1) ? (int)(info->ray.y) : (int)(info->ray.y) - 1;
			info->hit.key = HIT_HORIZON;
		}
		if (info->ray.ystep == 0)
		{
			mapx = (info->ray.xstep == 1) ? (int)(info->ray.x) : (int)(info->ray.x) - 1;
			mapy = (int)floor(f);
			info->hit.key = HIT_VERTICAL;
		}
		else if (info->ray.xstep == 0)
		{
			mapx = (int)floor(g);
			mapy = (info->ray.ystep == 1) ? (int)(info->ray.y) : (int)(info->ray.y) - 1;
			info->hit.key = HIT_HORIZON;
		}

		if (mapx >= info->map.x || mapx < 0 || mapy >= info->map.y || mapy < 0 )
		{
			printf("out! map : %d, %d\n", mapx, mapy);
			break ;
		}
		if (info->map.xy[mapy][mapx] == '1')
		{
			info->hit.dir = 0;
			if (info->hit.key == HIT_VERTICAL)
			{
				if (info->ray.xstep > 0)
					info->hit.dir = EAST;
				else if (info->ray.xstep < 0)
					info->hit.dir = WEST;
				info->hit.x = info->ray.x;
				info->hit.y = f;
			}
			else if (info->hit.key == HIT_HORIZON)
			{
				if (info->ray.ystep > 0)
					info->hit.dir = NORTH;
				else if (info->ray.ystep < 0)
					info->hit.dir = SOUTH;
				info->hit.x = g;
				info->hit.y = info->ray.y;
			}
			info->hit.dist = l2dist(info->pos.x, info->pos.y, info->hit.x, info->hit.y);
			info->hit.dist *= cos(info->ray.angle - info->dir.angle);
			break ;
		}
		if (info->hit.key == HIT_VERTICAL)
			info->ray.x += info->ray.xstep;
		else if (info->hit.key == HIT_HORIZON)
			info->ray.y += info->ray.ystep;
	}
}

void	raycasting(t_info *info)
{
	double	fov;
	double	fov_v;

	info->ray.i = 0;
	draw_background(info);
	fov = deg_to_rad(FOV);
	fov_v = fov * ((double)info->win.res_x / (double)info->win.res_y);
	while (info->ray.i < info->win.res_x)
	{
		info->ray.angle = (info->dir.angle + fov / 2.) - ((fov / ((double)info->win.res_x - 1.)) * (double)info->ray.i);
		calc_wall(info);
		draw_wall(info, fov_v);
		++info->ray.i;
	}
}
