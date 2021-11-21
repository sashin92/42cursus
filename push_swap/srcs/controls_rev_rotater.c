/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_rev_rotater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 06:12:06 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 10:24:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_all *s)
{
	ct_rev_rotater(&s->a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_all *s)
{
	ct_rev_rotater(&s->b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_all *s)
{
	ct_rev_rotater(&s->a);
	ct_rev_rotater(&s->b);
	ft_putendl_fd("rrr", 1);
}