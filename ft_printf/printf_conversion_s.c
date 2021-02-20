/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:04:57 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 14:05:05 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_conversion_s(va_list *ap, t_flag flags)
{
	char			*s;
	int				s_len;
	char			*val;

	s = va_arg(*ap, char *);
	s_len = ft_strlen(s);
	if (flags.precision < s_len && flags.dot_sign == 1)
		val = ft_substr(s, 0, flags.precision);
	else
		val = ft_strdup(s);
	return (val);
}
