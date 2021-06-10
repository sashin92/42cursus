/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:59:07 by schoi             #+#    #+#             */
/*   Updated: 2021/06/10 21:09:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_block_color(char block, int *c)
{
	if (block == '1')
		*c = 0x777777;
	else if (block == ' ')
		*c = 0x000000;
	else
		*c = 0xffffff;
}

void			draw_pixel(int x, int y, int color, t_mini_img *fi)
{
	fi->adr[y * (fi->sl / (fi->bpp / 8)) + x] = color;
}

void			draw_rectangle(t_info *s, int x, int y, int color)
{
	t_mini_img	*fi;
	int			i;
	int			j;

	fi = &(s->mini_img);
	i = -1;
	j = -1;
	while (++j < s->mini.bsize - 1)
	{
		while (++i < s->mini.bsize - 1)
			draw_pixel(x + i, y + j, color, fi);
		i = -1;
	}
}

void			draw_minimap(t_info *s)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	j = -1;
	c = 0;
	while (++j < s->map.y)
	{
		while (++i < s->map.x)
		{
			set_block_color(s->map.yx[j][i], &c);
			draw_rectangle(s, s->mini.bsize * i, s->mini.bsize * j, c);
		}
		i = -1;
	}
}

void			ft_minimap(t_info *s)
{
	int			min;

	min = s->win.res_y > s->win.res_x ? s->win.res_x : s->win.res_y;
	s->mini.mapsize = min / 3;
	s->mini.bsize = s->map.x > s->map.y
					? s->mini.mapsize / s->map.x : s->mini.mapsize / s->map.y;
	s->mini.ppx = s->pos.x * s->mini.bsize;
	s->mini.ppy = s->pos.y * s->mini.bsize;
}
