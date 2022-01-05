/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_divide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:22:47 by sashin            #+#    #+#             */
/*   Updated: 2021/12/30 17:37:41 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>

static char	*get_value_dup(char *env, int key_len, int env_len)
{
	char	*value;

	value = NULL;
	if (env_len == (key_len + 1))
	{
		value = ft_strnew();
		if (!value)
			exit_strerror();
	}
	else if (env_len > (key_len + 1))
	{
		value = ft_substr(env, (key_len + 1), env_len - key_len - 1);
		if (!value)
			exit_strerror();
	}
	return (value);
}

t_envs	*env_parse_key_value(char *env)
{
	char	*key;
	char	*value;
	int		key_len;
	int		env_len;

	key_len = 0;
	env_len = ft_strlen(env);
	while (env[key_len] && env[key_len] != '=')
		++key_len;
	key = ft_substr(env, 0, key_len);
	if (!key)
		exit_strerror();
	if (key_len == env_len)
		value = NULL;
	else
		value = get_value_dup(env, key_len, env_len);
	return (lst_env_new(key, value));
}
