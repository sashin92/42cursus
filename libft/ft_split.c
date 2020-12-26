/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:19:12 by sashin            #+#    #+#             */
/*   Updated: 2020/12/26 15:26:20 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			f_str_count(char const *s, char c)
{
	int		idx;
	int		count;

	idx = 0;
	count = 0;
	while (s[idx])
	{
		if (s[idx] != c)
		{
			++count;
			while (s[idx] != c && s[idx])
				++idx;
		}
		else
			++idx;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	int		count;
	int		idx;
	char	**s_arr;

	idx = 0;
	count = f_str_count(s, c);
	s_arr = (char**)malloc((count + 1) * sizeof(char*));

	while (s[idx])
	{
		if (s[idx]);
	}
}
