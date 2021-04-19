/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:04:37 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:45:46 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - ft_strnstr() find string little in string big during len. if find little,
** return pointer big indexing first of little char.
** - if can't find little in big, return NULL.
*/

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*pt;

	if (little[0] == '\0')
		return ((char*)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			++j;
			if (little[j] == '\0')
			{
				pt = &big[i];
				return ((char*)pt);
			}
		}
		++i;
	}
	return (NULL);
}
