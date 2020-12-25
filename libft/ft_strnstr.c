/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:04:37 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:03:09 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	const char		*pt;

	if (little[0] == 0)
		return ((char*)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			++j;
			if (little[j] == 0)
			{
				pt = &big[i];
				return ((char*)pt);
			}
		}
		++i;
	}
	return (0);
}
