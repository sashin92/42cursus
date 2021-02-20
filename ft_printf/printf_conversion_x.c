/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:31:16 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 14:27:24 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_x(va_list *ap, t_flag flags)
{
	long long		num;
	int				num_len;
	char			*val;

	num = va_arg(*ap, unsigned int);
	num_len = printf_base_len(num, 16);
	if (flags.precision > num_len)
		num_len = flags.precision;
	if (!(val = (char *)malloc(sizeof(char) * (num_len + 1))))
		return (0);
	val = printf_itoa_base(num, val, num_len, "0123456789abcdef");
	return (val);
}
