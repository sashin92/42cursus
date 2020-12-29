/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:04:11 by sashin            #+#    #+#             */
/*   Updated: 2020/12/29 15:39:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (0);
	while (idx < length)
	{
		str[idx] = (*f)(idx, s[idx]);
		++idx;
	}
	str[idx] = 0;
	return (str);
}
