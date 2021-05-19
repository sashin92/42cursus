/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:05:18 by sashin            #+#    #+#             */
/*   Updated: 2021/05/20 02:33:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			file_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);			// 파일이 존재하는지 확인, 있으면 열고 열렸는지 확인.
	if (fd == -1)
	{
		printf("errno: %d\n", errno);
		perror (file);
		exit (EXIT_FAILURE);
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
		exit (EXIT_FAILURE);
	}
	isvalid = ft_strncmp(&file[file_name_len - 4], extension, 4);
	if (isvalid == 0)
		return ;
	else
	{
		printf("Invalid extension\n");
		close(fd);
		exit (EXIT_FAILURE);
	}
}


int			ismap(char *line)			// 니가 맵이냐
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1')
			++i;
		else
			return (0);
	}
	return (1);
}

void		check_str(char *line, t_info *info)
{
		if (!ft_strncmp("R ", line, 2))
			info->err =parse_resolution(line, info);
		else if (!ft_strncmp("NO ", line, 3))
			info->err = parse_texture(info, line, &info->cub.north);
		else if (!ft_strncmp("SO ", line, 3))
			info->err = parse_texture(info, line, &info->cub.south);
		else if (!ft_strncmp("WE ", line, 3))
			info->err = parse_texture(info, line, &info->cub.west);
		else if (!ft_strncmp("EA ", line, 3))
			info->err = parse_texture(info, line, &info->cub.east);
		else if (!ft_strncmp("S ", line, 2))
			info->err = parse_texture(info, line, &info->cub.sprite);
		else if (!ft_strncmp("F ", line, 2))
			info->err = parse_rgb(line, &info->cub.floor);
		else if (!ft_strncmp("C ", line, 2))
			info->err = parse_rgb(line, &info->cub.ceilling);
		// else if (ismap(line))
		// info->err = parse_map(line, info);
}
