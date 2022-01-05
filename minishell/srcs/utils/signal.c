/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:44:08 by sashin            #+#    #+#             */
/*   Updated: 2021/12/30 13:52:34 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	signal_reset(void)
{
	signal(SIGINT, sig_function);
	signal(SIGTERM, sig_function);
	signal(SIGQUIT, SIG_IGN);
}

void	get_sigquit(void)
{
	printf("exit\n");
	termios_echoctl_on();
	exit(0);
}

void	sig_function(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		signal(SIGINT, sig_function);
	}
	else if (signum == SIGTERM)
	{
		termios_echoctl_on();
		printf("minishell is terminated by 'SIGTERM'\n");
		exit(255);
	}
}
