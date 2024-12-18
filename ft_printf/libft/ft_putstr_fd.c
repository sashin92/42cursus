/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:33:48 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 22:10:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putstr_fd() outputs the string 's' to the given file descriptor.
*/

void			ft_putstr_fd(char *s, int fd)
{
	int			idx;

	if (s == 0)
		return ;
	idx = 0;
	while (s[idx])
		write(fd, &s[idx++], 1);
}
