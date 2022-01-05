/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/17 09:43:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

# include "minishell_macros_structs.h"

int	builtin_cd(char **argv, t_info *info);
int	builtin_echo(char **argv, t_info *info);
int	builtin_env(char **argv, t_info *info);
int	builtin_exit(char **argv, t_info *info);
int	builtin_pwd(char **argv, t_info *info);
int	builtin_unset(char **argv, t_info *info);
int	builtin_export(char **argv, t_info *info);

#endif