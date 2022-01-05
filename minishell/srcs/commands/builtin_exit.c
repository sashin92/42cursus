/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/23 17:12:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>

static int	llnum_isvalid(char c, unsigned long long *ret, int sign)
{
	if (!ft_isdigit(c))
	{
		return (1);
	}
	(*ret) = (*ret) * 10 + (c - '0');
	if (((*ret) > 9223372036854775808ULL && sign == -1) || \
			((*ret) > 9223372036854775807ULL && sign == 1))
	{
		return (1);
	}
	return (0);
}

static int	isllnum(char *str)
{
	int					i;
	int					sign;
	unsigned long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		++i;
		if (str[i] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (llnum_isvalid(str[i], &ret, sign))
			return (0);
		++i;
	}
	return (1);
}

static long long	ft_atoll(char *str)
{
	int					i;
	int					sign;
	unsigned long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			break ;
		ret = ret * 10 + (str[i] - '0');
		++i;
	}
	ret = ret * sign;
	return (ret);
}

static void	exit_arg_one(t_info *info)
{
	ft_putstr_fd("exit\n", 2);
	exit(info->exit_code);
}

int	builtin_exit(char **argv, t_info *info)
{
	int			argc;
	long long	exit_num;

	argc = 0;
	while (argv[argc])
		++argc;
	if (argc == 1)
		exit_arg_one(info);
	if (argc > 2 && isllnum(argv[1]))
		error_msg(info->shell_name, argv[0], NULL, "too many arguments");
	else if (argc > 1 && !isllnum(argv[1]))
	{
		error_msg(info->shell_name, argv[0], argv[1], \
					"numeric argument required");
		exit(255);
	}
	else
	{
		exit_num = ft_atoll(argv[1]);
		ft_putstr_fd("exit\n", 2);
		exit((int)exit_num);
	}
	return (1);
}
