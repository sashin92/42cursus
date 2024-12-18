/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:24:41 by sashin            #+#    #+#             */
/*   Updated: 2021/12/20 09:39:10 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_macros_structs.h"
# include "minishell_utils.h"
# include "minishell_parsing.h"
# include "minishell_exec.h"

void	logo(void);
int		parse(char *input, t_info *info);
void	exec_args(t_info *info);

#endif