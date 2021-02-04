/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:24:56 by sashin            #+#    #+#             */
/*   Updated: 2021/02/04 11:37:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft/libft.h"

typedef struct	s_flag
{
	int			minus_sign;
	int			plus_sign;
	int			star_sign;
	int			space_char;
	int			sharp_sign;
	int			zero_padding;
	int			width;
	int			precision;
}				t_flag;


int		ft_printf(const char *format, ...);



#endif
