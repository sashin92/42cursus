/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:17:31 by sashin            #+#    #+#             */
/*   Updated: 2021/12/16 17:17:31 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"
#include "minishell_utils.h"
#include <stdlib.h>

static int	dquote_strlen_end_or_dollar_pt(char **head)
{
	int		count;

	count = 0;
	while (**head)
	{
		if (**head == '\"' || **head == '$')
			break ;
		++(*head);
		++count;
	}
	return (count);
}

static void	dquote_join(char **parsing_point, char **head, char **cmd)
{
	int		count;
	char	*tmp;

	count = dquote_strlen_end_or_dollar_pt(head);
	tmp = ft_strnjoin(*cmd, *parsing_point, count);
	if (!tmp)
		exit_strerror();
	free(*cmd);
	*cmd = tmp;
}

static int	check_dquote_error(char **parsing_point, char **head, t_info *info)
{
	if (!**head)
	{
		error_msg(info->shell_name, NULL, \
			"syntax error", "dquotes must be closed");
		return (-1);
	}
	++(*head);
	*parsing_point = *head;
	return (0);
}

int	parsing_dquote(char **parsing_point, t_info *info, char **cmd)
{
	char	*head;

	++(*parsing_point);
	head = *parsing_point;
	while (*head)
	{
		if (*head == '$')
		{
			parsing_dollar(&head, info, cmd);
			*parsing_point = head;
		}
		else if (*head == '\"')
			break ;
		else
		{
			dquote_join(parsing_point, &head, cmd);
			*parsing_point = head;
		}
	}
	return (check_dquote_error(parsing_point, &head, info));
}
