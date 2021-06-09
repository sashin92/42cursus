/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoi <schoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:22:14 by sashin            #+#    #+#             */
/*   Updated: 2021/06/09 18:45:13 by schoi            ###   ########.fr       */
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

int			ft_destroy(t_info *s)
{
	int		i;

	i = 0;
	while (i < s->map.y)
		free(s->map.yx[i++]);
	free(s->map.yx);
	free(s->cub.north);
	free(s->cub.south);
	free(s->cub.west);
	free(s->cub.east);
	mlx_destroy_window(s->mlx.ptr, s->win[0].ptr);
	free(s->mlx.ptr);
	exit(0);
	return (0);
}

int			put_key(int key, t_info *s)
{
	put_wasd(key, s);
	if (key == KEY_RIGHT)
		s->dir.angle -= (M_PI / 180) * ROTATE_SPD;
	else if (key == KEY_LEFT)
		s->dir.angle += (M_PI / 180) * ROTATE_SPD;
	else if (key == KEY_ESCAPE)
		ft_destroy(s);
	while (s->dir.angle >= 2. * M_PI)
		s->dir.angle -= 2. * M_PI;
	while (s->dir.angle < 0)
		s->dir.angle += 2. * M_PI;
	printf("\npos : %f, %f, dir_angle : %f\n", s->pos.x, s->pos.y,
											(s->dir.angle) * 180 / M_PI);
	s->mini.ppx = s->pos.x * s->mini.bsize;
	s->mini.ppy = s->pos.y * s->mini.bsize;
	loop(s);
	return (0);
}
