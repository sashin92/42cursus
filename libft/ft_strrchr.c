/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:55:35 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:03:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strrchr(const char *s, int c)
{
	int				idx;
	const char		*pt;
	int				length;

	idx = 0;
	length = 0;
	while (s[length])
		++length;
	while (idx < length)
	{
		if (s[length - idx - 1] == c)
		{
			pt = &s[length - idx - 1];
			return ((char*)pt);
		}
		++idx;
	}
	return (0);
}
