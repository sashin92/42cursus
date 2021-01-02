/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:19:12 by sashin            #+#    #+#             */
/*   Updated: 2021/01/02 14:24:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - ft_split() allocates and returns an array of strings obtained
** by splitting 's' using the character 'c' as a delimiter.
** - The array must be ended by a NULL pointer.
** - return array of new strings resulting from the split.
** NULL if the allocation fails.
*/

static int		split_str_count(char const *s, char c)
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

static int		split_length(char const *s, char c)
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

static char		*split_dup(char const *s, int length)
{
	int			idx;
	char		*str;

	idx = 0;
	if (!(str = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (idx < length)
	{
		str[idx] = s[idx];
		++idx;
	}
	str[idx] = '\0';
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
	count = split_str_count(s, c);
	if (!(s_arr = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	while (s[idx])
	{
		if (!(s[idx] == c))
		{
			s_arr[arr_idx] = split_dup(&s[idx], split_length(&s[idx], c));
			++arr_idx;
			while (!(s[idx] == c) && s[idx])
				++idx;
		}
		else
			++idx;
	}
	s_arr[arr_idx] = NULL;
	return (s_arr);
}
