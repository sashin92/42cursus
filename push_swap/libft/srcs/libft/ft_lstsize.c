/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:07:03 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:54:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_lstsize() counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int			count;

	count = 0;
	while (lst != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
