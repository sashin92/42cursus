/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:01:43 by sashin            #+#    #+#             */
/*   Updated: 2021/10/28 16:16:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


#include <stdio.h>


void	print_result(t_dlist *a, t_dlist *b, int count)
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

int	check_ascending(t_dlist **a, t_dlist **b)
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

// t_dlist	*find_pivot(t_dlist **a, int dlst_size)
// {
// 	t_dlist	*head;
// 	int		dlst_size_half;
	
// 	dlst_size_half = (dlst_size / 2) + (dlst_size % 2);
// 	head = *a;
// 	while (head)
// 	{
// 		if (head->i == dlst_size_half)
// 			return (head);
// 		head = head->next;
// 	}
// 	ft_putstr_fd("i cannot find pivot T_T\n", 1);
// 	return (NULL);
// }

// void	sort_a_to_b(t_all *s, int range)
// {
// 	int		i;

// 	i = 0;
// 	s->pivot = find_pivot(&s->a, range);
// 	if (range > 2)
// 	{
// 		while (i++ < range)
// 		{
// 			if ((s->a)->content < (s->pivot)->content)
// 			{
// 				ct_pusher(&s->a, &s->b, "pb");
// 				print_result(s->a, s->b, range);
// 				sleep(1);
// 			}
// 			else
// 			{
// 				ct_rotater(&s->a, NULL, "ra");
// 				print_result(s->a, s->b, range);
// 				sleep(1);
// 			}
// 		}
// 	}
// }






// void	sort(t_all *s, int dlst_size)
// {
// 	int		i;

// 	i = 0;
// 	s->pivot = find_pivot(&s->a, dlst_size);
// 	while (i++ < dlst_size)
// 	{
// 		if ((s->a)->content < (s->pivot)->content)
// 		{
// 			ct_pusher(&s->a, &s->b, "pb");
// 			print_result(s->a, s->b, dlst_size);
// 			sleep(1);
// 		}
// 		else
// 		{
// 			ct_rotater(&s->a, NULL, "ra");
// 			print_result(s->a, s->b, dlst_size);
// 			sleep(1);
// 		}
// 	}
// }



void	sort(t_all *s)
{
	int		i_mid;
	int		i;

	i_mid = (s->idx_max - s->idx_min + 1) / 2 + s->idx_min;
	i = 1;

	while (i < i_mid)
	{
		if (s->a->i < i_mid)
		{
			ct_pusher(&s->a, &s->b, "pb");
			if (s->b != NULL && s->b->i < (i_mid - 1) / 2 + 1)
				ct_rotater(NULL, &s->b, "rb");
			++i;
		}
		else
			ct_rotater(&s->a, NULL, "ra");
	}
}


void	sort_pa(t_all *s)
{
	int		i_mid;


	while (s->b != NULL)
	{
		i_mid = (s->idx_max - s->idx_min + 1) / 2 + s->idx_min;
		if (s->b == ft_dlstlast(s->b))
			


	}
}



void	ft_push_b_to_a(t_infobox *box, int imax)
{
	int	imid;
	int	i;

	while (box->bfirst != NULL)
	{
		imid = (imax - box->imin + 1) / 2 + box->imin;
		i = imax - imid;
		if (i < 1 || box->bfirst == box->blast)
			ft_push_last_b_to_a(box, imax);
		while (box->bfirst != NULL && i > 0)
		{
			if (ft_find_sorted_elem(box) < 0)
			{
				if (box->bfirst != NULL && box->bfirst->index > imid)
				{
					box->bfirst->portion = imax;
					ft_sort_operation(box, pa);
					i--;
				}
				else
					ft_sort_operation(box, rb);
			}
		}
		imax = imid;
	}
}





// void	ft_sort_second_half(t_infobox *box)
// {
// 	while (box->afirst->portion == 0)
// 	{
// 		if (box->afirst->index == box->imin)
// 			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
// 		else if (box->afirst->next->index == box->imin)
// 		{
// 			ft_sort_operation(box, sa);
// 			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
// 		}
// 		else if (box->bfirst != NULL && box->bfirst->index == box->imin)
// 		{
// 			ft_sort_operation(box, pa);
// 			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
// 		}
// 		else if (box->bfirst != NULL && box->blast->index == box->imin)
// 		{
// 			ft_sort_operation(box, rrb);
// 			ft_sort_operation(box, pa);
// 			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
// 		}
// 		else
// 			ft_sort_operation(box, pb);
// 	}
// 	ft_push_b_to_a(box, box->imax);
// 	ft_sort_by_portion(box);
// }






void	init_s(t_all *s)
{
	s->a = NULL;
	s->b = NULL;
	s->idx_min = 1;
	s->idx_max = 0;
}

void	run(int argc, char **argv)
{
	t_all	s;

	init_s(&s);
	s.a = parse_check_dup(argc, argv);
	if (s.a == NULL)
	{
		ft_putstr_fd("Wrong Arguments.\n", 2);
		return ;
	}
	s.idx_max = ft_dlstsize(s.a);
	pre_sort(&s.a);
	if (check_ascending(&s.a, &s.b) == 1)
		ft_putstr_fd("Done!\n", 1);
	else
		sort(&s);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd("Please Input Arguments.\n", 1);
	else
		run(argc, argv);
	return (0);
}

