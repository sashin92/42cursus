/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:01:43 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 11:04:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rewind(t_all *s, t_count count)
{

	while (count.ra != 0 && count.rb != 0)
	{
		rrr(s);
		count.ra--;
		count.rb--;
	}
	while (count.ra != 0)
	{
		rra(s);
		count.ra--;
	}
	while (count.rb != 0)
	{
		rrb(s);
		count.rb--;
	}
}

int		check_ascending(t_dlist **a, t_dlist **b)
{
	t_dlist	*a_ptr;
	t_dlist	*b_ptr;

	a_ptr = *a;
	b_ptr = *b;
	if (b_ptr != NULL)
		return (-1);
	while (a_ptr->next != NULL)
	{
		if (a_ptr->content < a_ptr->next->content)
			a_ptr = a_ptr->next;
		else
			return (-1);
	}
	return (1);
}

void	pre_sort(t_dlist **a)
{
	t_dlist *head;
	t_dlist	*cmp;
	int		idx;

	head = *a;
	while (head)
	{
		idx = 1;
		cmp = *a;
		while (cmp)
		{
			if (head->content > cmp->content)
				++idx;
			cmp = cmp->next;
		}
		head->i = idx;
		head = head->next;
	}
}

void	run(int argc, char **argv)
{
	t_all	s;
	int		lst_size;

	init_s(&s);
	s.a = parse_check_dup(argc, argv);
	if (s.a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	lst_size = ft_dlstsize(s.a);
	pre_sort(&s.a);
	if (check_ascending(&s.a, &s.b) == 1);
	else if (lst_size <= 5)
		small_sort(&s, lst_size);
	else
		a_to_b(&s, lst_size);
	ft_dlstfree(s.a);
	if (s.b != NULL)
		ft_dlstfree(s.b);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		run(argc, argv);
	return (0);
}

