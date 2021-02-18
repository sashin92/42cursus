/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:29:07 by sashin            #+#    #+#             */
/*   Updated: 2021/02/18 14:29:14 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_conversion_d(va_list *ap, t_flag flags)
{
	int			num;
	int			num_len;
	char		*val;

	num = va_arg(*ap, int);
	val = ft_itoa(num);
	printf_print(val, flags);

	free(val);
	return (1);
}