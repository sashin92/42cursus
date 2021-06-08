/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:22:14 by sashin            #+#    #+#             */
/*   Updated: 2021/06/08 19:02:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_angle(t_info *s, double angle)
{
	s->pos.x += MOVE_SPD * cos(angle);
	if (s->map.yx[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.x -= MOVE_SPD * cos(angle);
	s->pos.y += MOVE_SPD * sin(angle);
	if (s->map.yx[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.y -= MOVE_SPD * sin(angle);
}

static void	put_wasd(int key, t_info *s)
{
	if (key == KEY_W)
		move_angle(s, s->dir.angle);
	else if (key == KEY_S)
		move_angle(s, s->dir.angle + M_PI);
	else if (key == KEY_A)
		move_angle(s, s->dir.angle + M_PI / 2);
	else if (key == KEY_D)
		move_angle(s, s->dir.angle - M_PI / 2);
}

int			put_key(int key, t_info *s)
{
	put_wasd(key, s);
	if (key == KEY_RIGHT)
		s->dir.angle -= (M_PI / 180) * ROTATE_SPD;
	else if (key == KEY_LEFT)
		s->dir.angle += (M_PI / 180) * ROTATE_SPD;
	else if (key == KEY_ESCAPE)
		exit(0);
	while (s->dir.angle >= 2. * M_PI)
		s->dir.angle -= 2. * M_PI;
	while (s->dir.angle < 0)
		s->dir.angle += 2. * M_PI;
	printf("\npos : %f, %f, dir_angle : %f\n", s->pos.x, s->pos.y,
											(s->dir.angle) * 180 / M_PI);
	loop(s);
	return (0);
}
