/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:15:12 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 12:14:07 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include "minishell_macros_structs.h"

void	exec_args(t_info *info);

char	*redirection(t_info *info, int *tmp_stdin, int *tmp_stdout);
int		exec_command(char **parsed_argv, t_info *info, char **parsed_envs);
void	exec_program(char **parsed_argv, char **parsed_envs, t_info *info);

int		exec_programs_in_child(char **parsed_envs, t_info *info);

#endif