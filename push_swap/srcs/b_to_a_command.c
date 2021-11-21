/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:12:43 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 11:18:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb_rb_sb_rrb_sb(t_all *s)
{
	sb(s);
	rb(s);
	sb(s);
	rrb(s);
	sb(s);
}

void	sb_rb_sb_rrb(t_all *s)
{
	sb(s);
	rb(s);
	sb(s);
	rrb(s);
}

void	rb_sb_rrb_sb(t_all *s)
{
	rb(s);
	sb(s);
	rrb(s);
	sb(s);
}

void	rb_sb_rrb(t_all *s)
{
	rb(s);
	sb(s);
	rrb(s);
}