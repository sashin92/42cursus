/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:45:49 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 14:58:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_c(va_list *ap)
{
	char			c;
	char			*val;

	c = va_arg(*ap, int);
	if (!(val = (char *)malloc(sizeof(char) * 2)))
		return (0);
	val[0] = c;
	val[1] = '\0';
	return (val);
}
