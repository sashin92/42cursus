/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:23:00 by sashin            #+#    #+#             */
/*   Updated: 2020/12/31 15:17:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	int		idx;

	idx = 0;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (lst[idx]->next != NULL)
			++idx;
		lst[idx]->next = new;
	}
}
