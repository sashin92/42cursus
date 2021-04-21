/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:20 by sashin            #+#    #+#             */
/*   Updated: 2021/04/21 19:45:33 by sashin           ###   ########.fr       */
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
		printf("\n\n\n\npos : %d, %d\n", info->pos.x, ++info->pos.y);
	else if (key == KEY_S)
		printf("\n\n\n\npos : %d, %d\n", info->pos.x, --info->pos.y);
	else if (key == KEY_A)
		printf("\n\n\n\npos : %d, %d\n", --info->pos.x, info->pos.y);
	else if (key == KEY_D)
		printf("\n\n\n\npos : %d, %d\n", ++info->pos.x, info->pos.y);
	else if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

// int		ft_calculate(t_info *info)
// {
	
// }

int		ft_run(char *cub, t_info info)		// 돌려보자
{
	draw_grid(&info);
	// ft_calculate(&info);

	mlx_key_hook(info.win.ptr, move_dot, &info);

	mlx_loop(info.mlx.ptr);
	return (0);
}

int			ft_load_cub(char *cub_file)
{
	int		fd;
	char	*line;
	int		gnl;
	
	fd = file_open(cub_file);
	check_extension(cub_file, ".cub", fd); // 파일 이름이 .cub인지 확인. 아니라면 닫고 끝내기.
	printf("\nOK, .cub file is valid!\n\n");

	while (1) // 여기서부터 파일 내용들을 파싱한다.
	{
		gnl = get_next_line(fd, &line);
		if (line[0] == 'R' && line[1] == ' ')
		{
			// 해상도 파싱, 해상도 boolean 체크.
		}
		free(line);
		if (gnl != 1)
			break ;
	}
	return (0);
}

t_info		ft_init(char *cub)				// 초기화!
{
	t_info	info;

	ft_load_cub(cub);
	
	info.pos.x = 35;
	info.pos.y = 35;
	info.pos.xd = 0;
	info.pos.yd = 0;
	info.pos.angle = 0;
	info.mlx.ptr = mlx_init();
	info.win.ptr = mlx_new_window(info.mlx.ptr, WIDTH, HEIGHT, "untitiled");

	return (info);
}

int		main(int argc, char **argv)
{
	t_info	info;
	if (argc == 1)
		printf("Please input a \'.cub\' file. - by sashin\n");
	else if (argc == 2)
	{
		info = ft_init(argv[1]);
		ft_run(argv[1], info);
	}
	else
		printf("Error: Invalid arguments - by sashin\n");
	return (0);
}
