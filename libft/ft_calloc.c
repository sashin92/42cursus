/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:47:21 by sashin            #+#    #+#             */
/*   Updated: 2020/12/28 13:39:00 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t count, size_t size)
{
	void		*pt;
	size_t		idx;

	idx = 0;
	if (!(pt = malloc(count * size)))
		return (0);
	while (idx < (count * size))
		((char *)pt)[idx++] = 0;
	return (pt);
}
