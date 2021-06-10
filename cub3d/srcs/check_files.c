/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:05:18 by sashin            #+#    #+#             */
/*   Updated: 2021/06/10 20:15:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			file_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void		check_extension(char *file, char *extension, int fd)
{
	int		file_name_len;
	int		isvalid;

	file_name_len = ft_strlen(file);
	if (file_name_len < 4)
	{
		printf("Invalid extension\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	isvalid = ft_strncmp(&file[file_name_len - 4], extension, 4);
	if (isvalid == 0)
		return ;
	else
	{
		printf("Invalid extension\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
}

static int	ismap(t_info *s, char *line)
{
	if (s->flag == 0 && (line[0] == '1' || line[0] == ' '))
	{
		s->flag = 1;
		return (1);
	}
	if (s->flag == 1)
	{
		if (line[0] != ' ' && line[0] != '1')
			s->err = -15;
	}
	return (0);
}

void		check_cubline(t_info *s, char *line)
{
	if (ismap(s, line) || s->flag == 1)
		s->err = parse_map(line, s);
	else if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("NO\t", line, 3))
		s->err = parse_texture(s, &line[3], &s->cub.north);
	else if (!ft_strncmp("SO ", line, 3) || !ft_strncmp("SO\t", line, 3))
		s->err = parse_texture(s, &line[3], &s->cub.south);
	else if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("WE\t", line, 3))
		s->err = parse_texture(s, &line[3], &s->cub.west);
	else if (!ft_strncmp("EA ", line, 3) || !ft_strncmp("EA\t", line, 3))
		s->err = parse_texture(s, &line[3], &s->cub.east);
	else if (!ft_strncmp("F ", line, 2) || !ft_strncmp("F\t", line, 2))
		s->err = parse_rgb(&line[2], &s->cub.floor);
	else if (!ft_strncmp("C ", line, 2) || !ft_strncmp("C\t", line, 2))
		s->err = parse_rgb(&line[2], &s->cub.ceilling);
	else if (line[0] == '\0')
		return ;
	else
		s->err = -14;
}

void		check_s(t_info *s)
{
	if (s->cub.north == NULL)
		s->err = -7;
	else if (s->cub.south == NULL)
		s->err = -8;
	else if (s->cub.east == NULL)
		s->err = -9;
	else if (s->cub.west == NULL)
		s->err = -10;
	else if (s->cub.floor == -1)
		s->err = -11;
	else if (s->cub.ceilling == -1)
		s->err = -12;
	else if (s->pos.x == 0)
		s->err = -15;
}
