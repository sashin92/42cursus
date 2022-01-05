/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 12:06:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	builtin_pwd(char **argv, t_info *info)
{
	char	pwd[PATH_MAX + 1];

	if (!getcwd(pwd, PATH_MAX))
	{
		error_msg(info->shell_name, argv[0], NULL, NULL);
		return (1);
	}
	ft_putstr_fd(pwd, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
