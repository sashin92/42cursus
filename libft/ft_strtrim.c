/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:11:54 by sashin            #+#    #+#             */
/*   Updated: 2020/12/26 13:56:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		f_isset(char const c, char const *set)
{
	int			idx;

	idx = 0;
	while (set[idx])
	{
		if (c == set[idx])
			return (1);
		++idx;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			idx;
	int			begin;
	int			end;
	int			s1_len;

	s1_len = 0;
	while (s1[s1_len])
		++s1_len;
	idx = 0;
	while (f_isset(s1[idx], set))
		++idx;
	begin = idx;

}
