/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:35:29 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:56:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

/*
** ft_strdup() duplicate s1 to new string.
*/

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		length;
	size_t		idx;

	length = 0;
	while (s1[length])
		++length;
	s2 = (char *)malloc((length + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		s2[idx] = s1[idx];
		++idx;
	}
	s2[idx] = '\0';
	return (s2);
}
