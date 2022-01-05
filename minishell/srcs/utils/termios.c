/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:10:25 by sashin            #+#    #+#             */
/*   Updated: 2021/12/29 16:50:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

void	termios_echoctl_off(void)
{
	struct termios	attr;

	if (isatty(STDOUT_FILENO))
	{
		tcgetattr(STDOUT_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDERR_FILENO))
	{
		tcgetattr(STDERR_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	}
}

void	termios_echoctl_on(void)
{
	struct termios	attr;

	if (isatty(STDOUT_FILENO))
	{
		tcgetattr(STDOUT_FILENO, &attr);
		attr.c_lflag = attr.c_lflag | ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &attr);
		attr.c_lflag = attr.c_lflag | ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDERR_FILENO))
	{
		tcgetattr(STDERR_FILENO, &attr);
		attr.c_lflag = attr.c_lflag | ECHOCTL;
		tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	}
}
