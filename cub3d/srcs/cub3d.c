/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:20 by sashin            #+#    #+#             */
/*   Updated: 2021/06/09 21:53:34 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int			draw_player(t_info *s)
// {
// 	t_mini_img	*fi;
// 	double	i;

// 	fi = &(s->mini_img);
// 	//draw_circle(s, 1, s->mini.bsize / 6, s->mini.ppx, s->mini.ppy, 0x0000ff);
// 	i = -1;
// 	while (++i < s->mini.bsize / 3)
// 		draw_pixel(s->mini.ppx + i * s->mini.dx, s->mini.ppy + i * s->mini.dy, 0x0000ff, fi);
// 	return (1);
// }


static void		set_block_color(char block, int *c)
{
	if (block == '1')
		*c = 0x777777;
	else if (block == ' ')
		*c = 0x000000;
	else
	*c = 0xffffff;
}

void			draw_pixel(int x, int y, int color, t_mini_img *fi)
{
	fi->adr[y * (fi->sl / (fi->bpp / 8)) + x] = color;
}

void			draw_rectangle(t_info *a, int sx, int sy, int x, int y, int color)
{
	t_mini_img	*fi;
	int		i;
	int		j;

	fi = &(a->mini_img);
	i = -1;
	j = -1;
	while (++j < sy)
	{
		while (++i < sx)
			draw_pixel(x + i, y + j, color, fi);
		i = -1;
	}
}

void	draw_minimap(t_info *s)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	j = -1;
	c = 0;
	while (++j < s->map.y)
	{
		while (++i < s->map.x)
		{
			set_block_color(s->map.yx[j][i], &c);
			draw_rectangle(s, s->mini.bsize - 3, s->mini.bsize - 3, s->mini.bsize * i, s->mini.bsize * j, c);
		}
		i = -1;
	}
}

int			loop(t_info *s)
{
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win[0].res_x, s->win[0].res_y);
	s->img.adr = (int *)mlx_get_data_addr(s->img.ptr, &s->img.bpp,
										&s->img.sl, &s->img.end);
	s->mini_img.ptr = mlx_new_image(s->mlx.ptr, s->mini.mapsize, s->mini.mapsize);
	s->mini_img.adr = (int *)mlx_get_data_addr(s->mini_img.ptr, &s->mini_img.bpp,
										&s->mini_img.sl, &s->mini_img.end);


	draw_minimap(s);
	//draw_player(s);
	raycasting(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win[0].ptr, s->img.ptr, 0, 0);
	mlx_put_image_to_window(s->mlx.ptr, s->win[1].ptr, s->mini_img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
	s->img.ptr = NULL;
	s->img.adr = NULL;
	free(s->mini_img.ptr);
	free(s->mini_img.adr);
	s->mini_img.ptr = NULL;
	s->mini_img.adr = NULL;
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
	if (s->err < 0)
		return (check_error(s->err));
	((s->map.x >= s->map.y) && (s->mini.blocks = s->map.x)) || ((s->map.x < s->map.y) && (s->mini.blocks = s->map.y));
	s->mini.mapsize = 700;
	s->mini.bsize = s->mini.mapsize / s->mini.blocks;
	s->mini.ppx = s->pos.x * s->mini.bsize;
	s->mini.ppy = s->pos.y * s->mini.bsize;
	s->win[0].ptr = mlx_new_window(s->mlx.ptr, s->win[0].res_x,
									s->win[0].res_y, "cub3d");
	s->win[1].ptr = mlx_new_window(s->mlx.ptr, s->mini.mapsize, s->mini.mapsize, "minimap");
	write(1, "done\n", 5);
	loop(s);
	mlx_hook(s->win[0].ptr, 2, 0, put_key, s);
	mlx_hook(s->win[0].ptr, 17, 0, ft_destroy, s);
	mlx_loop(s->mlx.ptr);
	return (0);
}

static void	init(t_info *s)
{
	s->mlx.ptr = NULL;
	s->win[0].ptr = NULL;
	s->win[0].res_x = 1000;
	s->win[0].res_y = 600;
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

	s->mini.mapsize = 700;
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
