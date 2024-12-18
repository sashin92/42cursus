/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:30:09 by sashin            #+#    #+#             */
/*   Updated: 2021/01/01 14:01:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_isascii() tests that char c is ASCII or not.
*/

int				ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
