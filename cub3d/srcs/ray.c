/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:05 by sashin            #+#    #+#             */
/*   Updated: 2021/06/08 18:43:21 by sashin           ###   ########.fr       */
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
	s->hit.dist *= cos(s->ray.angle - s->dir.angle);
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

void		raycasting(t_info *s)
{
	double	fov;
	double	fov_v;
	int		i;

	s->ray.i = 0;
	i = 0;
	draw_background(s);
	fov = deg_to_rad(FOV);
	fov_v = fov * ((double)s->win.res_x / (double)s->win.res_y);
	while (s->ray.i < s->win.res_x)
	{
		s->ray.angle = (s->dir.angle + fov / 2.) -
					((fov / ((double)s->win.res_x - 1.)) * (double)s->ray.i);
		calc_wall(s);
		draw_wall(s, fov_v, i);
		++s->ray.i;
	}
}
