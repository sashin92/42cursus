/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:15:23 by sashin            #+#    #+#             */
/*   Updated: 2022/01/05 15:01:30 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include "minishell_exec.h"
#include "minishell_builtins.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static void	make_process(int *pid, int *fd, char **parsed_envs, t_info *info)
{
	char	**parsed_argv;
	int		n;
	int		i;

	i = -1;
	while (++i < info->args_num)
	{
		parsed_argv = cmds_to_argv(info->args->cmds);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			signal(SIGINT, SIG_DFL) && signal(SIGQUIT, SIG_DFL);
			if (info->args_num != 1 && i != 0)
				dup2(fd[2 * (i - 1)], STDIN_FILENO);
			if (info->args_num != 1 && i != (info->args_num - 1))
				dup2(fd[(2 * i) + 1], STDOUT_FILENO);
			n = 0;
			while (n < ((info->args_num - 1) * 2))
				close(fd[n++]);
			exec_program(parsed_argv, parsed_envs, info);
			exit(info->exit_code);
		}
		free(parsed_argv);
		info->args = info->args->next;
	}
}

static void	wait_check_childs(t_info *info, int *fd, int *pid)
{
	int		i;
	int		state;

	i = 0;
	while (i < ((info->args_num - 1) * 2))
		close(fd[i++]);
	i = 0;
	while (i < info->args_num)
	{
		waitpid(pid[i], &state, 0);
		if (state)
		{
			if (WIFSIGNALED(state))
				info->exit_code = 128 + WTERMSIG(state);
			else
				info->exit_code = WEXITSTATUS(state);
		}
		else
			info->exit_code = 0;
		++i;
	}
	free(fd);
	free(pid);
}

int	exec_programs_in_child(char **parsed_envs, t_info *info)
{
	int		i;
	int		*pid;
	int		*fd;

	pid = (int *)malloc(sizeof(int) * info->args_num);
	fd = (int *)malloc(sizeof(int) * ((info->args_num - 1) * 2));
	if (!pid || !fd)
		exit_strerror();
	i = -1;
	if (info->args_num > 1)
		while (++i < info->args_num - 1)
			pipe(&fd[i * 2]);
	make_process(pid, fd, parsed_envs, info);
	wait_check_childs(info, fd, pid);
	return (0);
}
