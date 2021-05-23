/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:30:20 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 16:59:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void		create_sprite_map(t_info *s)
// {
// 	char	**tmp_map;
// 	char	*tmp_str;
// 	int		i;

// 	tmp_str = (char *)malloc(sizeof(char) * s->map.x + 1);
// 	i = 0;
// 	while (i < s->map.x)
// 		tmp_str[i++] = '0';
// 	tmp_str[i] = '\0';
// 	tmp_map = (char **)malloc(sizeof(char *) * s->map.y);
// 	i = 0;
// 	while (i < s->map.y)
// 		tmp_map[i++] = ft_strdup(tmp_str);
// 	s->vis.xy = tmp_map;
// }

int			loop(t_info *s)
{
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.res_x, s->win.res_y);
	s->img.adr = (int *)mlx_get_data_addr(s->img.ptr, &s->img.bpp,
										&s->img.sl, &s->img.end);
	// create_sprite_map(s);
	raycasting(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
	s->img.ptr = NULL;
	s->img.adr = NULL;
	return (0);
}

int			load_cub(char *cub_file, t_info *s)
{
	int		fd;
	char	*line;
	int		gnl;
	int		i;

	fd = file_open(cub_file);
	check_extension(cub_file, ".cub", fd);
	printf("\nOK, .cub file is valid!\n\n");
	while (1)
	{
		gnl = get_next_line(fd, &line);
		check_cubline(s, line);
		free(line);
		if (s->err < 0)
			printf("Error\n");
		if (gnl != 1)
			break ;
	}
	printf("%d x %d\n", s->win.res_x, s->win.res_y);
	i = 0;
	while (i < s->map.y)
		printf("%s\n", s->map.xy[i++]);
	printf("map.x : %d, map.y : %d, pos:[%f,%f]\n", s->map.x, s->map.y,
												s->pos.x, s->pos.y);
	return (0);
}

int			run(char *cub, t_info *s, char *bmp)
{
	(void)bmp;
	s->mlx.ptr = mlx_init();
	load_cub(cub, s);
	s->win.ptr = mlx_new_window(s->mlx.ptr, s->win.res_x,
									s->win.res_y, "cub3d");
	write(1, "done\n", 5);
	loop(s);
	mlx_hook(s->win.ptr, 2, 0, put_key, s);
	mlx_loop(s->mlx.ptr);
	return (0);
}

void		init(t_info *s)
{
	s->mlx.ptr = NULL;
	s->win.ptr = NULL;
	s->win.res_x = 0;
	s->win.res_y = 0;
	s->cub.north = NULL;
	s->cub.south = NULL;
	s->cub.east = NULL;
	s->cub.west = NULL;
	s->cub.sprite = NULL;
	s->cub.floor = 0;
	s->cub.ceilling = 0;
	s->spr = NULL;
	s->map.xy = NULL;
	s->map.x = 0;
	s->map.y = 0;
	s->img.ptr = NULL;
	s->img.adr = NULL;
	s->pos.x = 0;
	s->pos.y = 0;
	s->dir.angle = 0;
	s->err = 0;
}

int			main(int argc, char **argv)
{
	t_info	s;

	if (argc == 1)
		printf("Please input a \".cub\" file. - by sashin\n");
	else if (argc == 2)
	{
		init(&s);
		run(argv[1], &s, 0);
	}
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
	{
		init(&s);
		bmp(&s, argv[1]);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
