/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_rotater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 06:12:06 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 10:24:32 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_all *s)
{
	ct_rotater(&s->a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_all *s)
{
	ct_rotater(&s->b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_all *s)
{
	ct_rotater(&s->a);
	ct_rotater(&s->b);
	ft_putendl_fd("rr", 1);
}