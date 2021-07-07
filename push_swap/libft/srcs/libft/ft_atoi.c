/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:37:24 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:50:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - ft_atoi() converts string_number to int.
** - out of range of int is undefined.
*/

static int	atoi_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static unsigned long long	atoi_check_over(unsigned long long val, int sign)
{
	if (val > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (val);
}

int	ft_atoi(const char *str)
{
	int						idx;
	int						sign;
	unsigned long long		val;

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
		if (val > 9223372036854775807)
			break ;
	}
	val = atoi_check_over(val, sign);
	return (sign * val);
}
