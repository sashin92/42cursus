/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:59:04 by sashin            #+#    #+#             */
/*   Updated: 2021/05/23 16:48:48 by sashin           ###   ########.fr       */
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

# define FOV 66.7
# define EPS 1e-06

# define MOVE_SPD 0.05
# define ROTATE_SPD 5

# define NORTH 11
# define SOUTH 12
# define EAST 13
# define WEST 14

# define HIT_VERTICAL 1
# define HIT_HORIZON 2

typedef struct	s_mlx
{
	void		*ptr;
}				t_mlx;

typedef struct	s_win
{
	void		*ptr;
	int			res_x;
	int			res_y;
}				t_win;

typedef struct	s_cub
{
	int			*north;
	int			*south;
	int			*east;
	int			*west;
	int			*sprite;
	int			floor;
	int			ceilling;
}				t_cub;

typedef struct	s_spr
{
	double		x;
	double		y;
	double		dist;
	double		th;
}				t_spr;

typedef struct	s_map
{
	char		**xy;
	int			x;
	int			y;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	int			*adr;
	int			w;
	int			h;
	int			sl;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_dir
{
	double		angle;
}				t_dir;

typedef struct	s_ray
{
	double		angle;
	double		x;
	double		y;
	double		ystep;
	double		xstep;
	int			i;
	double		f;
	double		g;
	int			cx;
	int			cy;
}				t_ray;

typedef struct	s_hit
{
	double		key;
	double		x;
	double		y;
	double		dir;
	double		dist;
}				t_hit;

typedef struct	s_info
{
	t_mlx		mlx;
	t_win		win;
	t_cub		cub;
	t_map		map;
	t_img		img;
	t_pos		pos;
	t_dir		dir;
	int			err;
	t_ray		ray;
	t_hit		hit;
	t_spr		*spr;
	int			spr_count;
}				t_info;

/*
** cub3d.c
*/
int			loop(t_info *s);
int			load_cub(char *cub_file, t_info *s);

/*
** check_files.c
*/
int				file_open(char *file);
void			check_extension(char *file, char *extension, int fd);
int				ismap(char *line);
void			check_cubline(t_info *s, char *line);

/*
** parse.c
*/
int				parse_resolution(char *line, t_info *s);
int				parse_rgb(char *line, int *rgb);
int				parse_map(char *line, t_info *s);
int				parse_texture(t_info *s, char *line, int **texture);

/*
** error.c
*/
int				err_sentence(int err);

/*
** ray.c
*/
void			raycasting(t_info *s);

/*
** ray_tools.c
*/
double			deg_to_rad(double deg);
int				rad_step(double rad);
double			l2dist(double x0, double y0, double x1, double y1);
void			ray_hit_v(t_info *s);
void			ray_hit_h(t_info *s);

/*
** draw.c
*/
void			draw_background(t_info *s);
void			draw_wall(t_info *s, double fov_v, int i);
void			draw_sprite(t_info *s, double fov_v, int i);

/*
** control.c
*/
int				put_key(int key, t_info *s);


/*
** sprite.c
*/
void			ray_touch_sprite(t_info *s);

/*
** bmp.c
*/
int				bmp(t_info *s, char *cub);

#endif
