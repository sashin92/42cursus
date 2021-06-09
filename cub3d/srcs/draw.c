/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:18:49 by sashin            #+#    #+#             */
/*   Updated: 2021/06/09 21:12:40 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			draw_background(t_info *s)
{
	int			i;

	i = 0;
	while (i < (s->win[0].res_x * s->win[0].res_y) / 2)
		s->img.adr[i++] = s->cub.ceilling;
	while (i < (s->win[0].res_x * s->win[0].res_y))
		s->img.adr[i++] = s->cub.floor;
}

static void		draw_wall_dir(t_info *s, int i, int y1, int x)
{
	(void)x;
	if (s->hit.dir == EAST)
		s->img.adr[(s->win[0].res_x * y1) + s->ray.i] = s->cub.east[i];
	else if (s->hit.dir == WEST)
		s->img.adr[(s->win[0].res_x * y1) + s->ray.i] = s->cub.west[i];
	else if (s->hit.dir == NORTH)
		s->img.adr[(s->win[0].res_x * y1) + s->ray.i] = s->cub.north[i];
	else if (s->hit.dir == SOUTH)
		s->img.adr[(s->win[0].res_x * y1) + s->ray.i] = s->cub.south[i];
}

void			draw_wall(t_info *s, double fov, int i)
{
	int			height;
	double		y0;
	double		y1;
	double		per_h;



	s->dx = s->hit.camera_dist * sin(s->dir.angle - s->ray.angle);
	s->mx = s->hit.camera_dist * cos((M_PI / 2) - (fov / 2.));
	double x = (s->win[0].res_x / (2 * s->mx)) * s->dx + (s->win[0].res_x / 2);

	height = (double)s->win[0].res_y / (2. * s->hit.camera_dist * tan(fov / 2.0));
	y0 = ((s->win[0].res_y - height) / 2.);
	y1 = y0 + height;
	if (y1 > s->win[0].res_y)
		y1 = s->win[0].res_y;
	while (y0 <= --y1 && y1 >= 0)
	{
		per_h = floor(64 * ((y1 - y0) / height));
		if (s->hit.dir == EAST || s->hit.dir == WEST)
			i = floor(64 * (s->hit.y - floor(s->hit.y))) + 64 * per_h;
		else if (s->hit.dir == NORTH || s->hit.dir == SOUTH)
			i = floor(64 * (s->hit.x - floor(s->hit.x))) + 64 * per_h;
		draw_wall_dir(s, i, (int)y1, (int)x);
	}
}
