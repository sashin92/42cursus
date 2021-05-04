/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:29:07 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:43:09 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*printf_conversion_d(va_list ap, t_flag *flags)
{
	long long	num;
	int			num_len;
	char		*val;

	num = va_arg(ap, int);
	if (flags->dot_sign == 1 && flags->precision >= 0)
		flags->zero_padding = ' ';
	if (flags->dot_sign == 1 && flags->precision == 0 && num == 0)
		return (val = ft_strdup(""));
	num_len = printf_base_len(num, 10);
	if (flags->precision > num_len)
		num_len = flags->precision;
	if (num < 0)
		++num_len;
	if (!(val = ft_calloc(num_len + 1, sizeof(char))))
		return (0);
	if (num < 0)
	{
		val[0] = '-';
		num = num * (-1);
	}
	val = printf_itoa_base(num, val, num_len, "0123456789");
	return (val);
}
