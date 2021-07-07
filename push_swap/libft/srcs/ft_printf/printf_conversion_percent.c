/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_percent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:32:37 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:36:07 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*printf_conversion_percent(void)
{
	char			*val;

	val = (char *)malloc(sizeof(char) * 2);
	if (!val)
		return (0);
	val[0] = '%';
	val[1] = '\0';
	return (val);
}
