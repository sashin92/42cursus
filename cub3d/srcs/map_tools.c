/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:13:21 by sashin            #+#    #+#             */
/*   Updated: 2021/06/08 18:34:52 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			map_check_arg(t_info *s)
{
	int		i;

	i = 0;
	while (s->map.yx[s->map.y][i])
	{
		if (s->map.yx[s->map.y][i] != 'N' && s->map.yx[s->map.y][i] != 'S'
			&& s->map.yx[s->map.y][i] != 'W' && s->map.yx[s->map.y][i] != 'E'
			&& s->map.yx[s->map.y][i] != '0' && s->map.yx[s->map.y][i] != '1'
			&& s->map.yx[s->map.y][i] != ' ')
			return (s->err = -15);
		++i;
	}
	return (0);
}

void		parse_map_copy(t_info *s, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (s->map.y + 2));
	while (i < s->map.y)
	{
		tmp[i] = s->map.yx[i];
		++i;
	}
	if (s->map.yx)
		free(s->map.yx);
	tmp[s->map.y] = ft_strdup(line);
	s->map.yx = tmp;
}

int			parse_map_pos(t_info *s)
{
	int		i;

	i = 0;
	while (s->map.yx[s->map.y][i])
	{
		if (s->map.yx[s->map.y][i] == 'N' || s->map.yx[s->map.y][i] == 'S'
			|| s->map.yx[s->map.y][i] == 'W' || s->map.yx[s->map.y][i] == 'E')
		{
			if (s->pos.x != 0)
				return (s->err = -15);
			s->pos.x = i + 0.5;
			s->pos.y = s->map.y + 0.5;
			if (s->map.yx[s->map.y][i] == 'N')
				s->dir.angle = M_PI / 2;
			else if (s->map.yx[s->map.y][i] == 'S')
				s->dir.angle = M_PI / 2 * 3;
			else if (s->map.yx[s->map.y][i] == 'W')
				s->dir.angle = M_PI;
		}
		++i;
	}
	return (0);
}

void		map_sort(t_info *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < s->map.y)
	{
		if ((int)ft_strlen(s->map.yx[i]) < s->map.x)
		{
			j = -1;
			tmp = (char *)malloc(sizeof(char) * s->map.x);
			while (++j < (int)ft_strlen(s->map.yx[i]))
				tmp[j] = s->map.yx[i][j];
			while (j < s->map.x)
			{
				tmp[j] = ' ';
				++j;
			}
			free(s->map.yx[i]);
			s->map.yx[i] = tmp;
		}
		++i;
	}
}
