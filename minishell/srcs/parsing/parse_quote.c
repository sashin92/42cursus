/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:17:28 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 11:52:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parsing.h"
#include "minishell_utils.h"
#include <stdlib.h>

static int	quote_strlen_end_pt(char **head)
{
	int		count;

	count = 0;
	while (**head)
	{
		if (**head == '\'')
			break ;
		++(*head);
		++count;
	}
	return (count);
}

int	parsing_quote(char **parsing_point, t_info *info, char **cmd)
{
	int		count;
	char	*tmp;
	char	*head;

	++(*parsing_point);
	head = *parsing_point;
	count = quote_strlen_end_pt(&head);
	if (*head == '\'')
	{
		++head;
		tmp = ft_strnjoin(*cmd, *parsing_point, count);
		if (!tmp)
			exit_strerror();
	}
	else
	{
		error_msg(info->shell_name, NULL, \
			"syntax error", "quotes must be closed");
		return (-1);
	}
	*parsing_point = head;
	free(*cmd);
	*cmd = tmp;
	return (0);
}
