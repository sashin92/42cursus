/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:30:47 by sashin            #+#    #+#             */
/*   Updated: 2020/12/25 22:02:56 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strchr(const char *s, int c)
{
	int				idx;
	const char		*pt;

	idx = 0;
	if (s == 0)
		return (0);
	if (c == 0)
		return (0);
	while (s[idx])
	{
		if (s[idx] == c)
		{
			pt = &s[idx];
			return ((char*)pt);
		}
		++idx;
	}
	return (0);
}
