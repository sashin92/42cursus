/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:01:43 by sashin            #+#    #+#             */
/*   Updated: 2021/06/19 22:23:33 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rev_rotate(t_dlist **dlst)
{
	t_dlist	*dlst_last;

	if (*dlst == NULL || (*dlst)->next == NULL)
		return ;
	dlst_last = ft_dlstlast(*dlst);
	dlst_last->prev->next = NULL;
	dlst_last->prev = NULL;
	dlst_last->next = *dlst;
	(*dlst)->prev = dlst_last;
	*dlst = dlst_last;
}

void		rotate(t_dlist **dlst)
{
	t_dlist	*dlst_last;
	t_dlist	*head;
	t_dlist	*tmp;

	if (*dlst == NULL || (*dlst)->next == NULL)
		return ;
	tmp = *dlst;
	head = (*dlst)->next;
	dlst_last = ft_dlstlast(*dlst);
	dlst_last->next = tmp;
	tmp->prev = dlst_last;
	tmp->next = NULL;
	*dlst = head;
}

void		swap(t_dlist **dlst)
{
	t_dlist	*tmp_one;
	t_dlist	*tmp_two;

	if (*dlst == NULL || (*dlst)->next == NULL)
		return ;
	tmp_one = *dlst;
	tmp_two = (*dlst)->next;
	if (tmp_two->next != NULL)
		tmp_two->next->prev = tmp_one;
	tmp_one->next = tmp_two->next;
	tmp_one->prev = tmp_two;
	tmp_two->next = tmp_one;
	tmp_two->prev = NULL;
	*dlst = tmp_two;
}

void		push(t_dlist **src_dlst, t_dlist **dest_dlst)
{
	t_dlist	*src_header;
	t_dlist	*dest_header;
	t_dlist	*tmp;

	if (*src_dlst == NULL)
		return ;
	tmp = *src_dlst;
	src_header = NULL;
	if ((*src_dlst)->next != NULL)
	{
		src_header = (*src_dlst)->next;
		src_header->prev = NULL;
	}
	tmp->next = NULL;
	dest_header = *dest_dlst;
	if (dest_header == NULL)
		dest_header = tmp;
	else
		ft_dlstadd_front(&dest_header, tmp);
	*src_dlst = src_header;
	*dest_dlst = dest_header;
}




int			parse_digit(char *str, int *flag)
{
	int		i;
	unsigned long long		ret;
	int		sign;

	i = 0;
	ret = 0;
	sign = 1;
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
		if (ret > 2147483647)
			*flag = 1;
	}
	return ((int)ret * sign);
}

t_dlist		*parse(int argc, char **argv)
{
	t_dlist	*new;
	t_dlist	*tmp;
	int		content;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	new = NULL;
	content = 0;
	while (i < argc)
	{
		content = parse_digit(argv[i], &flag);
		if (flag == 1)
		{
			ft_dlstfree(new);
			return (NULL);
		}
		tmp = ft_dlstnew(content);
		ft_dlstadd_back(&new, tmp);
		++i;
	}
	return (new);
}


void		sort(t_dlist **a, t_dlist **b)
{
	rotate(a);
	push(a, b);
}

void		print_result(t_dlist *a, t_dlist *b)
{
	char	*a_str;
	char	*b_str;

	while (a != NULL || b != NULL)
	{
		if (a != NULL)
			a_str = ft_itoa(a->content);
		else
			a_str = ft_strdup(" ");
		if (b != NULL)
			b_str = ft_itoa(b->content);
		else
			b_str = ft_strdup(" ");
		ft_putstr_fd(a_str, 1);
		ft_putstr_fd(" ", 1);
		ft_putendl_fd(b_str, 1);
		free(a_str);
		free(b_str);
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
		ft_putstr_fd("- -\na b\n", 1);
}

void		run(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	char	*a_str;
	char	*b_str;

	a = parse(argc, argv);
	b = NULL;
	a_str = NULL;
	b_str = NULL;
	if (a == NULL)
	{
		ft_putstr_fd("Wrong Arguments.\n", 1);
		return ;
	}
	sort(&a, &b);
	print_result(a, b);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd("Please Input Arguments.\n", 1);
	else
		run(argc, argv);
	return (0);
}


