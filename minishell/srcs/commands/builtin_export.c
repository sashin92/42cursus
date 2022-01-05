/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/23 19:00:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdio.h>
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
	return (1);
}

static void	print_export(t_envs *head)
{
	while (head)
	{
		if (head->value)
			printf("declare -x %s=\"%s\"\n", head->key, head->value);
		else
			printf("declare -x %s\n", head->key);
		head = head->next;
	}
}

static void	export_fix(t_envs *head, t_envs *new)
{
	if (new->value)
	{
		if (head->value)
		{
			free(head->value);
			head->value = NULL;
		}
		head->value = ft_strdup(new->value);
		if (!head->value)
			exit_strerror();
	}
	free(new->key);
	free(new->value);
	free(new);
}

static int	export_set(char **argv, t_info *info)
{
	t_envs	*new;
	t_envs	*search_result;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (argv[++i])
	{
		if (!arg_isvalid(argv[i]))
		{
			error_msg(info->shell_name, "export", argv[i], \
						"not a valid identifier");
			flag = 1;
			continue ;
		}
		new = env_parse_key_value(argv[i]);
		search_result = envs_search(info->envs, new->key);
		if (search_result)
			export_fix(search_result, new);
		else
			lst_envs_add_back(&info->envs, new);
	}
	return (flag);
}

int	builtin_export(char **argv, t_info *info)
{
	int		argc;
	t_envs	*head;

	argc = 0;
	head = info->envs;
	while (argv[argc])
		++argc;
	if (argc == 1)
		print_export(head);
	else
	{
		if (export_set(argv, info))
			return (1);
	}
	return (0);
}
