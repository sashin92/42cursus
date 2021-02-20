/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:30:19 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 14:41:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_base_len(long long num, int base)
{
	int			len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / base;
		++len;
	}
	return (len);
}

char		*printf_itoa_base(long long num, char *val, int num_len, char *base)
{
	val[num_len] = '\0';
	while (--num_len >= 0 && val[num_len] != '-')
	{
		val[num_len] = base[num % 16];
		num = num / 16;
	}
	return (val);
}
