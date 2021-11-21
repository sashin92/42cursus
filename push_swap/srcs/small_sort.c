/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 07:52:22 by sashin            #+#    #+#             */
/*   Updated: 2021/11/20 14:41:28 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_all *s)
{
	if (s->a->i > s->a->next->i && s->a->i > s->a->next->next->i)
	{
		if (s->a->next->i > s->a->next->next->i)
		{
			sa(s);
			rra(s);
		}
		else
			ra(s);
	}
	else if (s->a->next->i > s->a->i && s->a->next->i > s->a->next->next->i)
	{
		if (s->a->i > s->a->next->next->i)
			rra(s);
		else
		{
			sa(s);
			ra(s);
		}
	}
	else if (s->a->next->next->i > s->a->i &&
		s->a->next->next->i > s->a->next->i && s->a->i > s->a->next->i)
		sa(s);
}

void	sort_four(t_all *s)
{
	int	count;

	count = 0;
	while (count != 1)
	{
		if (s->a->i == 1)
		{
			pb(s);
			++count;
		}
		else
			ra(s);
	}
	sort_three(s);
	pa(s);
}

void	sort_five(t_all *s)
{
	int	count;

	count = 0;
	while (count != 2)
	{
		if (s->a->i < 3)
		{
			pb(s);
			++count;
		}
		else
			ra(s);
	}
	sort_three(s);
	if (s->b->i < s->b->next->i)
		sb(s);
	pa(s);
	pa(s);
}

void	small_sort(t_all *s, int size)
{
	if (size == 5)
		sort_five(s);
	else if (size == 4)
		sort_four(s);
	else if (size == 3)
		sort_three(s);
	else if (size == 2)
		ra(s);
}