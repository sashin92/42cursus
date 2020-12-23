/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:58:02 by sashin            #+#    #+#             */
/*   Updated: 2020/12/23 10:31:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	idx;

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
	dest[idx + destlen] = 0;
	return (destlen >= destsize ? (srclen + destsize) : (destlen + srclen));
}
