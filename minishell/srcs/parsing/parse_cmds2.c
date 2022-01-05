/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:22:49 by sashin            #+#    #+#             */
/*   Updated: 2022/01/03 15:41:55 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"
#include "minishell_utils.h"
#include <stdlib.h>

static int	cmdjoin(char **head, t_info *info, char **cmd)
{
	char	*tmp;
	int		err_flag;
	int		len;

	len = 0;
	err_flag = 0;
	if (**head == '\'')
		err_flag = parsing_quote(head, info, cmd);
	else if (**head == '\"')
		err_flag = parsing_dquote(head, info, cmd);
	else if (**head == '$')
		parsing_dollar(head, info, cmd);
	else
	{
		while ((*head)[len] && \
				!check_isspc((*head)[len]) && !ft_isspace((*head)[len]))
			++len;
		tmp = ft_strnjoin(*cmd, *head, len);
		if (!tmp)
			exit_strerror();
		free(*cmd);
		*cmd = tmp;
		*head = &(*head)[len];
	}
	return (err_flag);
}

char	*get_cmd(char **head, t_info *info)
{
	char	*cmd;
	int		err_flag;

	cmd = ft_strnew();
	if (!cmd)
		exit_strerror();
	err_flag = 0;
	while (**head && !err_flag)
	{
		if (**head == '<' || **head == '>' || **head == '|' \
			|| ft_isspace(**head))
			break ;
		else
			err_flag = cmdjoin(head, info, &cmd);
	}
	if (err_flag)
	{
		free(cmd);
		return (NULL);
	}
	while (**head && ft_isspace(**head))
		++(*head);
	return (cmd);
}
