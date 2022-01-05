/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:15:31 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 21:31:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include "minishell_exec.h"
#include "minishell_builtins.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <signal.h>

static void	reset_stdin_stdout(int tmp_stdin, int tmp_stdout, t_info *info)
{
	if (tmp_stdout)
	{
		close(tmp_stdout);
		dup2(info->cp_stdout, STDOUT_FILENO);
	}
	else if (tmp_stdin)
	{
		close(tmp_stdin);
		dup2(info->cp_stdin, STDIN_FILENO);
	}
}

void	exec_program(char **parsed_argv, char **parsed_envs, t_info *info)
{
	int		tmp_stdin;
	int		tmp_stdout;
	char	*ret;

	tmp_stdin = 0;
	tmp_stdout = 0;
	ret = redirection(info, &tmp_stdin, &tmp_stdout);
	if (ret)
	{
		reset_stdin_stdout(tmp_stdin, tmp_stdout, info);
		error_msg(info->shell_name, NULL, ret, NULL);
		info->exit_code = 1;
		return ;
	}
	else
		info->exit_code = 0;
	if (parsed_argv[0] && exec_command(parsed_argv, info, parsed_envs))
	{
		reset_stdin_stdout(tmp_stdin, tmp_stdout, info);
		error_exec_fail_msg(info, parsed_argv[0]);
	}
	else
		reset_stdin_stdout(tmp_stdin, tmp_stdout, info);
}

void	exec_args(t_info *info)
{
	char	**parsed_argv;
	char	**parsed_envs;

	parsed_argv = NULL;
	parsed_envs = NULL;
	if (info->args->cmds)
		parsed_argv = cmds_to_argv(info->args->cmds);
	parsed_envs = envs_combine_key_value(info->envs);
	termios_echoctl_on();
	signal(SIGINT, SIG_IGN);
	if (info->args_num == 1 && check_builtin(parsed_argv))
		exec_program(parsed_argv, parsed_envs, info);
	else
		exec_programs_in_child(parsed_envs, info);
	termios_echoctl_off();
	ft_dfree(parsed_envs);
	free(parsed_argv);
	return ;
}
