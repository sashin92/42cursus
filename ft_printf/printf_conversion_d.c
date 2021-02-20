/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:29:07 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 13:02:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_d(va_list *ap, t_flag flags)
{
	int			num;
	int			num_len;
	char		*val;

	num = va_arg(*ap, int);
	num_len = printf_base_len(num, 10);
	if (flags.precision > num_len)
		num_len = flags.precision;
	if (num < 0)
		++num_len;
	if (!(val = (char *)malloc(sizeof(char) * (num_len + 1))))
		return (0);
	if (num < 0)
	{
		val[0] = '-';
		num = num * (-1);
	}
	val[num_len] = '\0';
	while (--num_len >= 0 && val[num_len] != '-')
	{
		val[num_len] = num % 10 + '0';
		num = num / 10;
	}
	return (val);
}
