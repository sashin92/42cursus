/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:58:02 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 12:03:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - ft_strlcat() appends (destsize - destlen - 1) bytes
** from string src to string dest, and input '\0' in dest. return src length.
** - dest & src overlap behavior is undefined.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t		srclen;
	size_t		destlen;
	size_t		idx;
	size_t		ret;

	srclen = 0;
	destlen = 0;
	idx = 0;
	while (src[srclen])
		++srclen;
	while (dest[destlen] && destsize > destlen)
		++destlen;
	while ((destsize > idx + destlen + 1) && src[idx])
	{
		dest[idx + destlen] = src[idx];
		++idx;
	}
	if (destsize > destlen)
	{
		ret = destlen + srclen;
		dest[idx + destlen] = '\0';
	}
	else
		ret = srclen + destsize;
	return (ret);
}
