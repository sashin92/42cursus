/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:58:02 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 23:07:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - ft_strlcat() appends (destsize - destlen - 1) bytes
** from string src to string dest, and input '\0' in dest. return src length.
** - dest & src overlap behavior is undefined.
*/

size_t			ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t		destlen;
	size_t		srclen;
	size_t		idx;

	destlen = 0;
	srclen = 0;
	idx = 0;
	while (src[srclen])
		++srclen;
	while (dest[destlen])
		++destlen;
	while ((destsize > idx + destlen + 1) && src[idx])
	{
		dest[idx + destlen] = src[idx];
		++idx;
	}
	dest[idx + destlen] = '\0';
	return (destlen >= destsize ? (srclen + destsize) : (destlen + srclen));
}
