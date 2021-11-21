/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:04:17 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 13:17:30 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	parse_digit(char *str, int *flag, int i)
{
	long long			ret;
	long long			sign;

	ret = 0;
	sign = 1;
	if (str[0] == '\0' || (str[0] == '-' && str[1] == '\0') || \
			(str[0] == '+' && str[1] == '\0'))
		*flag = 1;
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
	}
	if (ret > 2147483647 && (ret * sign) != -2147483648)
		*flag = 1;
	return (ret * sign);
}

static void	check_duplicate(t_dlist *dlst, int content, int *flag)
{
	t_dlist	*head;

	if (dlst == NULL)
		return ;
	head = dlst;
	while (head)
	{
		if (head->content == content)
		{
			*flag = 1;
			break ;
		}
		head = head->next;
	}
}

t_dlist	*parse_check_dup(int argc, char **argv)
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
		content = parse_digit(argv[i], &flag, 0);
		check_duplicate(new, content, &flag);
		if (flag == 1)
		{
			ft_dlstfree(new);
			return (NULL);
		}
		tmp = ft_dlstnew(content, i);
		ft_dlstadd_back(&new, tmp);
		++i;
	}
	return (new);
}
