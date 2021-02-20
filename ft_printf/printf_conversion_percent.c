/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_percent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:32:37 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 22:05:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_percent(void)
{
	char			*val;

	if (!(val = (char *)malloc(sizeof(char) * 2)))
		return (0);
	val[0] = '%';
	val[1] = '\0';
	return (val);
}
