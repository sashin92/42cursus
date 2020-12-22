/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:57:38 by sashin            #+#    #+#             */
/*   Updated: 2020/12/22 16:55:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	idx;

	count = 0;
	idx = 0;
	while (src[count])
		++count;
	if (size > 0)
	{
		while ((size - 1 > idx) && src[idx])
		{
			dest[idx] = src[idx];
			++idx;
		}
		dest[idx] = 0;
	}
	return (count);
}
