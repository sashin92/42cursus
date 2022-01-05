/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:24:44 by sashin            #+#    #+#             */
/*   Updated: 2021/12/23 15:24:16 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"
#include "minishell_utils.h"
#include <stdlib.h>

static int	get_redir(char **head)
{
	int		ret;

	ret = check_isspc_in_str(*head);
	if (ret == L_REDIR || ret == R_REDIR)
		*head += 1;
	else if (ret == LL_REDIR || ret == RR_REDIR)
		*head += 2;
	else
		ret = 0;
	while (*head && ft_isspace(**head))
		++(*head);
	return (ret);
}

static int	check_redir_error(char **input)
{
	int		spc;

	spc = check_isspc_in_str(*input);
	if (spc == L_REDIR || spc == R_REDIR || spc == LL_REDIR || \
		spc == RR_REDIR || spc == PIPE)
		return (spc);
	return (0);
}

static int	make_cmds(t_cmds **ret, int redir, char **head, t_info *info)
{
	char	*cmd;
	t_cmds	*tmp;

	if (head == NULL)
	{
		cmd = ft_strnew();
		if (!cmd)
			exit_strerror();
	}
	else
		cmd = get_cmd(head, info);
	if (!cmd)
		return (1);
	tmp = lst_cmds_new(cmd, redir);
	lst_cmds_add_back(ret, tmp);
	return (0);
}

static int	check_and_get_redir(char **head, t_info *info)
{
	int		redir_error;
	int		redir;

	redir_error = 0;
	redir = get_redir(head);
	if (redir)
	{
		redir_error = check_redir_error(head);
		if (!**head)
			redir_error = -1;
	}
	if (redir_error)
	{
		error_msg(info->shell_name, NULL, "syntax error", \
			"unexpected token near redirection token");
		redir = -1;
	}
	return (redir);
}

t_cmds	*parse_cmds(char **head, t_info *info)
{
	t_cmds	*ret;
	int		redir;

	ret = NULL;
	redir = 0;
	while (**head && **head != '|')
	{
		redir = check_and_get_redir(head, info);
		if (redir == -1 || make_cmds(&ret, redir, head, info))
		{
			lst_cmds_clear(&ret);
			return (NULL);
		}
	}
	if (!ret)
		error_msg(info->shell_name, NULL, "syntax error", \
			"unexpected token near pipe token");
	return (ret);
}
