/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:04:17 by sashin            #+#    #+#             */
/*   Updated: 2021/06/20 13:06:20 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int				parse_digit(char *str, int *flag)
{
	int					i;
	unsigned long long	ret;
	int					sign;

	i = 0;
	ret = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			ret = ret * 10 + (str[i] - '0');
		else
			*flag = 1;
		++i;
		if (ret > 2147483647)
			*flag = 1;
	}
	return ((int)ret * sign);
}

t_dlist					*parse(int argc, char **argv)
{
	t_dlist				*new;
	t_dlist				*tmp;
	int					content;
	int					i;
	int					flag;

	i = 1;
	flag = 0;
	new = NULL;
	content = 0;
	while (i < argc)
	{
		content = parse_digit(argv[i], &flag);
		if (flag == 1)
		{
			ft_dlstfree(new);
			return (NULL);
		}
		tmp = ft_dlstnew(content);
		ft_dlstadd_back(&new, tmp);
		++i;
	}
	return (new);
}
