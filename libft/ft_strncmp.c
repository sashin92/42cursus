/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:30:26 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 16:36:47 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n)
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		++idx;
	}
	return (0);
}
