/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:12:57 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 12:02:07 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

# include "minishell_macros_structs.h"
# include "minishell_lib.h"
# include <stddef.h>

char	*heredoc(int *tmp_stdin, int *tmp_stdout, \
					char *redir_str, t_info *info);
/*
** check and search
*/
int		check_isspc(char c);
int		check_isspc_in_str(char *content);
t_envs	*envs_search(t_envs *envs, char *str);
int		check_builtin(char **cmds);
int		check_input_isempty(char **head, char *input);

/*
** envs related functions
*/
void	lst_envs_add_back(t_envs **envs, t_envs *new);
void	lst_envs_clear(t_envs **envs);
t_envs	*lst_env_new(char *key, char *value);
void	lst_envs_del_one(t_envs *target, t_info *info);

int		get_envp(char **envp, t_info *info);

void	envs_renew_pwd(t_envs *envs);
void	envs_renew_shlvl(t_info *info);
void	envs_delete_oldpwd(t_envs *envs, t_info *info);

char	**envs_combine_key_value(t_envs *envs);

t_envs	*env_parse_key_value(char *env);

/*
** cmds related funcitons
*/
t_cmds	*lst_cmds_new(char *cmd, int redir);
void	lst_cmds_add_back(t_cmds **cmds, t_cmds *new);
void	lst_cmds_clear(t_cmds **cmds);
char	**cmds_to_argv(t_cmds *cmds);

/*
** args related funcitons
*/
t_args	*lst_args_new(t_cmds *cmds);
void	lst_args_add_back(t_args **args, t_args *new);
void	lst_args_clear(t_args **args);

/*
** error and exit
*/
void	error_msg(char *shell, char *program, char *arg, char *custom_msg);
void	exit_strerror(void);
void	check_exit_strerror(char *s);
int		return_msg(char *str);
void	error_exec_fail_msg(t_info *info, char *program);
/*
** signal, termios
*/
void	sig_function(int signum);
void	sig_ignore(int signum);
void	get_sigquit(void);
void	signal_reset(void);

void	termios_echoctl_off(void);
void	termios_echoctl_on(void);

#endif
