/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:19:12 by sashin            #+#    #+#             */
/*   Updated: 2020/12/31 17:13:20 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				f_str_count(char const *s, char c)
{
	int			idx;
	int			count;

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

int				f_split_length(char const *s, char c)
{
	int			idx;
	int			length;

	idx = 0;
	length = 0;
	while (!(s[idx] == c) && s[idx])
	{
		++length;
		++idx;
	}
	return (length);
}

char			*f_allocate(char const *s, int length)
{
	int			idx;
	char		*str;

	idx = 0;
	str = (char *)malloc((length + 1) * sizeof(char));
	while (idx < length)
	{
		str[idx] = s[idx];
		++idx;
	}
	str[idx] = 0;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int			count;
	int			idx;
	int			arr_idx;
	char		**s_arr;

	idx = 0;
	arr_idx = 0;
	count = f_str_count(s, c);
	if (!(s_arr = (char **)malloc((count + 1) * sizeof(char *))))
		return (0);
	while (s[idx])
	{
		if (!(s[idx] == c))
		{
			s_arr[arr_idx] = f_allocate(&s[idx], f_split_length(&s[idx], c));
			++arr_idx;
			while (!(s[idx] == c) && s[idx])
				++idx;
		}
		else
			++idx;
	}
	s_arr[arr_idx] = 0;
	return (s_arr);
}
