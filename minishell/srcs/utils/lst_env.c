/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:18:07 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 15:18:07 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <unistd.h>
#include <stdlib.h>

void	lst_envs_add_back(t_envs **envs, t_envs *new)
{
	t_envs	*temp;

	if (*envs == NULL)
		*envs = new;
	else
	{
		temp = *envs;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	lst_envs_clear(t_envs **envs)
{
	t_envs	*temp;
	t_envs	*head;

	head = *envs;
	while (head)
	{
		temp = head->next;
		free(head->key);
		free(head->value);
		head->key = NULL;
		head->value = NULL;
		free(head);
		head = temp;
	}
	free(*envs);
	*envs = NULL;
}

t_envs	*lst_env_new(char *key, char *value)
{
	t_envs	*new;

	new = (t_envs *)malloc(sizeof(t_envs));
	if (!new)
		exit_strerror();
	ft_memset(new, 0, sizeof(t_envs));
	new->key = key;
	new->value = value;
	return (new);
}

void	lst_envs_del_one(t_envs *target, t_info *info)
{
	t_envs	*head;

	head = info->envs;
	if (info->envs == target)
	{
		info->envs = target->next;
		free(target->key);
		free(target->value);
		free(target);
	}
	else
	{
		while (head && head->next != target)
			head = head->next;
		head->next = target->next;
		free(target->key);
		free(target->value);
		free(target);
	}
}
