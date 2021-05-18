/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:05 by sashin            #+#    #+#             */
/*   Updated: 2021/05/19 00:08:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

#define ROW 6
#define COL 6

int	w_map[ROW][COL] = {
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1}
	};

int	ct = 0;

double	l2dist(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;

	dx = fabs(x1 - x0);
	dy = fabs(y1 - y0);
	return (sqrt(dx * dx + dy * dy));
}

void	get_wall_intersection(t_info *info)
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
	
	while (1) // ray가 hit하기 전까지 루프
	{
		double f;
		double g;
		double dist_v;
		double dist_h;

		int mapx, mapy;

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

		if (mapx >= COL || mapx < 0 || mapy >= ROW || mapy < 0 )
		{
			printf("out! map : %d, %d\n", mapx, mapy);
			break ;
		}
		if (w_map[mapy][mapx] == 1)
		{
			if (info->hit.key == HIT_VERTICAL)
			{
				if (info->ray.xstep > 0)
					info->hit.dir = 1;
				else
					info->hit.dir = 2;
				info->hit.x = info->ray.x;
				info->hit.y = f;
			}
			else if (info->hit.key == HIT_HORIZON)
			{
				if (info->ray.ystep > 0)
					info->hit.dir = 3;
				else
					info->hit.dir = 4;
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

void	draw_vertical(t_info *info, double fov_v)
{
	int		start;
	double	height;
	int		y0;
	int		y1;
	int		i;

	height = (double)info->win.res_y / (2. * info->hit.dist * tan(fov_v / 2.0));
	y0 = (int)((info->win.res_y - height) / 2.);
	y1 = y0 + height - 1; // -1을 왜해주지?

	start = info->win.res_x * (info->win.res_y - height) / 2;

	while (y0 <= y1)
	{
		if (info->hit.dir == 1)
			info->img.adr[(info->win.res_x * y0) - info->ray.i] = 0x00FF0000;
		else if (info->hit.dir == 2)
			info->img.adr[(info->win.res_x * y0) - info->ray.i] = 0x0000FF00;
		else if (info->hit.dir == 3)
			info->img.adr[(info->win.res_x * y0) - info->ray.i] = 0x00FFFFFF;
		else if (info->hit.dir == 4)
			info->img.adr[(info->win.res_x * y0) - info->ray.i] = 0x000000FF;
		++y0;
	}
}

void	raycasting(t_info *info)
{
	double	fov;
	double	fov_v;
	int		ct = 0;

	info->ray.i = 0;
	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.res_x, info->win.res_y);
	info->img.adr = (int *)mlx_get_data_addr(info->img.ptr, &info->img.bpp, &info->img.size_l, &info->img.endian);
	fov = deg_to_rad(FOV);
	fov_v = fov * ((double)info->win.res_x / (double)info->win.res_y);
	while (info->ray.i < info->win.res_x)
	{
		info->ray.angle = (info->dir.angle + fov / 2.) - ((fov / ((double)info->win.res_x - 1.)) * (double)info->ray.i);
		get_wall_intersection(info);
		draw_vertical(info, fov_v);
		++info->ray.i;
	}
}

int	loop(t_info *info)
{
	raycasting(info);
	mlx_put_image_to_window(info->mlx.ptr, info->win.ptr, info->img.ptr, 0, 0);
	return (0);
}

int		move_dot(int key, t_info *info)
{
	if (key == KEY_W)
		printf("\n\n\n\npos : %f, %f\n", info->pos.x, info->pos.y -= 0.1);
	else if (key == KEY_S)
		printf("\n\n\n\npos : %f, %f\n", info->pos.x, info->pos.y += 0.1);
	else if (key == KEY_A)
		printf("\n\n\n\npos : %f, %f\n", info->pos.x -= 0.1, info->pos.y);
	else if (key == KEY_D)
		printf("\n\n\n\npos : %f, %f\n", info->pos.x += 0.1, info->pos.y);
	else if (key == KEY_RIGHT)
		printf("\n\n\n\ndir_angle : %f\n", info->dir.angle += M_PI / 15.);
	else if (key == KEY_LEFT)
		printf("\n\n\n\ndir_angle : %f\n", info->dir.angle -= M_PI / 15.);
	else if (key == KEY_ESCAPE)
		exit(0);
	printf("\n\n\n\ncur : %f, %f, dir_angle : %f\n", info->pos.x, info->pos.y, info->dir.angle);
	loop(info);
	return (0);
}

int main()
{
	t_info info;

	info.win.res_x = 800;
	info.win.res_y = 600;
	info.pos.x = 1.5;
	info.pos.y = 3.5;
	info.ray.i = 0;
	info.dir.angle = - M_PI / 2;
	info.mlx.ptr = mlx_init();

	info.win.ptr = mlx_new_window(info.mlx.ptr, info.win.res_x, info.win.res_y, "UI");
	write(1, "done\n", 5);
	loop(&info);
	mlx_hook(info.win.ptr, 2, 0, move_dot, &info);
	mlx_loop(info.mlx.ptr);
}
