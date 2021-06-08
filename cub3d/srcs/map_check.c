/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:21:02 by sashin            #+#    #+#             */
/*   Updated: 2021/06/08 18:01:09 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_map_inside(t_info *s)
{
	int		x;
	int		y;

	y = 1;
	while (y < s->map.y - 1)
	{
		x = 1;
		while (x < s->map.x - 1)
		{
			if (s->map.yx[y][x] == '0')
			{
				if (s->map.yx[y][x - 1] == ' ' || s->map.yx[y - 1][x] == ' '
					|| s->map.yx[y][x + 1] == ' ' || s->map.yx[y + 1][x] == ' '
					|| s->map.yx[y - 1][x - 1] == ' '
					|| s->map.yx[y + 1][x - 1] == ' '
					|| s->map.yx[y - 1][x + 1] == ' '
					|| s->map.yx[y + 1][x + 1] == ' ')
					return (s->err = -15);
			}
			++x;
		}
		++y;
	}
	return (0);
}

int			check_map_outside(t_info *s)
{
	int		i;

	i = 0;
	while (i < s->map.x - 1)
	{
		if (s->map.yx[0][i] != '1' && s->map.yx[0][i] != ' ')
			return (s->err = -15);
		if (s->map.yx[s->map.y - 1][i] != '1'
			&& s->map.yx[s->map.y - 1][i] != ' ')
			return (s->err = -15);
		++i;
	}
	i = 0;
	while (i < s->map.y - 1)
	{
		if (s->map.yx[i][0] != '1' && s->map.yx[i][0] != ' ')
			return (s->err = -15);
		if (s->map.yx[i][s->map.x - 1] != '1'
			&& s->map.yx[i][s->map.x - 1] != ' ')
			return (s->err = -15);
		++i;
	}
	return (0);
}
