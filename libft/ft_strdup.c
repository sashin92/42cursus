/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:35:29 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:02:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		length;
	size_t		idx;

	length = 0;
	while (s1[length])
		++length;
	s2 = malloc((length + 1) * sizeof(char*));
	idx = 0;
	while (s1[idx])
	{	s2[idx] = s1[idx];
		++idx;
	}
	s2[idx] = 0;
	return (s2);
}
