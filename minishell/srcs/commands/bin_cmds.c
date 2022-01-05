/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:15:31 by sashin            #+#    #+#             */
/*   Updated: 2022/01/05 15:29:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtins.h"
#include "minishell_utils.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>

static char	*set_path(char **arr_path, char *cmd)
{
	char		*path;
	char		*tmp;
	struct stat	sb;
	int			i;

	i = 0;
	path = NULL;
	tmp = NULL;
	while (arr_path[i])
	{
		tmp = ft_strjoin(arr_path[i], "/");
		if (!tmp)
			exit_strerror();
		path = ft_strjoin(tmp, cmd);
		if (!path)
			exit_strerror();
		free(tmp);
		if (stat(path, &sb) == 0)
			return (path);
		free(path);
		path = NULL;
		i++;
	}
	errno = 0;
	return (NULL);
}

static int	extern_cmd(char **parsed_argv, t_info *info, char **parsed_envs)
{
	t_envs		*env_path;
	char		**arr_path;
	char		*path;

	env_path = envs_search(info->envs, "PATH");
	if (parsed_argv[0] && ft_strrchr(parsed_argv[0], '/'))
		execve(parsed_argv[0], parsed_argv, parsed_envs);
	else if (env_path != NULL)
	{
		if (parsed_argv[0] && parsed_argv[0][0] && \
			ft_strcmp(parsed_argv[0], ".") && ft_strcmp(parsed_argv[0], ".."))
		{
			arr_path = ft_split(env_path->value, ':');
			if (!arr_path)
				exit_strerror();
			path = set_path(arr_path, parsed_argv[0]);
			if (!path)
				return (-1);
			execve(path, parsed_argv, parsed_envs);
			free(path);
			ft_dfree(arr_path);
		}
	}
	return (-1);
}

int	exec_command(char **parsed_argv, t_info *info, char **parsed_envs)
{
	if (!ft_strcmp(parsed_argv[0], "echo"))
		info->exit_code = builtin_echo(parsed_argv, info);
	else if (!ft_strcmp(parsed_argv[0], "cd"))
		info->exit_code = builtin_cd(parsed_argv, info);
	else if (!ft_strcmp(parsed_argv[0], "pwd"))
		info->exit_code = builtin_pwd(parsed_argv, info);
	else if (!ft_strcmp(parsed_argv[0], "export"))
		info->exit_code = builtin_export(parsed_argv, info);
	else if (!ft_strcmp(parsed_argv[0], "unset"))
		info->exit_code = builtin_unset(parsed_argv, info);
	else if (!ft_strcmp(parsed_argv[0], "env"))
		info->exit_code = builtin_env(parsed_argv, info);
	else if (!ft_strcmp(parsed_argv[0], "exit"))
		info->exit_code = builtin_exit(parsed_argv, info);
	else
	{
		if (extern_cmd(parsed_argv, info, parsed_envs))
			return (-1);
	}
	return (0);
}
