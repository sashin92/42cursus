/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_combine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:22:09 by sashin            #+#    #+#             */
/*   Updated: 2021/12/28 16:08:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <stdlib.h>

static char	*env_combine_key_value(t_envs *head)
{
	char	*key_equal;
	char	*key_equal_value;

	key_equal = ft_strjoin(head->key, "=");
	if (!key_equal)
		return (NULL);
	key_equal_value = ft_strjoin(key_equal, head->value);
	if (!key_equal_value)
	{
		free(key_equal);
		return (NULL);
	}
	free(key_equal);
	return (key_equal_value);
}

static int	envs_get_size(t_envs *envs)
{
	t_envs	*head;
	int		size;

	size = 0;
	head = envs;
	while (head)
	{
		if (head->value)
			++size;
		head = head->next;
	}
	return (size);
}

static int	envs_get_char_envs(t_envs *envs, char **ret)
{
	t_envs	*head;
	int		i;

	head = envs;
	i = 0;
	while (head)
	{
		if (head->value)
		{
			ret[i] = env_combine_key_value(head);
			if (!ret[i])
			{
				ft_dfree(ret);
				return (1);
			}
			++i;
		}
		head = head->next;
	}
	ret[i] = NULL;
	return (0);
}

char	**envs_combine_key_value(t_envs *envs)
{
	char	**ret;
	int		size;

	size = envs_get_size(envs);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		exit_strerror();
	ft_memset(ret, 0, (sizeof(char *) * (size + 1)));
	if (envs_get_char_envs(envs, ret))
		return (NULL);
	return (ret);
}
