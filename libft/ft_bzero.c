/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:47:19 by sashin            #+#    #+#             */
/*   Updated: 2020/12/28 13:38:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
		((unsigned char *)s)[idx++] = 0;
}
