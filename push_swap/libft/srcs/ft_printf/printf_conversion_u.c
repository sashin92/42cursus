/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:02:03 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:36:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*printf_conversion_u(va_list ap, t_flag *flags)
{
	long long		num;
	int				num_len;
	char			*val;

	num = va_arg(ap, unsigned int);
	if (flags->dot_sign == 1 && flags->precision >= 0)
		flags->zero_padding = ' ';
	if (flags->dot_sign == 1 && flags->precision == 0 && num == 0)
		return (val = ft_strdup(""));
	num_len = printf_base_len(num, 10);
	if (flags->precision > num_len)
		num_len = flags->precision;
	val = ft_calloc(num_len + 1, sizeof(char));
	if (!val)
		return (0);
	val = printf_itoa_base(num, val, num_len, "0123456789");
	return (val);
}
