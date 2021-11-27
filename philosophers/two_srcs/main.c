/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:38:55 by sashin            #+#    #+#             */
/*   Updated: 2021/11/27 18:59:16 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		check_parse(&info, argc, argv);
		if (info.err_flag == 0)
			run(&info);
		if (info.err_flag < 0)
			return (error_msg(info.err_flag));
	}
	else
	{
		ft_putstr_fd("Please Input valid data.\n", 2);
		return (1);
	}
	return (0);
}