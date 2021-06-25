/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:49:48 by sashin            #+#    #+#             */
/*   Updated: 2021/06/25 18:11:14 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist		*ft_dlstnew(int content, int i)
{
	t_dlist	*new;

	if (!(new = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	new->content = content;
	new->i = i;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	new->next = *dlst;
	(*dlst)->prev = new;
	new->prev = NULL;
	*dlst = new;
}

void		ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist *temp;

	if (*dlst == NULL)
		*dlst = new;
	else
	{
		temp = *dlst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

t_dlist		*ft_dlstlast(t_dlist *dlst)
{
	if (dlst == NULL)
		return (NULL);
	while (dlst->next != NULL)
		dlst = dlst->next;
	return (dlst);
}

void		ft_dlstfree(t_dlist *dlst)
{
	t_dlist	*head;
	t_dlist	*tmp;

	if (dlst == NULL)
		return ;
	head = dlst;
	while (head->next != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

int				ft_dlstsize(t_dlist *dlst)
{
	t_dlist		*tmp;
	int			count;

	count = 0;
	tmp = dlst;
	while (tmp != NULL)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}
