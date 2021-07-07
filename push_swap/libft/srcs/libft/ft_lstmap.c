/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:45:43 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:54:44 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** - ft_lstmap() iterates the list 'lst' and applies the function 'f' to the
** content of each node.
** - this function creates a new list resulting of the successive applications
** of the function 'f'.
** - the 'del' function is used to delete the content of the node if needed.
*/

static void	lstmap_clear(t_list *lst, void (*del)(void *))
{
	t_list		*temp;

	while (lst)
	{
		temp = lst->next;
		del(lst->content);
		free(lst);
		lst = temp;
	}
	lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*head;

	new = (t_list *)malloc(sizeof(t_list));
	if (!lst || !new)
		return (NULL);
	new->content = (*f)(lst->content);
	head = new;
	head->next = NULL;
	while (lst->next)
	{
		head->next = (t_list *)malloc(sizeof(t_list));
		if (!head->next)
		{
			lstmap_clear(new, del);
			return (NULL);
		}
		lst = lst->next;
		head = head->next;
		head->content = (*f)(lst->content);
		head->next = NULL;
	}
	return (new);
}
