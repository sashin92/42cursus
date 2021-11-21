/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:06:38 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 13:11:31 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_sa_rra(t_all *s)
{
	ra(s);
	sa(s);
	rra(s);
}

void	ra_sa_rra_sa(t_all *s)
{
	ra(s);
	sa(s);
	rra(s);
	sa(s);
}

void	sa_ra_sa_rra(t_all *s)
{
	sa(s);
	ra(s);
	sa(s);
	rra(s);
}

void	sa_ra_sa_rra_sa(t_all *s)
{
	sa(s);
	ra(s);
	sa(s);
	rra(s);
	sa(s);
}
