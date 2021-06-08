/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:21 by sashin            #+#    #+#             */
/*   Updated: 2021/06/08 17:24:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int			parse_map(char *line, t_info *s)
{
	int		len;

	if (s->err < 0)
		return (s->err);
	parse_map_copy(s, line);
	map_check_arg(s);
	parse_map_pos(s);
	len = ft_strlen(line);
	if (len > s->map.x)
		s->map.x = len;
	s->map.y++;
	return (s->err);
}
