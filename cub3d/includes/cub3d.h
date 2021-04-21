/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:59:04 by sashin            #+#    #+#             */
/*   Updated: 2021/04/21 19:14:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/errno.h>

# include "lib_sashin.h"
# include "keycode_mac.h"
# include "../mlx/mlx.h"

typedef struct	s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct	s_win
{
	void	*ptr;
}				t_win;

typedef struct	s_pos
{
	int		x;
	int		y;
	int		xd;
	int		yd;
	int		angle;
}				t_pos;

typedef struct	s_cub
{
	int		res_x;
	int		res_y;
	int		res;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sky;
	char	*floor;
	char	*ceilling;
}				t_cub;

typedef struct	s_info
{
	t_win		win;
	t_mlx		mlx;
	t_pos		pos;
	t_cub		cub;
}				t_info;





int			file_open(char *file);
void		check_extension(char *file, char *extension, int fd);





#endif