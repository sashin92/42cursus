/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:34:46 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:45:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - ft_putendl_fd() outputs the string 's' to the given file descriptor,
** followed by a newline.
*/

void			ft_putendl_fd(char *s, int fd)
{
	int			idx;

	idx = 0;
	while (s[idx])
		write(fd, &s[idx++], 1);
	write(fd, "\n", 1);
}
