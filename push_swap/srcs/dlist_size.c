/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:23:20 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 13:25:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_dlstsize(t_dlist *dlst)
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
