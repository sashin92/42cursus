/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:20 by sashin            #+#    #+#             */
/*   Updated: 2021/06/10 21:07:33 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			loop(t_info *s)
{
	mlx_clear_window(s->mlx.ptr, s->win.ptr);
	ft_bzero(s->img.adr, sizeof(int) * s->win.res_x * s->win.res_y);
	ft_bzero(s->mini_img.adr, sizeof(int) * s->mini.mapsize * s->mini.mapsize);
	draw_minimap(s);
	raycasting(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->mini_img.ptr, 0, 0);
	return (0);
}

static void	load_cub(char *cub_file, t_info *s)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = file_open(cub_file);
	check_extension(cub_file, ".cub", fd);
	while (s->err == 0)
	{
		gnl = get_next_line(fd, &line);
		check_cubline(s, line);
		free(line);
		if (gnl != 1)
			break ;
	}
	map_sort(s);
	check_map_inside(s);
	check_map_outside(s);
	if (s->err < 0)
		return ;
	check_s(s);
	if (s->err < 0)
		return ;
	close(fd);
	return ;
}

static int	run(char *cub, t_info *s)
{
	s->mlx.ptr = mlx_init();
	load_cub(cub, s);
	ft_minimap(s);
	if (s->err < 0)
		return (check_error(s->err));
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.res_x,
									s->win.res_y, "cub3d");
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.res_x, s->win.res_y);
	s->img.adr = (int *)mlx_get_data_addr(s->img.ptr, &s->img.bpp,
										&s->img.sl, &s->img.end);
	s->mini_img.ptr = mlx_new_image(s->mlx.ptr, s->mini.mapsize,
									s->mini.mapsize);
	s->mini_img.adr = (int *)mlx_get_data_addr(s->mini_img.ptr,
						&s->mini_img.bpp, &s->mini_img.sl, &s->mini_img.end);
	loop(s);
	mlx_hook(s->win.ptr, 2, 0, put_key, s);
	mlx_hook(s->win.ptr, 17, 0, ft_destroy, s);
	mlx_loop(s->mlx.ptr);
	return (0);
}

static void	init(t_info *s)
{
	s->mlx.ptr = NULL;
	s->win.ptr = NULL;
	s->win.res_x = 1600;
	s->win.res_y = 900;
	s->cub.north = NULL;
	s->cub.south = NULL;
	s->cub.east = NULL;
	s->cub.west = NULL;
	s->cub.floor = -1;
	s->cub.ceilling = -1;
	s->map.yx = NULL;
	s->map.x = 0;
	s->map.y = 0;
	s->img.ptr = NULL;
	s->img.adr = NULL;
	s->pos.x = 0;
	s->pos.y = 0;
	s->dir.angle = 0;
	s->err = 0;
	s->flag = 0;
	s->mini.blocks = 0;
	s->mini.bsize = 0;
	s->mini.ppx = 0;
	s->mini.ppy = 0;
}

int			main(int argc, char **argv)
{
	t_info	s;

	if (argc == 1)
		printf("Please input a \".cub\" file.\n");
	else if (argc == 2)
	{
		init(&s);
		run(argv[1], &s);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
