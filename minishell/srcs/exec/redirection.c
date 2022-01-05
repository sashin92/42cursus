/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:15:31 by sashin            #+#    #+#             */
/*   Updated: 2022/01/05 13:33:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include "minishell_parsing.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <signal.h>

static char	*open_file_and_write(t_cmds *cmds, int *tmp_stdout)
{
	char	*file;
	int		fd;

	file = cmds->cmd;
	fd = 0;
	if (*tmp_stdout)
		close(*tmp_stdout);
	*tmp_stdout = dup(STDOUT_FILENO);
	if (cmds->redir == RR_REDIR)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (cmds->redir == R_REDIR)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (file);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static char	*open_file_and_read(t_cmds *cmds, int *tmp_stdin)
{
	char	*file;
	int		fd;

	file = cmds->cmd;
	fd = 0;
	if (*tmp_stdin)
		close(*tmp_stdin);
	*tmp_stdin = dup(STDIN_FILENO);
	if (cmds->redir == L_REDIR)
		fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		return (file);
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

char	*redirection(t_info *info, int *tmp_stdin, int *tmp_stdout)
{
	t_cmds	*head;
	char	*ret;

	head = info->args->cmds;
	ret = NULL;
	while (head && !ret)
	{
		if (head->redir == R_REDIR || head->redir == RR_REDIR)
			ret = open_file_and_write(head, tmp_stdout);
		else if (head->redir == L_REDIR)
			ret = open_file_and_read(head, tmp_stdin);
		else if (head->redir == LL_REDIR)
			ret = heredoc(tmp_stdin, tmp_stdout, head->cmd, info);
		head = head->next;
	}
	if (ret)
		return (ret);
	return (NULL);
}
