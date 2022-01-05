/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_macros_structs.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:43:39 by sashin            #+#    #+#             */
/*   Updated: 2021/12/24 16:56:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MACROS_STRUCTS_H
# define MINISHELL_MACROS_STRUCTS_H

# define L_REDIR 1
# define R_REDIR 2
# define LL_REDIR 3
# define RR_REDIR 4
# define PIPE 5
# define QUOTE 6
# define DQUOTE 7
# define DOLLAR 8
# define TRUE 1
# define FALSE 0

# define RST "\x1B[0m"
# define BRI "\x1B[1m"
# define DIM "\x1B[2m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"

typedef struct s_envs
{
	char			*key;
	char			*value;
	struct s_envs	*next;
}					t_envs;

typedef struct s_cmds
{
	char			*cmd;
	int				redir;
	struct s_cmds	*next;
}					t_cmds;

typedef struct s_args
{
	t_cmds			*cmds;
	struct s_args	*next;
}					t_args;

typedef struct s_info
{
	char			*shell_name;
	char			*cmd_line;
	int				exit_code;
	t_envs			*envs;
	t_args			*args;
	int				args_num;
	int				cp_stdin;
	int				cp_stdout;
}					t_info;

#endif
