/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:15:10 by sashin            #+#    #+#             */
/*   Updated: 2021/12/26 16:15:10 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include "minishell_macros_structs.h"
#include <stdlib.h>

t_cmds	*lst_cmds_new(char *cmd, int redir)
{
	t_cmds	*new;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new)
		exit_strerror();
	new->cmd = cmd;
	new->redir = redir;
	new->next = NULL;
	return (new);
}

void	lst_cmds_add_back(t_cmds **cmds, t_cmds *new)
{
	t_cmds	*temp;

	if (*cmds == NULL)
		*cmds = new;
	else
	{
		temp = *cmds;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	lst_cmds_clear(t_cmds **cmds)
{
	t_cmds	*temp;

	while (*cmds)
	{
		temp = (*cmds)->next;
		free((*cmds)->cmd);
		free(*cmds);
		*cmds = temp;
	}
	*cmds = NULL;
}

static int	get_argc(t_cmds *cmds)
{
	t_cmds	*tmp;
	int		argc;

	argc = 0;
	tmp = cmds;
	while (tmp)
	{
		if (!tmp->redir)
			++argc;
		tmp = tmp->next;
	}
	return (argc);
}

char	**cmds_to_argv(t_cmds *cmds)
{
	int		argc;
	char	**parsed_argv;
	int		i;

	argc = get_argc(cmds);
	parsed_argv = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!parsed_argv)
		exit_strerror();
	i = 0;
	while (i < argc)
	{
		if (!cmds->redir)
		{
			parsed_argv[i] = cmds->cmd;
			++i;
		}
		cmds = cmds->next;
	}
	parsed_argv[argc] = NULL;
	return (parsed_argv);
}
