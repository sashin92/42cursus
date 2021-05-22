/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:25:35 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 01:16:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ray_touch_sprite(t_info *s, int i)
{
	
	t_spr	*tmp;
	tmp = (t_spr *)malloc(sizeof(t_spr) * i);

	while (--i > 0)
	{
		tmp[i].x = s->ray.cx + 0.5;
		tmp[i].y = s->ray.cy + 0.5;
		tmp[i].th = atan2((tmp[i].y - s->pos.y), tmp[i].x - s->pos.x);
		if (tmp[i].th < 0)
			tmp[i].th += M_PI;
		tmp[i].dist = l2dist(s->pos.x, s->pos.y, tmp[i].x, tmp[i].y);
		--i;
	}
	if (s->spr != NULL)
		free(s->spr);
	s->spr = tmp;
}
