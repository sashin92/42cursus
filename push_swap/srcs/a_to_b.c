/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 08:39:54 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 10:59:00 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_by_size_a(t_all *s, int size)
{
	if (size == 5)
		five_a(s);
	else if (size == 4)
		four_a(s);
	else if (size == 3)
		three_a(s);
	else if (size == 2)
	{
		if (s->a->i > s->a->next->i)
			sa(s);
	}
}

void	a_to_b(t_all *s, int size)
{
	t_count	count;

	if (size <= 5)
	{
		sort_by_size_a(s, size);
		return ;
	}
	init_count(&count);
	get_pivot(s->a, &count, size);
	a_to_b_sort(s, &count, size);
	ft_rewind(s, count);
	a_to_b(s, count.ra);
	b_to_a(s, count.rb);
	b_to_a(s, count.pb - count.rb);
}