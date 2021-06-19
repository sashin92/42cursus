/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:30:26 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:45:44 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_strncmp() compares s1 against s2 during n characters.
** if find diff, differing s1 & s2 (s1 - s2) at differenced location.
*/

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		idx;

	idx = 0;
	while (idx < n && (s1[idx] || s2[idx]))
	{
		if (s1[idx] != s2[idx])
			return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
		++idx;
	}
	return (0);
}
