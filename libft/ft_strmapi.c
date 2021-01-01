/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:04:11 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 14:41:05 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - ft_strmapi() applies the function ’f’ to each character of the string ’s’
** to create a new string  resulting from successive applications of ’f’.
** - return the string created from the successive applications of ’f’.
** - returns NULL if the allocation fails.
*/

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			idx;
	int			length;
	char		*str;

	idx = 0;
	length = 0;
	while (s[length])
		++length;
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (idx < length)
	{
		str[idx] = (*f)(idx, s[idx]);
		++idx;
	}
	str[idx] = '\0';
	return (str);
}
