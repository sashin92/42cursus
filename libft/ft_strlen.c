/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:46:59 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 13:06:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlen() computes the length of the string s. return length of s.
*/

size_t			ft_strlen(const char *s)
{
	size_t		length;

	length = 0;
	while (s[length])
		++length;
	return (length);
}
