/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:36:34 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 14:43:09 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd() outputs the integer ’n’ to the given file descriptor.
*/

void			ft_putnbr_fd(int n, int fd)
{
	char		val;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	val = (n % 10) + '0';
	if (n >= 10)
	{
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	write(fd, &val, 1);
}
