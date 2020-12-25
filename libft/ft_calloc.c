/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:47:21 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:02:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void		*pt;
	size_t		idx;

	idx = 0;
	pt = malloc(count * size);
	while (idx < size)
		((char*)pt)[idx++] = 0;
	
	return (pt);
}
