/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:21 by sashin            #+#    #+#             */
/*   Updated: 2021/06/10 20:34:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			parse_rgb(char *line, int *rgb)
{
	int		r_g_b[3];
	int		i;

	i = 0;
	if (*rgb != -1)
		return (-3);
	ft_bzero(r_g_b, sizeof(int) * 3);
	ft_space_skip(&line);
	while (i < 3)
	{
		if (!ft_isdigit(*line))
			return (-4);
		while (ft_isdigit(*line))
			r_g_b[i] = (r_g_b[i] * 10) + (*(line++) - '0');
		if (i != 2 && ft_skip(&line, ',') < 0)
			return (-4);
		if (r_g_b[i] > 255)
			return (-4);
		++i;
	}
	ft_space_skip(&line);
	if (*line != 0)
		return (-4);
	*rgb = (r_g_b[0] * 256 * 256) + (r_g_b[1] * 256) + r_g_b[2] + 1;
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
