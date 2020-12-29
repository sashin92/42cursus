/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:37:24 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 17:27:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				atoi_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			idx;
	int			sign;
	int			val;

	idx = 0;
	sign = 1;
	val = 0;
	while (atoi_isspace(str[idx]))
		++idx;
	if (str[idx] == '-')
	{
		sign *= -1;
		++idx;
	}
	else if (str[idx] == '+')
		++idx;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		val = (val * 10) + (str[idx] - '0');
		++idx;
	}
	return (sign * val);
}
