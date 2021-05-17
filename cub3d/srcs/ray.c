/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:05 by sashin            #+#    #+#             */
/*   Updated: 2021/05/18 02:28:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int		w_map[6][6] = {
// 	{1,1,1,1,1,1},
// 	{1,0,0,0,0,1},
// 	{1,0,0,0,0,1},
// 	{1,0,0,0,0,1},
// 	{1,0,0,0,0,1},
// 	{1,1,1,1,1,1}
// };

// void	ray_dir(t_info *info)
// {
// 	double	rad;
// 	double	d;

// 	rad = (((2 * info->ray.i) / info->win.res_x) - 1) * (M_PI / 180) * FOV_2;
// 	info->ray.x = info->dir.x * cos(rad) - info->dir.y * sin(rad);
// 	info->ray.y = info->dir.y * cos(rad) + info->dir.x * sin(rad);
// 	d = hypot(info->ray.x, info->ray.y);
// 	info->ray.x = info->ray.x / d;
// 	info->ray.y = info->ray.y / d;
// 	if (info->ray.x >= 0)
// 		info->ray.v = 1;
// 	else
// 		info->ray.v = 0;
// 	if (info->ray.y >= 0)
// 		info->ray.h = 1;
// 	else
// 		info->ray.h = 0;
// }

// void	ray_dda_ver(t_info *info)
// {
// 	double	x;
// 	double	y;

// 	x = floor(info->pos.x) + info->ray.v;
// 	y = info->pos.y + (info->ray.y / info->ray.x) * (x - info->pos.x);
// 	while ((floor(y) > 0) && (floor(y) < info->map.y))
// 	{
// 		if (info->map.xy[(int)floor(y)][(int)(x - 1 + info->ray.v)] == '1')
// 		{
// 			info->hit.x = x;
// 			info->hit.y = y;
// 			info->hit.d = hypot(x - info->pos.x, y - info->pos.y);
// 			return ;
// 		}
// 		x = x + (2 * info->ray.v - 1);
// 		y = x + (2 * info->ray.v - 1) * info->ray.y / info->ray.x;
// 	}
// }

// void	ray_dda_hor(t_info *info)
// {
// 	double	x;
// 	double	y;

// 	y = floor(info->pos.y) + info->ray.h;
// 	x = info->pos.x + (info->ray.x / info->ray.y) * (y - info->pos.y);
// 	while ((floor(x) > 0) && (floor(x) < info->map.x))
// 	{
// 		if (info->map.xy[(int)(y - 1 + info->ray.h)][(int)floor(x)] == '1')
// 		{
// 			info->hit.x = x;
// 			info->hit.y = y;
// 			info->hit.d = hypot(x - info->pos.x, y - info->pos.y);
// 			return ;
// 		}
// 		y = y + (2 * info->ray.h - 1);
// 		x = y + (2 * info->ray.h - 1) * info->ray.x / info->ray.y;
// 	}
// }

// void		ray_stack(t_info *info)
// {

// }

// void		raycasting(t_info *info)
// {
// 	int		bpp;
// 	int		sl;
// 	int		end;

// 	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.res_x, info->win.res_y);
// 	info->img.adr = mlx_get_data_addr(info->img.ptr, &bpp, &sl, &end);
// 	info->stack = malloc(sizeof(t_stack) * info->win.res_x);
// 	while (info->ray.i < info->win.res_x)
// 	{
// 		ray_dir(info);
// 		ray_dda_ver(info);
// 		ray_dda_hor(info);
// 		info->stack[info->ray.i].x = info->ray.x;
// 		info->stack[info->ray.i].y = info->ray.y;
// 		info->stack[info->ray.i].d = info->hit.d;
// 		info->ray.i++;
// 	}
// }

double deg_to_rad(double deg)
{
	int rad;

	rad = 0;
	rad = deg * (M_PI * 180.0);

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

#define ROW 6
#define COL 6

int	w_map[ROW][COL] = {
	{1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1}};

double	l2dist(double x0, double x1, double y0, double y1)
{
	double	dx;
	double	dy;

	dx = x1 - x0;
	dy = y1 - y0;
	return (sqrt(dx * dx + dy * dy));
}

void	get_wall_intersection(t_info *info)
{
	info->ray.h = rad_step(cos(info->ray.angle));
	info->ray.v = rad_step(sin(info->ray.angle));

	// double	xslope = (xstep == 0) ? INFINITY : tan(ray);
	// double	yslope = (ystep == 0) ? INFINITY : 1./tan(ray); 만약 ray.x, ray.y가 0이라면 문제가 생길 수 있다.

	if (info->ray.h > 0)
		info->ray.x = floor(info->pos.x) + 1;
	else if (info->ray.h < 0)
		info->ray.x = ceil(info->pos.x) - 1;
	else
		info->ray.x = info->pos.x;
	if (info->ray.v > 0)
		info->ray.y = floor(info->pos.y) + 1;
	else if (info->ray.v < 0)
		info->ray.y = ceil(info->pos.y) - 1;
	else
		info->ray.y = info->pos.y;

	while (1) // ray가 hit하기 전까지 루프
	{
		double f;
		double g;
		double dist_v;
		double dist_h;

		int mapx, mapy;

		if (info->ray.h != 0)
			f = tan(info->ray.angle) * (info->ray.x - info->pos.x) + info->pos.y;
		if (info->ray.v != 0)
			g = (1. / tan(info->ray.angle)) * (info->ray.y - info->pos.y) + info->pos.x;

		/* which is nearer to me - VERT(nx,f) or HORIZ(g,ny)? */
		dist_v = l2dist(info->pos.x, info->pos.y, info->ray.x, f);
		dist_h = l2dist(info->pos.x, info->pos.y, g, info->ray.y);

		if (dist_v < dist_h)
		{
			mapx = (info->ray.h == 1) ? (int)(info->ray.x) : (int)(info->ray.x) - 1;
			mapy = (int)f;
			info->hit.key = HIT_VERTICAL;
		}
		else
		{
			mapx = (int)g;
			mapy = (info->ray.v == 1) ? (int)(info->ray.y) : (int)(info->ray.y) - 1;
			info->hit.key = HIT_HORIZON;
		}
		if (mapx > ROW || mapy > COL)
			break; /* out of map */

		if (w_map[mapx][mapy] == 1)
		{
			if (info->hit.key == HIT_VERTICAL)
			{
				if (info->ray.h > 0)
					info->hit.d = 1;
				else
					info->hit.d = -1;
				info->hit.x = info->ray.x;
				info->hit.y = f;
			}
			else if (info->hit.key == HIT_HORIZON)
			{
				if (info->ray.v > 0)
					info->hit.d = 1;
				else
					info->hit.d = -1;
				info->hit.x = g;
				info->hit.y = info->ray.y;
			}
		}
		printf(" hit wall!\n");
		break;
	}

	if (info->hit.key == HIT_VERTICAL)
		info->ray.x += info->ray.h;
	else if (info->hit.key == HIT_HORIZON)
		info->ray.y += info->ray.v;
/* end of while(!hit) */
}

void raycasting(t_info *info)
{
	double fov;

	fov = deg_to_rad(FOV);
	while (info->ray.i < info->win.res_x)
	{
		info->ray.angle = (info->dir.angle + fov / 2) - (fov / (info->win.res_x - 1)) * info->ray.i;
		get_wall_intersection(info);//계산;
		++info->ray.i;
	}
}

int main()
{
	t_info info;
	info.pos.x = 2;
	info.pos.y = 2;
	info.ray.i = 0;	// 1부터? 0부터?
	info.win.res_x = 10;
	info.win.res_y = 10;

	raycasting(&info);
}