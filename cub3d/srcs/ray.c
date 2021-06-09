/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:05 by sashin            #+#    #+#             */
/*   Updated: 2021/06/09 22:15:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ray_dda_check(t_info *s)
{
	double	dist_v;
	double	dist_h;

	if (s->ray.xstep != 0)
		s->ray.f = tan(s->ray.angle) * (s->ray.x - s->pos.x) + s->pos.y;
	if (s->ray.ystep != 0)
		s->ray.g = (1. / tan(s->ray.angle)) * (s->ray.y - s->pos.y) + s->pos.x;
	dist_v = l2dist(s->pos.x, s->pos.y, s->ray.x, s->ray.f);
	dist_h = l2dist(s->pos.x, s->pos.y, s->ray.g, s->ray.y);
	if (dist_v < dist_h)
		ray_hit_v(s);
	else if (dist_v > dist_h)
		ray_hit_h(s);
	if (s->ray.ystep == 0)
		ray_hit_v(s);
	else if (s->ray.xstep == 0)
		ray_hit_h(s);
}

static void	ray_touch_wall(t_info *s)
{
	s->hit.dir = 0;
	if (s->hit.key == HIT_VERTICAL)
	{
		if (s->ray.xstep > 0)
			s->hit.dir = EAST;
		else if (s->ray.xstep < 0)
			s->hit.dir = WEST;
		s->hit.x = s->ray.x;
		s->hit.y = s->ray.f;
	}
	else if (s->hit.key == HIT_HORIZON)
	{
		if (s->ray.ystep > 0)
			s->hit.dir = NORTH;
		else if (s->ray.ystep < 0)
			s->hit.dir = SOUTH;
		s->hit.x = s->ray.g;
		s->hit.y = s->ray.y;
	}
	s->hit.dist = l2dist(s->pos.x, s->pos.y, s->hit.x, s->hit.y);
	draw_rectangle(s, 2, 2, s->hit.x * s->mini.bsize, s->hit.y * s->mini.bsize, 0xff0000);
	s->hit.camera_dist = s->hit.dist * cos(s->ray.angle - s->dir.angle);
}

static void	ray_dda_step(t_info *s)
{
	s->ray.xstep = rad_step(cos(s->ray.angle));
	s->ray.ystep = rad_step(sin(s->ray.angle));
	if (s->ray.xstep > 0)
		s->ray.x = floor(s->pos.x) + 1.;
	else if (s->ray.xstep < 0)
		s->ray.x = ceil(s->pos.x) - 1.;
	else
		s->ray.x = s->pos.x;
	if (s->ray.ystep > 0)
		s->ray.y = floor(s->pos.y) + 1.;
	else if (s->ray.ystep < 0)
		s->ray.y = ceil(s->pos.y) - 1.;
	else
		s->ray.y = s->pos.y;
}

static void	calc_wall(t_info *s)
{
	ray_dda_step(s);
	while (1)
	{
		ray_dda_check(s);
		if (s->ray.cx >= s->map.x || s->ray.cx < 0 ||
			s->ray.cy >= s->map.y || s->ray.cy < 0)
			break ;
		if (s->map.yx[s->ray.cy][s->ray.cx] == '1')
		{
			ray_touch_wall(s);
			break ;
		}
		if (s->hit.key == HIT_VERTICAL)
			s->ray.x += s->ray.xstep;
		else if (s->hit.key == HIT_HORIZON)
			s->ray.y += s->ray.ystep;
	}
}

void			draw_line(t_info *s, int xs, int ys,
							double len, double ang, int color)
{
	t_mini_img	*fi;
	double	line;

	fi = &(s->mini_img);
	line = 0;
	while (line <= len)
	{
		draw_pixel(xs + line * cos(ang), ys + line * sin(ang), color, fi);
		line += 1;
	}
}

// void		raycasting(t_info *s)
// {
// 	double	fov;
// 	// double	fov_v;
// 	int		i;
// 	// double	th;

// 	s->ray.i = 0;
// 	i = 0;
// 	draw_background(s);
// 	fov = deg_to_rad(FOV);

// 	// th = 0;
// 	s->ray.angle = M_PI / 2 - s->dir.angle + fov / 2;


// 	// fov_v = fov * ((double)s->win[0].res_x / (double)s->win[0].res_y);
// 	while (s->ray.angle >= 0)
// 	{
// 		calc_wall(s);
// 		draw_wall(s, fov, i);

// 		draw_line(s, s->mini.ppx, s->mini.ppy, s->hit.dist * s->mini.bsize, s->ray.angle, 0x00ff00);
// 		s->ray.angle = atan(tan(s->ray.angle) - 1 / (double)s->win[0].res_x);
// 	}
// }



void		raycasting(t_info *s)
{
	double	fov;
	double	fov_v;
	int		i;

	s->ray.i = 0;
	i = 0;
	draw_background(s);
	fov = deg_to_rad(FOV);
	fov_v = fov * ((double)s->win[0].res_x / (double)s->win[0].res_y);
	while (s->ray.i < s->win[0].res_x)
	{
		s->ray.angle = (s->dir.angle + fov / 2.) -
					(((fov / ((double)s->win[0].res_x - 1.)) * (double)s->ray.i));
		calc_wall(s);
		draw_wall(s, fov_v, i);

		draw_line(s, s->mini.ppx, s->mini.ppy, s->hit.dist * s->mini.bsize, s->ray.angle, 0x00ff00);
		s->ray.angle = atan(tan(s->ray.angle) - 1 / (double)s->win[0].res_x);
		++s->ray.i;
	}
}