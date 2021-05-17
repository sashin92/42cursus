/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:59:04 by sashin            #+#    #+#             */
/*   Updated: 2021/05/18 02:24:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/errno.h>

# include "../lib/includes/lib_sashin.h"
# include "keycode_mac.h"
# include "../mlx/mlx.h"

# define FOV 10
# define EPS 1e-06


# define HIT_VERTICAL 1
# define HIT_HORIZON 2

typedef struct	s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct	s_win
{
	void	*ptr;
	int		res_x;
	int		res_y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	int				*adr;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_dir
{
	double		x;
	double		y;
	double		angle;
}				t_dir;

typedef struct	s_ray
{
	double		angle;
	double		x;
	double		y;
	double		v;
	double		h;
	int			i;
}				t_ray;

typedef struct	s_hit
{
	double		key;
	double		x;
	double		y;
	double		d;
}				t_hit;

typedef struct	s_map
{
	char		**xy;
	int			x;
	int			y;
	int			spr;
}				t_map;

typedef struct	s_cub
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sky;
	char	*sprite;
	int		floor;
	int		ceilling;
}				t_cub;

typedef struct	s_stack
{
	double		x;
	double		y;
	double		d;
}				t_stack;



typedef struct	s_info
{
	int			err;
	t_win		win;
	t_mlx		mlx;
	int			rgb;
	t_pos		pos;
	t_dir		dir;
	t_ray		ray;
	t_hit		hit;
	t_map		map;
	t_cub		cub;
	t_stack		*stack;
	t_img		img;
}				t_info;




/*
** check_files.c
*/
int			file_open(char *file);
void		check_extension(char *file, char *extension, int fd);
int			ismap(char *line);

/*
** parse.c
*/
int		parse_resolution(char *line, t_info *info);
int		parse_rgb(char *line, int *rgb);
int		parse_map(char *line, t_info *info); 
int		parse_path(char *line, char **texture);

/*
** error.c
*/
int		err_sentence(int err);


/*
** ray.c
*/
void		raycasting(t_info *info);


/*
** draw.c
*/
int		draw_grid(t_info *info);


#endif