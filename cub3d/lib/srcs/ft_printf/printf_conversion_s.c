/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:04:57 by sashin            #+#    #+#             */
/*   Updated: 2021/04/19 16:43:16 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*printf_conversion_s(va_list ap, t_flag *flags)
{
	char			*s;
	int				s_len;
	char			*val;

	s = va_arg(ap, char *);
	if (s == 0)
		s = ft_strdup("(null)");
	s_len = ft_strlen(s);
	if (flags->precision >= 0 && flags->precision < s_len
		&& flags->dot_sign == 1)
		val = ft_substr(s, 0, flags->precision);
	else
		val = ft_strdup(s);
	return (val);
}
