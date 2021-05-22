/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:05:18 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 01:15:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			file_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("errno: %d\n", errno);
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

int			ismap(char *line)
{
	if (line[0] == '1' || line[0] == ' ')
		return (1);
	return (0);
}

void		check_cubline(t_info *s, char *line)
{
	if (!ft_strncmp("R ", line, 2))
		s->err = parse_resolution(line, s);
	else if (!ft_strncmp("NO ", line, 3))
		s->err = parse_texture(s, line, &s->cub.north);
	else if (!ft_strncmp("SO ", line, 3))
		s->err = parse_texture(s, line, &s->cub.south);
	else if (!ft_strncmp("WE ", line, 3))
		s->err = parse_texture(s, line, &s->cub.west);
	else if (!ft_strncmp("EA ", line, 3))
		s->err = parse_texture(s, line, &s->cub.east);
	else if (!ft_strncmp("S ", line, 2))
		s->err = parse_texture(s, line, &s->cub.sprite);
	else if (!ft_strncmp("F ", line, 2))
		s->err = parse_rgb(line, &s->cub.floor);
	else if (!ft_strncmp("C ", line, 2))
		s->err = parse_rgb(line, &s->cub.ceilling);
	else if (ismap(line))
		s->err = parse_map(line, s);
}
