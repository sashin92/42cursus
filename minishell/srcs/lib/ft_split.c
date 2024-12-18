/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:19:12 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 12:34:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** - ft_split() allocates and returns an array of strings obtained
** by splitting 's' using the character 'c' as a delimiter.
** - The array must be ended by a NULL pointer.
** - return array of new strings resulting from the split.
** NULL if the allocation fails.
*/

static char	**split_allocate(char const *s, char c)
{
	int			idx;
	int			count;
	char		**s_arr;

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
	s_arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!s_arr)
		return (NULL);
	return (s_arr);
}

static int	split_len(char const *s, char c)
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

static char	*split_dup(char const *s, int length)
{
	int			idx;
	char		*str;

	idx = 0;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (idx < length)
	{
		str[idx] = s[idx];
		++idx;
	}
	str[idx] = '\0';
	return (str);
}

static void	*split_free(char **s_arr, int arr_idx)
{
	while (arr_idx >= 0)
	{
		free(s_arr[arr_idx]);
		--arr_idx;
	}
	free(s_arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			idx;
	int			arr_idx;
	char		**s_arr;

	idx = 0;
	arr_idx = 0;
	s_arr = split_allocate(s, c);
	if (!s_arr)
		return (NULL);
	while (s[idx])
	{
		if (!(s[idx] == c))
		{
			s_arr[arr_idx++] = split_dup(&s[idx], split_len(&s[idx], c));
			if (!s_arr[arr_idx - 1])
				return (split_free(s_arr, (arr_idx - 1)));
			while (!(s[idx] == c) && s[idx])
				++idx;
		}
		else
			++idx;
	}
	s_arr[arr_idx] = NULL;
	return (s_arr);
}
