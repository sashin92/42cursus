/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:49:34 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 09:37:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

# include "minishell_macros_structs.h"

t_envs	*parse_key_value(char *env);
int		parse(char *input, t_info *info);

void	parsing_dollar(char **parsing_point, t_info *info, char **arg);
int		parsing_quote(char **parsing_point, t_info *info, char **arg);
int		parsing_dquote(char **parsing_point, t_info *info, char **arg);

t_cmds	*parse_cmds(char **input, t_info *info);
char	*get_cmd(char **head, t_info *info);

#endif
