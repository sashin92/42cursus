/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:52:51 by sashin            #+#    #+#             */
/*   Updated: 2021/11/26 17:24:34 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			error_msg(int err_flag)
{
	if (err_flag < 0)
	{
		if (err_flag == -1)
			ft_putstr_fd("Please input valid arg\n", 2);
		else if (err_flag == -2)
			ft_putstr_fd("Malloc error\n", 2);
		else if (err_flag == -3)
			ft_putstr_fd("mutex init error\n", 2);
		else if (err_flag == -4)
			ft_putstr_fd("mutex destroy error\n", 2);
		else if (err_flag == -5)
			ft_putstr_fd("gettimeofday error\n", 2);
		return (1);
	}
	return (0);
}

// int				error_function_msg(int err_flag, void (*f)(void))
// {
// 	if (f)
// 		f();
// 	error_msg(err_flag);
// 	return (1);
// }