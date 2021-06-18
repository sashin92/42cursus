/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:04:53 by sashin            #+#    #+#             */
/*   Updated: 2021/06/18 17:34:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static char		*itoa_is_zero(void)
{
	char		*num;

	if (!(num = (char *)malloc(sizeof(char) * (2))))
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char		*itoa_is_positive(int n, int digit)
{
	int			idx;
	char		*num;

	if (!(num = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	idx = digit;
	while (idx > 0)
	{
		num[idx - 1] = (n % 10) + '0';
		n = n / 10;
		idx--;
	}
	num[digit] = '\0';
	return (num);
}

static char		*itoa_is_negative(int n, int digit)
{
	int			idx;
	char		*num;

	if (!(num = (char *)malloc(sizeof(char) * (digit + 2))))
		return (NULL);
	idx = digit;
	if (n == -2147483648)
	{
		num[idx--] = '8';
		n = n / 10;
	}
	n = n * (-1);
	num[0] = '-';
	while (idx > 0)
	{
		num[idx] = (n % 10) + '0';
		n = n / 10;
		idx--;
	}
	num[digit + 1] = '\0';
	return (num);
}

char			*ft_itoa(int n)
{
	char		*num;
	int			cp_n;
	int			digit;

	digit = 0;
	cp_n = n;
	while (cp_n != 0)
	{
		cp_n = cp_n / 10;
		++digit;
	}
	if (n < 0)
		num = itoa_is_negative(n, digit);
	else if (n == 0)
		num = itoa_is_zero();
	else
		num = itoa_is_positive(n, digit);
	return (num);
}
