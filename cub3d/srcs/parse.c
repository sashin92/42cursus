/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:21 by sashin            #+#    #+#             */
/*   Updated: 2021/06/04 01:45:20 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			parse_resolution(char *line, t_info *s)
{
	if (s->win.res_x != 0 || s->win.res_y != 0)
		return (-1);
	ft_space_skip(&line);
	while (ft_isdigit(*line))
		s->win.res_x = (s->win.res_x * 10) + (*(line++) - '0');
	ft_space_skip(&line);
	while (ft_isdigit(*line))
		s->win.res_y = (s->win.res_y * 10) + (*(line++) - '0');
	ft_space_skip(&line);
	if (s->win.res_x <= 0 || s->win.res_x <= 0 || *line != '\0')
		return (-2);
	return (0);
}

int			parse_rgb(char *line, int *rgb)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	if (*rgb != -1)
		return (-3);
	ft_space_skip(&line);
	while (ft_isdigit(*line))
		r = (r * 10) + (*(line++) - '0');
	ft_skip(&line, ',');
	while (ft_isdigit(*line))
		g = (g * 10) + (*(line++) - '0');
	ft_skip(&line, ',');
	while (ft_isdigit(*line))
		b = (b * 10) + (*(line++) - '0');
	while (*line == ' ' || *line == '\t')
		++line;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || *line != 0)
		return (-4);
	*rgb = (r * 256 * 256) + (g * 256) + b + 1;
	return (0);
}

static int	texture_open(t_info *s, char *texture_name, int **texture)
{
	int		fd;
	void	*texture_img_ptr;

	fd = file_open(texture_name);
	check_extension(texture_name, ".xpm", fd);
	close(fd);
	texture_img_ptr = mlx_xpm_file_to_image(s->mlx.ptr, texture_name,
											&s->img.w, &s->img.h);
	*texture = (int *)mlx_get_data_addr(texture_img_ptr, &s->img.bpp,
										&s->img.sl, &s->img.end);
	free(texture_img_ptr);
	free(texture_name);
	return (0);
}

int			parse_texture(t_info *s, char *line, int **texture)
{
	int		i;
	char	*texture_name;
	int		name_len;

	i = 0;
	if (*texture != NULL)
		return (-1);
	ft_space_skip(&line);
	name_len = 0;
	while ((*(line + name_len) != '\t') && *(line + name_len) != '\0')
		++name_len;
	while (*(line + name_len + i) != '\0')
	{
		if (*(line + name_len + i) == '\t')
			return (-5);
		++i;
	}
	texture_name = (char *)malloc(sizeof(char) * (name_len + 1));
	i = 0;
	while (i < name_len)
		texture_name[i++] = *(line++);
	texture_name[i] = '\0';
	return (texture_open(s, texture_name, texture));
}

int			check_map_isvalid(t_info *s, char *tmp, int i)
{
	int		j;

	j = 0;
	if (i == 0)
	{
		while (tmp[j])
		{
			if (tmp[j] == ' ' || tmp[j] == '1')
				++j;
			else
				break ;
		}
		if (tmp[j] != '\0')
			return (-1);
	}
	else
	{
		while (tmp[j]
		{
			if 
		})

	}
	return (0);
}


int			parse_map(char *line, t_info *s)
{
	int		i;
	int		len;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (s->map.y + 2));
	i = 0;
	while (i < s->map.y)
	{
		tmp[i] = s->map.yx[i];
		++i;
	}
	if (s->map.yx)
		free(s->map.yx);
	tmp[s->map.y] = ft_strdup(line);
	s->map.yx = tmp;
	check_map_isvalid(s, tmp, i);
	len = ft_strlen(line);
	int j = 0;
	while (s->map.yx[s->map.y][j])
	{
		if (s->map.yx[s->map.y][j] == 'N')
		{
			s->pos.x = j + 0.5;
			s->pos.y = s->map.y + 0.5;
		}
		++j;
	}
	if (len > s->map.x)
		s->map.x = len;
	s->map.y++;
	return (0);
}
