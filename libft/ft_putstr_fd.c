/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:33:48 by sashin            #+#    #+#             */
/*   Updated: 2021/01/02 14:24:41 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putstr_fd() outputs the string 's' to the given file descriptor.
*/

void			ft_putstr_fd(char *s, int fd)
{
	int			idx;

	idx = 0;
	while (s[idx])
		write(fd, &s[idx++], 1);
}
