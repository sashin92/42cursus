/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:40:56 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 13:19:14 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_dlist *lst, int size)
{
	int		i;
	int		val;
	t_dlist	*tmp_lst;

	i = 0;
	val = lst->i;
	tmp_lst = lst;
	while (i++ < size)
	{
		if (val < tmp_lst->i)
			val = tmp_lst->i;
		if (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
	}
	return (val);
}

int	get_min(t_dlist *lst, int size)
{
	int		i;
	int		val;
	t_dlist	*tmp_lst;

	i = 0;
	val = lst->i;
	tmp_lst = lst;
	while (i++ < size)
	{
		if (val > tmp_lst->i)
			val = tmp_lst->i;
		if (tmp_lst->next != NULL)
			tmp_lst = tmp_lst->next;
	}
	return (val);
}

int	get_mid(t_dlist *lst, int size)
{
	int		i;
	int		j;
	int		order;
	t_dlist	*tmp_lst_one;
	t_dlist	*tmp_lst_two;

	i = 0;
	tmp_lst_one = lst;
	while (i++ < size)
	{
		order = 0;
		j = 0;
		tmp_lst_two = lst;
		while (j++ < size)
		{
			if (tmp_lst_one->i >= tmp_lst_two->i)
				++order;
			tmp_lst_two = tmp_lst_two->next;
		}
		if (order == (size + 1) / 2)
			break ;
		tmp_lst_one = tmp_lst_one->next;
	}
	return (tmp_lst_one->i);
}

void	get_pivot(t_dlist *lst, t_count *count, int size)
{
	int		max;
	int		min;

	max = get_max(lst, size);
	min = get_min(lst, size);
	count->pivot_one = (max + min) / 2;
	count->pivot_two = (count->pivot_one + min) / 2;
}
