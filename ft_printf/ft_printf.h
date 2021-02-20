/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:24:56 by sashin            #+#    #+#             */
/*   Updated: 2021/02/21 01:02:04 by sashin           ###   ########.fr       */
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
	int			dot_sign;
	int			null_char;
	int			zero_padding;
	int			width;
	int			precision;
}				t_flag;

int				ft_printf(const char *format, ...);

void			printf_check_flags(char **form, t_flag *flags);
void			printf_check_width(char **form, va_list ap, t_flag *flags);
void			printf_check_precision(char **form, va_list ap, t_flag *flags);

void			printf_init_flags(t_flag *flags);

char			*printf_conversion_d(va_list ap, t_flag *flags);
char			*printf_conversion_u(va_list ap, t_flag *flags);
char			*printf_conversion_x(va_list ap, t_flag *flags);
char			*printf_conversion_x_large(va_list ap, t_flag *flags);

char			*printf_conversion_p(va_list ap, t_flag *flags);

char			*printf_conversion_percent(void);

char			*printf_conversion_c(va_list ap, t_flag *flags);
char			*printf_conversion_s(va_list ap, t_flag *flags);

int				printf_print(char *val, t_flag flags);

int				printf_base_len(long long num, int base);
int				printf_atoi(char **form);
char			*printf_itoa_base(long long num, char *val, int num_len,
									char *base);
void			printf_putchar_padding(t_flag flags, int *val_len);
#endif
