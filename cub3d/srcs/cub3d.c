/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:20 by sashin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/20 21:26:03 by sashin           ###   ########.fr       */
=======
/*   Updated: 2021/05/20 02:37:08 by sashin           ###   ########.fr       */
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			loop(t_info *info)
{
<<<<<<< HEAD
	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.res_x,
							info->win.res_y);
=======
	info->img.ptr = mlx_new_image(info->mlx.ptr,
								info->win.res_x, info->win.res_y);
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
	info->img.adr = (int *)mlx_get_data_addr(info->img.ptr, &info->img.bpp,
										&info->img.size_l, &info->img.endian);
	raycasting(info);
	mlx_put_image_to_window(info->mlx.ptr, info->win.ptr, info->img.ptr, 0, 0);
	free(info->img.ptr);
	free(info->img.adr);
	info->img.ptr = NULL;
	info->img.adr = NULL;
	return (0);
}

int			load_cub(char *cub_file, t_info *info)
{
	int		fd;
	char	*line;
	int		gnl;
<<<<<<< HEAD
	int		i;

	fd = file_open(cub_file);
	check_extension(cub_file, ".cub", fd);
=======

	fd = file_open(cub_file);
	check_extension(cub_file, ".cub", fd); // 파일 이름이 .cub인지 확인
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
	printf("\nOK, .cub file is valid!\n\n");
	while (1)
	{
		gnl = get_next_line(fd, &line);
<<<<<<< HEAD
		check_cubline(info, line);
=======
		check_str(line, info);
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
		free(line);
		if (info->err < 0)
			printf("Error\n");
		if (gnl != 1)
			break ;
	}
	printf("%d x %d\n", info->win.res_x, info->win.res_y);
	i = 0;
	while (i < info->map.y)
		printf("%s\n", info->map.xy[i++]);
	printf("map.x : %d, map.y : %d, pos:[%f,%f]\n", info->map.x, info->map.y,
												info->pos.x, info->pos.y);
	return (0);
}

int			run(char *cub, t_info *info)
{
	info->mlx.ptr = mlx_init();
	load_cub(cub, info);
<<<<<<< HEAD
	info->win.ptr = mlx_new_window(info->mlx.ptr, info->win.res_x,
									info->win.res_y, "cub3d");
=======
	info->win.ptr = mlx_new_window(info->mlx.ptr,
								info->win.res_x, info->win.res_y, "UI");
>>>>>>> 68ef52ef5209690f063114a3fecfb17fa7a43f6d
	write(1, "done\n", 5);
	loop(info);
	mlx_hook(info->win.ptr, 2, 0, put_key, info);
	mlx_loop(info->mlx.ptr);
	return (0);
}

void		init(t_info *info)
{
	info->mlx.ptr = NULL;
	info->win.ptr = NULL;
	info->win.res_x = 0;
	info->win.res_y = 0;
	info->cub.north = NULL;
	info->cub.south = NULL;
	info->cub.east = NULL;
	info->cub.west = NULL;
	info->cub.sprite = NULL;
	info->cub.floor = 0;
	info->cub.ceilling = 0;
	info->map.xy = NULL;
	info->map.x = 0;
	info->map.y = 0;
	info->img.ptr = NULL;
	info->img.adr = NULL;
	info->img.width = 0;
	info->img.height = 0;
	info->pos.x = 0;
	info->pos.y = 0;
	info->dir.angle = 0;
	info->err = 0;
}

int			main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		printf("Please input a \".cub\" file. - by sashin\n");
	else if (argc == 2)
	{
		init(&info);
		run(argv[1], &info);
	}
	else
		printf("Error: Too much arguments - by sashin\n");
	return (0);
}
