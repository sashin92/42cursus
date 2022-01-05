/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:18:57 by sashin            #+#    #+#             */
/*   Updated: 2021/12/23 10:04:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"
#include "minishell_utils.h"
#include <stdlib.h>

static void	dollar_join(char **cmd)
{
	char	*tmp;

	tmp = ft_strjoin(*cmd, "$");
	if (!tmp)
		exit_strerror();
	free(*cmd);
	*cmd = tmp;
}

static void	ext_code_join(char **cmd, t_info *info)
{
	char	*itoa;
	char	*tmp;

	itoa = ft_itoa(info->exit_code);
	if (!itoa)
		exit_strerror();
	tmp = ft_strjoin(*cmd, itoa);
	if (!tmp)
		exit_strerror();
	free(*cmd);
	free(itoa);
	*cmd = tmp;
}

static void	env_join(char **cmd, char **parsing_point, t_info *info)
{
	t_envs	*search;
	char	*head;
	char	*tmp;
	char	*env_key;
	int		i;

	head = *parsing_point;
	i = 0;
	while (head[i] && (ft_isalpha(head[i]) || ft_isdigit(head[i])))
		++i;
	env_key = ft_substr(head, 0, i);
	if (!env_key)
		exit_strerror();
	search = envs_search(info->envs, env_key);
	free(env_key);
	if (search && search->value)
	{
		tmp = ft_strjoin(*cmd, search->value);
		free(*cmd);
		*cmd = tmp;
	}
	*parsing_point = &head[i];
}

void	parsing_dollar(char **parsing_point, t_info *info, char **cmd)
{
	++(*parsing_point);
	if (!**parsing_point || **parsing_point == '\"' \
			|| ft_isspace(**parsing_point))
		dollar_join(cmd);
	else if (**parsing_point == '?')
	{
		ext_code_join(cmd, info);
		++(*parsing_point);
	}
	else if (ft_isdigit(**parsing_point))
		++(*parsing_point);
	else if (!ft_isalpha(**parsing_point))
		return ;
	else
		env_join(cmd, parsing_point, info);
}
