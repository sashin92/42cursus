/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:59:04 by sashin            #+#    #+#             */
/*   Updated: 2021/05/14 16:20:58 by sashin           ###   ########.fr       */
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

# define FOV 66
# define FOV_2 FOV / 2

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
	double		x;
	double		y;
	double		v;
	double		h;
	int			i;
}				t_ray;

typedef struct	s_hit
{
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

typedef struct	s_img
{
	void			*ptr;
	char			*adr;
	int				fsh;
}				t_img;

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

/*
** parse.c
*/
int		parse_resolution(char *line, t_info *info);
int		parse_rgb(char *line, int *rgb);
int		parse_map(char *line, t_info *info); 

/*
** error.c
*/
int		err_sentence(int err);


/*
** ray.c
*/
void		raycasting(t_info *info);


#endif