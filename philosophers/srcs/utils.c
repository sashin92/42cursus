/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:18:50 by sashin            #+#    #+#             */
/*   Updated: 2021/11/23 18:55:28 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_atoi_nosign(char *str)
{
	long long	val;
	int			i;

	if (str == NULL || str[0] < '0' || str[0] > '9')
		return (-1);
	val = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (val * (long long)10) + (long long)(str[i] - '0');
		if (val > 2147483647)
			return (-1);
		++i;
	}
	if (str[i] != '\0')
		return (-1);
	return (val);
}