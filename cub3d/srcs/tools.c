/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:42:30 by sashin            #+#    #+#             */
/*   Updated: 2021/06/10 20:35:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_space_skip(char **s)
{
	while ((**s >= 9 && **s <= 13) || **s == ' ')
		++*s;
}

int				ft_skip(char **s, char c)
{
	ft_space_skip(s);
	if (**s == c)
		++*s;
	else
		return (-1);
	ft_space_skip(s);
	return (0);
}

void			calc_rayangle(t_info *s)
{
	s->vec.dx = cos(s->dir.angle);
	s->vec.dy = sin(s->dir.angle);
	s->vec.cx = cos(s->dir.angle + M_PI / 2);
	s->vec.cy = sin(s->dir.angle + M_PI / 2);
	s->vec.rdx = s->vec.dx + s->vec.cx
				* ((2 * (double)s->ray.i / s->win.res_x) - 1);
	s->vec.rdy = s->vec.dy + s->vec.cy
				* ((2 * (double)s->ray.i / s->win.res_x) - 1);
	s->ray.angle = atan(s->vec.rdy / s->vec.rdx);
	if (s->vec.rdx < 0)
		s->ray.angle += M_PI;
}

void			draw_line(t_info *s, int color)
{
	t_mini_img	*fi;
	double		line;

	fi = &(s->mini_img);
	line = 0;
	while (line <= s->hit.dist * s->mini.bsize)
	{
		draw_pixel(s->mini.ppx + line * cos(s->ray.angle),
					s->mini.ppy + line * sin(s->ray.angle), color, fi);
		line += 1;
	}
}

void			free_split(char **arr)
{
	int			i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
