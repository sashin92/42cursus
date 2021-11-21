/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:40:21 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 13:12:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_by_size_b(t_all *s, int size)
{
	if (size == 5)
		five_b(s);
	else if (size == 4)
		four_b(s);
	else if (size == 3)
		three_b(s);
	else if (size == 2)
	{
		if (s->b->i < s->b->next->i)
			sb(s);
		pa(s);
		pa(s);
	}
	else if (size == 1)
		pa(s);
}

void	b_to_a(t_all *s, int size)
{
	t_count	count;

	if (size <= 5)
	{
		sort_by_size_b(s, size);
		return ;
	}
	init_count(&count);
	get_pivot(s->b, &count, size);
	b_to_a_sort(s, &count, size);
	a_to_b(s, count.pa - count.ra);
	ft_rewind(s, count);
	a_to_b(s, count.ra);
	b_to_a(s, count.rb);
}
