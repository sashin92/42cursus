/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:45:43 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 18:10:15 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - ft_lstmap() iterates the list 'lst' and applies the function 'f' to the
** content of each node.
** - this function creates a new list resulting of the successive applications
** of the function 'f'.
** - the 'del' function is used to delete the content of the node if needed.
*/

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *head;

	if (!lst || !(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = (*f)(lst->content);
	head = new;
	head->next = NULL;
	while (lst->next)
	{
		if (!(head->next = (t_list *)malloc(sizeof(t_list))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
		head = head->next;
		head->content = (*f)(lst->content);
		head->next = NULL;
	}
	return (new);
}
