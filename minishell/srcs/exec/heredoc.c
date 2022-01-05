/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:15:31 by sashin            #+#    #+#             */
/*   Updated: 2022/01/05 13:41:20 by sashin           ###   ########.fr       */
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

static char	*set_heredoc(char *input, int *tmp_stdin)
{
	int		fd[2];

	if (*tmp_stdin)
	{
		dup2(*tmp_stdin, STDIN_FILENO);
		close(*tmp_stdin);
	}
	*tmp_stdin = dup(STDIN_FILENO);
	pipe(fd);
	dup2(fd[0], STDIN_FILENO);
	ft_putstr_fd(input, fd[1]);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

static void	heredocjoin(char **head, t_info *info, char **result)
{
	char	*tmp;
	int		err_flag;
	int		len;

	len = 0;
	err_flag = 0;
	while (**head)
	{
		if (**head == '$')
			parsing_dollar(head, info, result);
		else
		{
			while ((*head)[len] && \
					!check_isspc((*head)[len]) && !ft_isspace((*head)[len]))
				++len;
			tmp = ft_strnjoin(*result, *head, len);
			free(*result);
			*result = tmp;
			*head = &(*head)[len];
		}
	}
	*head = ft_strrchr(*result, '\n');
	if (!*head)
		*head = *result;
}

static char	*loop_heredoc(char *str, char *result, \
							char *redir_str, t_info *info)
{
	char	*tmp;
	char	*head;
	char	*tmp_newline;

	while (1)
	{
		str = readline("> ");
		tmp = ft_strnew();
		head = str;
		check_exit_strerror(tmp);
		heredocjoin(&head, info, &tmp);
		if (!ft_strcmp(tmp, redir_str) || !str)
			break ;
		tmp_newline = ft_strjoin(tmp, "\n");
		check_exit_strerror(tmp_newline);
		free(tmp);
		tmp = ft_strjoin(result, tmp_newline);
		check_exit_strerror(tmp);
		free(result);
		result = tmp;
		free(str);
	}
	free(tmp);
	free(str);
	return (result);
}

static char	*exec_heredoc(char *redir_str, t_info *info)
{
	char	*str;
	char	*result;

	str = NULL;
	result = ft_strnew();
	if (!result)
		exit_strerror();
	signal(SIGQUIT, SIG_IGN);
	result = loop_heredoc(str, result, redir_str, info);
	signal(SIGQUIT, SIG_DFL);
	return (result);
}

char	*heredoc(int *tmp_stdin, int *tmp_stdout, \
						char *redir_str, t_info *info)
{
	char	*result;

	if (*tmp_stdin)
		close(*tmp_stdin);
	*tmp_stdin = dup(STDIN_FILENO);
	if (*tmp_stdout)
		close(*tmp_stdout);
	*tmp_stdout = dup(STDOUT_FILENO);
	dup2(info->cp_stdout, STDOUT_FILENO);
	result = exec_heredoc(redir_str, info);
	set_heredoc(result, tmp_stdin);
	dup2(*tmp_stdout, STDOUT_FILENO);
	return (0);
}
