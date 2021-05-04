/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:47:21 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:44:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_calloc allocate memory (size * count). and fill zero.
*/

void			*ft_calloc(size_t count, size_t size)
{
	void		*pt;
	size_t		idx;

	idx = 0;
	if (!(pt = (void *)malloc(count * size)))
		return (NULL);
	while (idx < (count * size))
		((char *)pt)[idx++] = 0;
	return (pt);
}
