/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_init_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:42:12 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:33:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	printf_init_flags(t_flag *flags)
{
	flags->minus_sign = 0;
	flags->plus_sign = 0;
	flags->sharp_sign = 0;
	flags->space_char = 0;
	flags->dot_sign = 0;
	flags->null_char = 0;
	flags->zero_padding = ' ';
	flags->star_sign = 0;
	flags->precision = 0;
	flags->width = 0;
}
