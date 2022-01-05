/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:06:08 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 12:01:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include "minishell_macros_structs.h"
#include <stdlib.h>

t_args	*lst_args_new(t_cmds *cmds)
{
	t_args	*new;

	new = (t_args *)malloc(sizeof(t_args));
	if (!new)
		exit_strerror();
	new->cmds = cmds;
	new->next = NULL;
	return (new);
}

void	lst_args_add_back(t_args **args, t_args *new)
{
	t_args	*temp;

	if (*args == NULL)
		*args = new;
	else
	{
		temp = *args;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	lst_args_clear(t_args **args)
{
	t_args	*temp;

	if (*args == NULL)
		return ;
	while (*args)
	{
		temp = (*args)->next;
		lst_cmds_clear(&(*args)->cmds);
		free(*args);
		*args = temp;
	}
	*args = NULL;
}
