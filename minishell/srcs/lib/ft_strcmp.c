/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:08:58 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 14:08:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** ft_strcmp() compares s1 against s2.
** if find diff, differing s1 & s2 (s1 - s2) at differenced location.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		idx;

	idx = 0;
	if (!s1)
		return (-1);
	else if (!s2)
		return (-1);
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
		++idx;
	}
	if (s1[idx])
		return (((unsigned char *)s1)[idx]);
	else if (s2[idx])
		return (-((unsigned char *)s2)[idx]);
	return (0);
}
