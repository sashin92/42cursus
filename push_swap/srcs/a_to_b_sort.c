/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:57:51 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 11:12:18 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_to_b_sort(t_all *s, t_count *count, int size)
{
	while (size--)
	{
		if (s->a->i >= count->pivot_one)
		{
			ra(s);
			count->ra++;
		}
		else
		{
			pb(s);
			count->pb++;
			if (s->b->i >= count->pivot_two)
			{
				rb(s);
				count->rb++;
			}
		}
	}
}

void	three_a(t_all *s)
{
	if (s->a->i < s->a->next->i &&
		s->a->next->i > s->a->next->next->i)
	{
		if (s->a->i < s->a->next->next->i)
			ra_sa_rra(s);
		else
			ra_sa_rra_sa(s);
	}
	else if (s->a->i > s->a->next->i &&
		s->a->next->i < s->a->next->next->i)
	{
		if (s->a->i < s->a->next->next->i)
			sa(s);
		else
			sa_ra_sa_rra(s);
	}
	else if (s->a->i > s->a->next->i &&
		s->a->next->i > s->a->next->next->i)
		sa_ra_sa_rra_sa(s);
}

void	four_a(t_all *s)
{
	int		count;
	int		i;
	int		min;

	i = 0;
	count = 0;
	min = get_min(s->a, 4);
	while (i < 4 && count != 1)
	{
		if (s->a->i == min)
		{
			pb(s);
			++count;
		}
		else
		{
			ra(s);
			++i;
		}
	}
	while (i-- > 0)
		rra(s);
	three_a(s);
	pa(s);
}

void	five_a(t_all *s)
{
	int		mid;
	int		count;
	int		i;

	mid = get_mid(s->a, 5);
	count = 0;
	i = 0;
	while (i < 5 && count != 2)
	{
		if (s->a->i < mid)
		{
			pb(s);
			++count;
		}
		else
		{
			ra(s);
			++i;
		}
	}
	while (i-- > 0)
		rra(s);
	if (s->b->i < s->b->next->i)
		sb(s);
	three_a(s);
	pa(s);
	pa(s);
}