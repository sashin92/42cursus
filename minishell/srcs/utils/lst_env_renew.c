/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_renew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:27:36 by sashin            #+#    #+#             */
/*   Updated: 2022/01/01 11:15:33 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static void	check_isshlvl(t_envs **envs)
{
	t_envs	*result;
	int		i;

	i = 0;
	result = *envs;
	while (result->value[i])
	{
		if (!ft_isdigit(result->value[i]))
		{
			free(result->value);
			result->value = NULL;
			break ;
		}
		++i;
	}
	*envs = result;
}

static void	update_shlvl(t_envs **envs)
{
	t_envs	*result;
	char	*tmp;
	int		num;

	result = *envs;
	num = 0;
	if (result->value != NULL)
	{
		num = ft_atoi(result->value);
		free(result->value);
		num += 1;
		tmp = ft_itoa(num);
		if (!tmp)
			exit_strerror();
		result->value = tmp;
	}
	else if (!result->value)
	{
		tmp = ft_strdup("1");
		if (!tmp)
			exit_strerror();
		result->value = tmp;
	}
	*envs = result;
}

void	envs_renew_shlvl(t_info *info)
{
	t_envs	*result;
	char	*tmp;
	char	*tmp_key;

	result = envs_search(info->envs, "SHLVL");
	if (result)
	{
		if (result->value)
		{
			check_isshlvl(&result);
			update_shlvl(&result);
		}
		else if (!result->value)
			update_shlvl(&result);
	}
	else
	{
		tmp_key = ft_strdup("SHLVL");
		tmp = ft_strdup("1");
		result = lst_env_new(tmp_key, tmp);
		if (!tmp_key || !tmp || !result)
			exit_strerror();
		lst_envs_add_back(&info->envs, result);
	}
}

void	envs_delete_oldpwd(t_envs *envs, t_info *info)
{
	t_envs	*result;

	result = envs_search(envs, "OLDPWD");
	if (result)
		lst_envs_del_one(result, info);
}

void	envs_renew_pwd(t_envs *envs)
{
	t_envs	*result;
	char	*tmp;
	char	*tmp_key;

	result = envs_search(envs, "PWD");
	if (result)
	{
		if (result->value)
			free(result->value);
		tmp = getcwd(NULL, PATH_MAX);
		if (!tmp)
			exit_strerror();
		result->value = tmp;
	}
	else if (!result)
	{
		tmp = getcwd(NULL, PATH_MAX);
		tmp_key = ft_strdup("PWD");
		if (!tmp || !tmp_key)
			exit_strerror();
		result = lst_env_new(tmp_key, tmp);
		lst_envs_add_back(&envs, result);
	}
}
