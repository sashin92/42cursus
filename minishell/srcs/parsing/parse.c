/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:24:44 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 16:46:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"
#include "minishell_utils.h"
#include <stdlib.h>

static int	args_clear_with_exit_code(t_info *info)
{
	info->exit_code = 2;
	lst_args_clear(&info->args);
	return (1);
}

static int	check_pipe_error(char *head, t_info *info)
{
	while (*head && ft_isspace(*head))
		++head;
	if (!*head)
	{
		error_msg(info->shell_name, NULL, "syntax error", \
			"unexpected token near pipe token");
		return (1);
	}
	return (0);
}

static void	check_input_redir(t_args **args, int *flag)
{
	t_cmds	*cmds_head;
	t_args	*args_head;

	args_head = *args;
	cmds_head = args_head->cmds;
	while (*flag != 2 && cmds_head)
	{
		if (cmds_head->redir == LL_REDIR || cmds_head->redir == L_REDIR)
			(*flag)++;
		cmds_head = cmds_head->next;
	}
	args_head = args_head->next;
	*args = args_head;
}

static int	check_dup_input(t_info *info)
{
	t_args	*args_head;
	int		flag;

	flag = 0;
	args_head = info->args;
	if (args_head)
		check_input_redir(&args_head, &flag);
	while (flag != 2 && args_head)
	{
		flag = 1;
		check_input_redir(&args_head, &flag);
	}
	if (flag == 2)
	{
		error_msg(info->shell_name, NULL, "syntax error", \
			"Ambiguous input redirect.");
		return (1);
	}
	return (0);
}

int	parse(char *input, t_info *info)
{
	t_cmds	*cmds;
	t_args	*arg_tmp;
	char	*head;

	head = input;
	info->args_num = 0;
	while (*head)
	{
		cmds = parse_cmds(&head, info);
		if (!cmds)
			return (args_clear_with_exit_code(info));
		arg_tmp = lst_args_new(cmds);
		lst_args_add_back(&info->args, arg_tmp);
		++(info->args_num);
		if (*head && *head == '|')
		{
			if (check_pipe_error(++head, info))
				return (args_clear_with_exit_code(info));
			while (ft_isspace(*head))
				++head;
		}
	}
	if (check_dup_input(info))
		return (args_clear_with_exit_code(info));
	return (0);
}
