/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:51:26 by sashin            #+#    #+#             */
/*   Updated: 2021/12/30 19:12:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>
#include <unistd.h>

static void	set_envs(t_info *info)
{
	envs_delete_oldpwd(info->envs, info);
	envs_renew_pwd(info->envs);
	envs_renew_shlvl(info);
}

int	get_envp(char **envp, t_info *info)
{
	int		i;
	t_envs	*env_new;

	env_new = NULL;
	i = 0;
	while (envp[i])
	{
		env_new = env_parse_key_value(envp[i]);
		lst_envs_add_back(&info->envs, env_new);
		++i;
	}
	set_envs(info);
	return (0);
}
