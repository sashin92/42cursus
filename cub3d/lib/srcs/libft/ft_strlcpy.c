/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:57:38 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:45:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - ft_strlcpy() copies (size - 1) bytes from string src to string dest,
** and input '\0' in dest. return src length.
** - if size is 0, nothing happen.
** - dest & src overlap behavior is undefined.
*/

size_t			ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		src_length;
	size_t		idx;

	src_length = 0;
	idx = 0;
	while (src[src_length])
		++src_length;
	if (size > 0)
	{
		while ((size - 1 > idx) && src[idx])
		{
			dest[idx] = src[idx];
			++idx;
		}
		dest[idx] = '\0';
	}
	return (src_length);
}
