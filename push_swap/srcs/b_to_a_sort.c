/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:00:27 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 11:17:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_to_a_sort(t_all *s, t_count *count, int size)
{
	while (size--)
	{
		if (s->b->i < count->pivot_two)
		{
			rb(s);
			count->rb++;
		}
		else
		{
			pa(s);
			count->pa++;
			if (s->a->i < count->pivot_one)
			{
				ra(s);
				count->ra++;
			}
		}
	}
}

void	three_b(t_all *s)
{
	if (s->b->i < s->b->next->i &&
		s->b->next->i < s->b->next->next->i)
		sb_rb_sb_rrb_sb(s);
	else if (s->b->i < s->b->next->i &&
		s->b->next->i > s->b->next->next->i)
	{
		if (s->b->i < s->b->next->next->i)
			sb_rb_sb_rrb(s);
		else
			sb(s);
	}
	else if (s->b->i > s->b->next->i &&
		s->b->next->i < s->b->next->next->i)
	{
		if (s->b->i < s->b->next->next->i)
			rb_sb_rrb_sb(s);
		else
			rb_sb_rrb(s);
	}
	pa(s);
	pa(s);
	pa(s);
}

void	four_b(t_all *s)
{
	int		count;
	int		i;
	int		max;

	i = 0;
	count = 0;
	max = get_max(s->b, 4);
	while (i < 4 && count != 1)
	{
		if (s->b->i == max)
		{
			pa(s);
			++count;
		}
		else
		{
			rb(s);
			++i;
		}
	}
	while (i-- > 0)
		rrb(s);
	three_b(s);
}

void	five_b(t_all *s)
{
	int		mid;
	int		count;
	int		i;

	mid = get_mid(s->b, 5);
	count = 0;
	i = 0;
	while (i < 5 && count != 2)
	{
		if (s->b->i > mid)
		{
			pa(s);
			++count;
		}
		else
		{
			rb(s);
			++i;
		}
	}
	while (i-- > 0)
		rrb(s);
	if (s->a->i > s->a->next->i)
		sa(s);
	three_b(s);
}