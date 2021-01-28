/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:24:56 by sashin            #+#    #+#             */
/*   Updated: 2021/01/28 21:44:52 by sashin           ###   ########.fr       */
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
	int			minus;
	int			width;
	int			precision;
	int			star;
}				t_flag;


int		ft_printf(const char *type, ...);



#endif
