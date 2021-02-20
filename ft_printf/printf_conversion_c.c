/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:45:49 by sashin            #+#    #+#             */
/*   Updated: 2021/02/21 00:30:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_c(va_list ap, t_flag *flags)
{
	char			c;
	char			*val;

	c = va_arg(ap, int);
	if (flags->dot_sign == 1 && flags->precision >= 0)
		flags->zero_padding = ' ';
	if (!(val = (char *)malloc(sizeof(char) * 2)))
		return (0);
	if (c == '\0')
		flags->null_char = 1;
	val[0] = c;
	val[1] = '\0';
	return (val);
}
