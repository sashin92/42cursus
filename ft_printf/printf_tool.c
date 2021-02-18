/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:30:19 by sashin            #+#    #+#             */
/*   Updated: 2021/02/18 17:30:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_base_len(int num, int base)
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