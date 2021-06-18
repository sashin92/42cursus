/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:14:51 by sashin            #+#    #+#             */
/*   Updated: 2021/06/18 18:20:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		ft_atoi(char *s)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (*s == '-')
	{
		sign *= -1;
		++s;
	}
	while (ft_isdigit(*s))
	{
		ret = ret * 10 + *s - '0';
		++s;
	}
	if (*s != '\0')
		return (-1);
	return (ret * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		++len;
	write(1, s, len);
}

int		ft_power(int num, int pow)
{
	int		i;
	int		ret;

	if (pow == 0)
		return (1);
	else if (pow == 1)
		return (num);
	i = 1;
	ret = num;
	while (i < pow)
	{
		ret = ret * num;
		++i;
	}
	return (ret);
}
