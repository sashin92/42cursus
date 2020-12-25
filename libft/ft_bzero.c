/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:47:19 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 17:27:22 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			ft_bzero(void *s, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
		((unsigned char*)s)[idx++] = 0;
}
