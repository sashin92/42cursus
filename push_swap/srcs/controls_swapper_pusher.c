/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_swapper_pusher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 06:12:06 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 10:24:45 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_all *s)
{
	ct_swapper(&s->a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_all *s)
{
	ct_swapper(&s->b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_all *s)
{
	ct_swapper(&s->a);
	ct_swapper(&s->b);
	ft_putendl_fd("ss", 1);
}

void	pa(t_all *s)
{
	ct_pusher(&s->b, &s->a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_all *s)
{
	ct_pusher(&s->a, &s->b);
	ft_putendl_fd("pb", 1);
}