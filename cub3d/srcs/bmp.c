/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:12:14 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 15:11:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			bmp_pixel(t_info *s, int fd)
{
	int				i;
	int				height;
	unsigned char	buf[4];

	height = s->win.res_x * (s->win.res_y - 1);
	while (height >= 0)
	{
		i = 0;
		while (i < s->win.res_x)
		{
			buf[0] = s->img.adr[height + i] % 256;
			buf[1] = s->img.adr[height + i] / 256 % 256;
			buf[2] = s->img.adr[height + i] / 256 / 256 % 256;
			buf[3] = 0;
			write(fd, buf, 4);
			i++;
		}
		height -= s->win.res_x;
	}
}

static void			bmp_infoheader(t_info *s, int fd)
{
	unsigned char	header[40];

	ft_memset(header, 0, 40);
	header[0] = 40;
	header[4] = s->win.res_x % 256;
	header[5] = s->win.res_x / 256 % 256;
	header[6] = s->win.res_x / 256 / 256 % 256;
	header[7] = s->win.res_x / 256 / 256 / 256;
	header[8] = s->win.res_y % 256;
	header[9] = s->win.res_y / 256 % 256;
	header[10] = s->win.res_y / 256 / 256 % 256;
	header[11] = s->win.res_y / 256 / 256 / 256;
	header[12] = 1;
	header[14] = 32;
	write(fd, header, 40);
}

static void			bmp_fileheader(t_info *s, int fd)
{
	int				bfsize;
	unsigned char	header[14];

	ft_memset(header, 0, 14);
	header[0] = 'B';
	header[1] = 'M';
	bfsize = s->win.res_x * s->win.res_y * 4 + (40 + 14);
	header[2] = bfsize % 256;
	header[3] = bfsize / 256 % 256;
	header[4] = bfsize / 256 / 256 % 256;
	header[5] = bfsize / 256 / 256 / 256;
	header[10] = 40 + 14;
	write(fd, header, 14);
}

int					bmp(t_info *s, char *cub)
{
	int				fd;

	s->mlx.ptr = mlx_init();
	load_cub(cub, s);
	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.res_x, s->win.res_y);
	s->img.adr = (int *)mlx_get_data_addr(s->img.ptr, &s->img.bpp,
										&s->img.sl, &s->img.end);
	raycasting(s);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	bmp_fileheader(s, fd);
	bmp_infoheader(s, fd);
	bmp_pixel(s, fd);
	close(fd);
	free(s->img.ptr);
	free(s->img.adr);
	printf("created \"bitmap.bmp\" file\n");
	return (0);
}