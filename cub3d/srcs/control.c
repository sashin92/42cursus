/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:22:14 by sashin            #+#    #+#             */
/*   Updated: 2021/05/19 17:16:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	put_wasd(int key, t_info *info)
{
	if (key == KEY_W)
	{
		info->pos.x += 0.1 * cos(info->dir.angle);
		info->pos.y += 0.1 * sin(info->dir.angle);
	}
	else if (key == KEY_S)
	{
		info->pos.x -= 0.1 * cos(info->dir.angle);
		info->pos.y -= 0.1 * sin(info->dir.angle);
	}
	else if (key == KEY_A)
	{
		info->pos.x += 0.1 * cos(info->dir.angle + M_PI / 2);
		info->pos.y += 0.1 * sin(info->dir.angle + M_PI / 2);
	}
	else if (key == KEY_D)
	{
		info->pos.x -= 0.1 * cos(info->dir.angle + M_PI / 2);
		info->pos.y -= 0.1 * sin(info->dir.angle + M_PI / 2);
	}
}

int		put_key(int key, t_info *info)
{

	put_wasd(key, info);
	if (key == KEY_RIGHT)
		info->dir.angle -= M_PI / 16.;
	else if (key == KEY_LEFT)
		info->dir.angle += M_PI / 16.;
	else if (key == KEY_ESCAPE)
		exit(0);
	while (info->dir.angle >= 2. * M_PI)
		info->dir.angle -= 2. * M_PI;
	while (info->dir.angle < 0)
		info->dir.angle += 2. * M_PI;
	printf("\n\n\n\ncur : %f, %f, dir_angle : %f\n", info->pos.x, info->pos.y, (info->dir.angle) * 180 / M_PI);
	loop(info);
	return (0);
}