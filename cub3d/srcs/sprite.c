/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:25:35 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 17:06:22 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ray_touch_sprite(t_info *s)
{
	s->spr[s->spr_count].x = s->ray.cx + 0.5;
	s->spr[s->spr_count].y = s->ray.cy + 0.5;
	s->spr[s->spr_count].dist = l2dist(s->pos.x, s->pos.y, s->spr[s->spr_count].x, s->spr[s->spr_count].y);
	s->spr[s->spr_count].th = atan2(s->spr[s->spr_count].y - s->pos.y, s->spr[s->spr_count].x - s->pos.x);
	if (s->spr[s->spr_count].th < 0)
		s->spr[s->spr_count].th += 2 * M_PI;
	s->spr[s->spr_count].dist *= cos(s->dir.angle - s->spr[s->spr_count].th);
	++s->spr_count;
}

