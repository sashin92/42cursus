/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_x_large.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:31:16 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:43:21 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*printf_conversion_x_large(va_list ap, t_flag *flags)
{
	long long		num;
	int				num_len;
	char			*val;

	num = va_arg(ap, unsigned int);
	if (flags->dot_sign == 1 && flags->precision >= 0)
		flags->zero_padding = ' ';
	if (flags->dot_sign == 1 && flags->precision == 0 && num == 0)
		return (val = ft_strdup(""));
	num_len = printf_base_len(num, 16);
	if (flags->precision > num_len)
		num_len = flags->precision;
	if (!(val = ft_calloc(num_len + 1, sizeof(char))))
		return (0);
	val = printf_itoa_base(num, val, num_len, "0123456789ABCDEF");
	return (val);
}
