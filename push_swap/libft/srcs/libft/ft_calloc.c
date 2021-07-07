/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:47:21 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:52:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_calloc allocate memory (size * count). and fill zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void		*pt;
	size_t		idx;

	idx = 0;
	pt = (void *)malloc(count * size);
	if (!pt)
		return (NULL);
	while (idx < (count * size))
		((char *)pt)[idx++] = 0;
	return (pt);
}
