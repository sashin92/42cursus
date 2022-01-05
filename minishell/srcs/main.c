/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:24:44 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 21:30:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

static void	clear_input_args(t_info *info, char **input, t_args **tmp_args)
{
	lst_args_clear(tmp_args);
	info->args = NULL;
	free(*input);
}

static void	run(t_info info)
{
	char	*input;
	char	*head;
	t_args	*tmp_args;

	termios_echoctl_off();
	while (1)
	{
		signal_reset();
		input = readline(info.cmd_line);
		if (!input)
			get_sigquit();
		head = input;
		if (check_input_isempty(&head, input))
			continue ;
		add_history(input);
		if (parse(head, &info))
		{
			free(input);
			continue ;
		}
		tmp_args = info.args;
		exec_args(&info);
		clear_input_args(&info, &input, &tmp_args);
	}
}

static void	run_tester(char *line, t_info *info)
{
	t_args	*tmp_args;

	if (!line)
		get_sigquit();
	if (*line == '\0' || *line == ' ')
		return ;
	if (parse(line, info))
		return ;
	tmp_args = info->args;
	exec_args(info);
	lst_args_clear(&tmp_args);
	info->args = NULL;
}

static void	init(t_info *info, char *shell_name)
{
	char	*pt;

	pt = ft_strrchr(shell_name, '/');
	++pt;
	info->shell_name = pt;
	info->envs = NULL;
	info->args = NULL;
	info->args_num = 0;
	info->exit_code = 0;
	info->cp_stdin = dup2(STDIN_FILENO, 100);
	info->cp_stdout = dup2(STDOUT_FILENO, 101);
	info->cmd_line = ft_strjoin(info->shell_name, "$ ");
	if (!info->cmd_line || info->cp_stdin == -1 || info->cp_stdout == -1)
		exit_strerror();
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	init(&info, argv[0]);
	get_envp(envp, &info);
	if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
	{
		run_tester(argv[2], &info);
		exit(info.exit_code);
	}
	else
	{
		logo();
		run(info);
	}
	return (0);
}
