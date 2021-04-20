/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:59:04 by sashin            #+#    #+#             */
/*   Updated: 2021/04/20 14:21:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "lib_sashin.h"
# include "keycode_mac.h"
# include "../mlx/mlx.h"

typedef struct	s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct	s_win
{
	int		x;
	int		y;
	void	*ptr;
}				t_win;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

#endif