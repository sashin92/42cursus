/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:24:44 by sashin            #+#    #+#             */
/*   Updated: 2021/12/08 18:58:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	char *input;

	while (1)
	{
		input = readline("shell$>");
		printf(" -> %s\n", input);
		add_history(input);
		free(input);
	}
	return (0);
}