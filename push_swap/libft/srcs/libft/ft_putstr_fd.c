/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:33:48 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:55:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_putstr_fd() outputs the string 's' to the given file descriptor.
*/

void	ft_putstr_fd(char *s, int fd)
{
	int			len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
}
