/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitin_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:56:30 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 13:56:30 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>

static int	arg_isvalid(char *argv)
{
	int		i;

	i = 0;
	if (!ft_isalpha(argv[i]) && argv[i] != '_')
		return (0);
	++i;
	while (argv[i])
	{
		if (argv[i] == '=')
			break ;
		if (!ft_isalpha(argv[i]) && !ft_isdigit(argv[i]) && argv[i] != '_')
			return (0);
		++i;
	}
	if (argv[i])
		return (0);
	return (1);
}

int	builtin_unset(char **argv, t_info *info)
{
	int		i;
	t_envs	*head;

	i = 1;
	head = info->envs;
	while (argv[i])
	{
		if (!arg_isvalid(argv[i]))
			return (1);
		head = envs_search(info->envs, argv[i]);
		if (head != NULL)
			lst_envs_del_one(head, info);
		++i;
	}
	return (0);
}
