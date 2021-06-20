/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:47:25 by sashin            #+#    #+#             */
/*   Updated: 2021/06/20 13:08:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ct_rev_rotater(t_dlist **dlst)
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

void		ct_rotater(t_dlist **dlst)
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

void		ct_swapper(t_dlist **dlst)
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

void		ct_pusher(t_dlist **src_dlst, t_dlist **dest_dlst)
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