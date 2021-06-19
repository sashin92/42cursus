/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:45:40 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:44:21 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** ft_isprint() tests that char c is printable ASCII or not.
*/

int				ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
