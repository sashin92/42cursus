/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/17 09:43:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include "minishell_builtins.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	cd_home(t_envs *head, t_info *info)
{
	head = envs_search(info->envs, "HOME");
	if (!head || !head->value)
	{
		error_msg(info->shell_name, "cd", NULL, "HOME not set");
		return (1);
	}
	if (chdir(head->value))
	{
		error_msg(info->shell_name, "cd", head->value, NULL);
		return (1);
	}
	return (0);
}

static int	cd_change_dir(char **argv, t_info *info)
{
	char	*dir;

	dir = ft_strdup(argv[1]);
	if (!dir)
		exit_strerror();
	if (chdir(dir))
	{
		error_msg(info->shell_name, argv[0], argv[1], NULL);
		free(dir);
		return (1);
	}
	free(dir);
	return (0);
}

int	builtin_cd(char **argv, t_info *info)
{
	int		argc;
	t_envs	*head;

	argc = 0;
	head = NULL;
	while (argv[argc])
		++argc;
	if (argc == 1 && cd_home(head, info))
		return (1);
	else if (argc >= 2)
	{
		if (cd_change_dir(argv, info))
			return (1);
	}
	envs_renew_pwd(info->envs);
	return (0);
}
