/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:31:35 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 18:19:31 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putchar_fd() outputs the character ’c’ to the given file descriptor.
*/

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
