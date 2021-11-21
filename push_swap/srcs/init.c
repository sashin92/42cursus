/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:53:31 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 10:54:06 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_s(t_all *s)
{
	s->a = NULL;
	s->b = NULL;
}

void	init_count(t_count *count)
{
	count->ra = 0;
	count->rb = 0;
	count->pa = 0;
	count->pb = 0;
	count->pivot_one = 0;
	count->pivot_two = 0;
}