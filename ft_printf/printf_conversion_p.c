/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:27:11 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 14:27:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_p(va_list *ap, t_flag flags)
{
	long long		num;
	int				num_len;
	char			*temp;
	char			*val;

	num = va_arg(*ap, unsigned long long);
	num_len = printf_base_len(num, 16);
	if (flags.precision > num_len)
		num_len = flags.precision;
	if (!(temp = (char *)malloc(sizeof(char) * (num_len + 1))))
		return (0);
	temp = printf_itoa_base(num, temp, num_len, "0123456789abcdef");
	val = ft_strjoin("0x", temp);
	return (val);
}
