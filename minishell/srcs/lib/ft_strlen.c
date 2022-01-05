/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:46:59 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:56:55 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlen() computes the length of the string s. return length of s.
*/

int	ft_strlen(const char *s)
{
	int		length;

	length = 0;
	while (s[length])
		++length;
	return (length);
}
