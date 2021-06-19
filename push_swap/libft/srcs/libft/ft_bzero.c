/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:47:19 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:44:05 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**  ft_bzero() writes n zeroed bytes to the string s.
** If n is zero, ft_bzero() does nothing.
*/

void		ft_bzero(void *s, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
		((char *)s)[idx++] = '\0';
}
