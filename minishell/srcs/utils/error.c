/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 12:53:24 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <stdlib.h>

void	error_msg(char *shell, char *program, char *arg, char *custom_msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(shell, 2);
	ft_putstr_fd(": ", 2);
	if (program)
	{
		ft_putstr_fd(program, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (custom_msg)
	{
		ft_putstr_fd(custom_msg, 2);
		ft_putstr_fd("\n"RST, 2);
	}
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n"RST, 2);
	}
	errno = 0;
}

void	exit_strerror(void)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	check_exit_strerror(char *s)
{
	if (!s)
		exit_strerror();
}

int	return_msg(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

void	error_exec_fail_msg(t_info *info, char *program)
{
	if (errno == EACCES)
	{
		error_msg(info->shell_name, program, NULL, NULL);
		info->exit_code = 126;
	}
	else if (errno == ENOENT)
	{
		error_msg(info->shell_name, program, NULL, NULL);
		info->exit_code = 127;
	}
	else
	{
		error_msg(info->shell_name, program, NULL, "command not found");
		info->exit_code = 127;
	}
}
