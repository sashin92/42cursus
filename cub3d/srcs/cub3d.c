/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:20 by sashin            #+#    #+#             */
/*   Updated: 2021/05/14 16:26:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WIDTH 500
#define HEIGHT 500
#define ROW 5
#define COL 5

int		draw_grid(t_info *info)
{
	int		row_count;
	int		col_count;
	int		i;

	row_count = 0;
	col_count = 0;

	while (col_count++ < HEIGHT / COL)
	{
		i = 0;
		while (++i < WIDTH)
			mlx_pixel_put(info->mlx.ptr, info->win.ptr, i, col_count * (WIDTH / COL), 0x00FFFFFF);
	}
	while (row_count++ < WIDTH / ROW)
	{
		i = 0;
		while (++i < HEIGHT)
			mlx_pixel_put(info->mlx.ptr, info->win.ptr, row_count * (HEIGHT / ROW), i, 0x00FFFFFF);
	}
	return (0);
}

// move dot using key

int		move_dot(int key, t_info *info)
{
	if (key == KEY_W)
		printf("\n\n\n\npos : %f, %f\n", info->pos.x, ++info->pos.y);
	else if (key == KEY_S)
		printf("\n\n\n\npos : %f, %f\n", info->pos.x, --info->pos.y);
	else if (key == KEY_A)
		printf("\n\n\n\npos : %f, %f\n", --info->pos.x, info->pos.y);
	else if (key == KEY_D)
		printf("\n\n\n\npos : %f, %f\n", ++info->pos.x, info->pos.y);
	else if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		run(char *cub, t_info info)		// 돌려보자
{
	draw_grid(&info);

	mlx_key_hook(info.win.ptr, move_dot, &info);

	mlx_loop(info.mlx.ptr);
	return (0);
}

int			parse_path(char *line, char **texture)
{
	int		i;
	int		j;
	char	*path;
	int		path_len;

	if (*texture != NULL)
		return (-1);				// 만약 텍스처가 비어있지 않다면(경로지정을 이미 했다면) 에러
	i = 2;
	while (line[i] == ' ')
		++i;
	path_len = 0;
	while (line[i + path_len] != ' ' && line[i + path_len] != '\0')		// 만약 파일이름에 공백이 있다면
		++path_len;
	j = i + path_len;
	while (line[j] != '\0')
		if (line[j++] != ' ')
			return (-1);						// 경로 다음에 다른 문자가 나왔을 때 에러
	path = (char *)malloc(sizeof(char) * (path_len + 1));
	j = 0;
	while (j < path_len)
		path[j++] = line[i++];
	path[j] = '\0';
	*texture = path;
	return (0);
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

int			load_cub(char *cub_file, t_info *info)
{
	int		fd;
	char	*line;
	int		gnl;
	
	fd = file_open(cub_file);
	check_extension(cub_file, ".cub", fd); // 파일 이름이 .cub인지 확인. 아니라면 닫고 끝내기(exit).
	printf("\nOK, .cub file is valid!\n\n");

	while (1) // 여기서부터 파일 내용들을 파싱한다.
	{
		gnl = get_next_line(fd, &line);
		if (!ft_strncmp("R ", line, 2))
			info->err = parse_resolution(line, info);
		else if (!ft_strncmp("NO ", line, 3))
			info->err = parse_path(line, &info->cub.north);
		else if (!ft_strncmp("SO ", line, 3))
			info->err = parse_path(line, &info->cub.south);
		else if (!ft_strncmp("WE ", line, 3))
			info->err = parse_path(line, &info->cub.west);
		else if (!ft_strncmp("EA ", line, 3))
			info->err = parse_path(line, &info->cub.east);
		else if (!ft_strncmp("S ", line, 2))
			info->err = parse_path(line, &info->cub.sprite);
		else if (!ft_strncmp("F ", line, 2))
			info->err = parse_rgb(line, &info->cub.floor);
		else if (!ft_strncmp("C ", line, 2))
			info->err = parse_rgb(line, &info->cub.ceilling);
		// else if (ismap(line))
		// 	info->err = parse_map(line, info);
		free(line);
		// if (info->err < 0)
		// 	printf("에러가 발생했더라.(에러체크함수로 이동)\n");	// 에러체크함수 만들자.
		if (gnl != 1)
			break ;
	}

	printf("%d x %d\n%s\n%s\n%s\n%s\n%s\n", info->win.res_x, info->win.res_y,
			info->cub.north, info->cub.south, info->cub.west, info->cub.east, info->cub.sprite);
	return (0);
}

	int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};


void		init(t_info *info)				// 초기화!
{
	info->mlx.ptr = NULL;
	info->win.ptr = NULL;
	info->img.ptr = NULL;
	info->img.adr = NULL;
	info->win.res_x = 0;
	info->win.res_y = 0;
	info->img.fsh = 0;
	info->err = 0;
	info->map.xy = NULL;
	info->stack = NULL;
	info->map.x = 0;
	info->map.y = 0;
	info->map.spr = 0;
	info->pos.x = 0;
	info->pos.y = 0;
	info->dir.x = 0;
	info->dir.y = 0;
}

int		main(int argc, char **argv)
{
	t_info	info;
	
	if (argc == 1)
		printf("Please input a \".cub\" file. - by sashin\n");
	else if (argc == 2)
	{
		init(&info);
		load_cub(argv[1], &info);
		run(argv[1], info);
	}
	else
		printf("Error: Invalid arguments - by sashin\n");
	return (0);
}
