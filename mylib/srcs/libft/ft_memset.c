/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:41:12 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:45:06 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**  ft_memset() writes len bytes of value c(converted to an unsigned char)
** to the string b.
*/

void		*ft_memset(void *b, int c, size_t len)
{
	size_t		idx;

	idx = 0;
	while (idx < len)
	{
		((unsigned char *)b)[idx] = c;
		++idx;
	}
	return (b);
}
