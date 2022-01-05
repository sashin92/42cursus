/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/17 09:43:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdio.h>

int	builtin_env(char **argv, t_info *info)
{
	int		argc;
	t_envs	*head;

	argc = 0;
	while (argv[argc])
		++argc;
	if (argc == 1)
	{
		head = info->envs;
		while (head)
		{
			if (head->value)
				printf("%s=%s\n", head->key, head->value);
			head = head->next;
		}
	}
	else if (argc > 1)
	{
		error_msg(info->shell_name, argv[0], NULL, "Too many arguments");
		return (1);
	}
	return (0);
}
