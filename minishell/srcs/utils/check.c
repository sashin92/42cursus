/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:57:08 by sashin            #+#    #+#             */
/*   Updated: 2021/12/16 20:21:46 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_lib.h"
#include "minishell_macros_structs.h"
#include <stdlib.h>

int	check_isspc(char c)
{
	if (c == '<')
		return (L_REDIR);
	else if (c == '>')
		return (R_REDIR);
	else if (c == '|')
		return (PIPE);
	else if (c == '$')
		return (DOLLAR);
	else if (c == '\'')
		return (QUOTE);
	else if (c == '\"')
		return (DQUOTE);
	return (0);
}

int	check_isspc_in_str(char *content)
{
	if (content[0] && content[1] && !ft_strncmp(content, "<<", 2))
		return (LL_REDIR);
	else if (content[0] && content[1] && !ft_strncmp(content, ">>", 2))
		return (RR_REDIR);
	else if (content[0] && !ft_strncmp(content, "<", 1))
		return (L_REDIR);
	else if (content[0] && !ft_strncmp(content, ">", 1))
		return (R_REDIR);
	else if (content[0] && !ft_strncmp(content, "|", 1))
		return (PIPE);
	else if (content[0] && !ft_strncmp(content, "\'", 1))
		return (QUOTE);
	else if (content[0] && !ft_strncmp(content, "\"", 1))
		return (DQUOTE);
	return (0);
}

t_envs	*envs_search(t_envs *envs, char *str)
{
	t_envs	*head;

	head = envs;
	while (head)
	{
		if (!(ft_strcmp(head->key, str)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	check_builtin(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (!cmds)
			return (FALSE);
		else if (!ft_strcmp(cmds[i], "cd"))
			return (TRUE);
		else if (!ft_strcmp(cmds[i], "pwd"))
			return (TRUE);
		else if (!ft_strcmp(cmds[i], "export"))
			return (TRUE);
		else if (!ft_strcmp(cmds[i], "unset"))
			return (TRUE);
		else if (!ft_strcmp(cmds[i], "env"))
			return (TRUE);
		else if (!ft_strcmp(cmds[i], "exit"))
			return (TRUE);
		else if (!ft_strcmp(cmds[i], "echo"))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	check_input_isempty(char **head, char *input)
{
	while (**head && ft_isspace(**head))
		++(*head);
	if (!**head)
	{
		free(input);
		return (1);
	}
	return (0);
}
