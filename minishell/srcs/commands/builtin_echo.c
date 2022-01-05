/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/17 09:43:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <unistd.h>

static int	echo_isn(char *argv)
{
	int		i;

	i = 0;
	if (argv[i] && argv[i] == '-')
	{
		++i;
		if (argv[i] && argv[i] == 'n')
		{
			while (argv[i] == 'n')
				++i;
			if (!argv[i])
				return (1);
		}
	}
	return (0);
}

int	builtin_echo(char **argv, t_info *info)
{
	int		i;
	int		option_n;
	int		flag;

	(void)info;
	option_n = 0;
	flag = 0;
	i = 0;
	while (argv[++i])
	{
		if (!echo_isn(argv[i]))
			break ;
		option_n = 1;
	}
	while (argv[i])
	{
		if (flag == 1)
			ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		flag = 1;
		++i;
	}
	if (option_n == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
