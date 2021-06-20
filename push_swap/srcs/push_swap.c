/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:01:43 by sashin            #+#    #+#             */
/*   Updated: 2021/06/20 13:46:14 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_result(t_dlist *a, t_dlist *b, int count)
{
	char	*a_str;
	char	*b_str;
	char	*no;
	int		i;

	i = 1;
	ft_putstr_fd("------------\n n | a | b |\n---|---|---|\n", 1);
	while (i <= count)
	{
		no = ft_itoa(i);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(no, 1);
		free(no);
		++i;
		if (a != NULL)
			a_str = ft_itoa(a->content);
		else
			a_str = ft_strdup(" ");
		if (b != NULL)
			b_str = ft_itoa(b->content);
		else
			b_str = ft_strdup(" ");
		ft_putstr_fd(" | ", 1);
		ft_putstr_fd(a_str, 1);
		ft_putstr_fd(" | ", 1);
		ft_putstr_fd(b_str, 1);
		ft_putstr_fd(" |\n", 1);
		free(a_str);
		free(b_str);
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	ft_putstr_fd("------------\n", 1);
}

int			check_ascending(t_dlist **a, t_dlist **b)
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

void		sort(t_dlist **a, t_dlist **b)
{
	ct_rotater(a);
	ct_pusher(a, b);
}

void		run(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	int		count;

	a = parse(argc, argv);
	b = NULL;
	if (a == NULL)
	{
		ft_putstr_fd("Wrong Arguments.\n", 1);
		return ;
	}
	count = ft_dlstsize(a);
	sort(&a, &b);
	print_result(a, b, count);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd("Please Input Arguments.\n", 1);
	else
		run(argc, argv);
	return (0);
}


