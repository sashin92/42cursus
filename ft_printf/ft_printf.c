/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:06:20 by sashin            #+#    #+#             */
/*   Updated: 2021/01/28 22:29:34 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printf_witdh(const char *type)
{
	
}



static int	printf_isvalid_flag(const char *format)
{
	t_flag	*flag;
	int		count;

	count = 0;
	while (*format == '-')
	{
		flag->minus = 1;
		++format;
	}
	if (ft_isdigit(*format))
	{
		ft_atoi(format);
	}
	if (*format)
}

static int	printf_parsing()
{
	if 
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			length;

	pt = format;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			printf_isvalid_flag(++format);
		else
			ft_putchar_fd(*pt, 1);
		++pt;
	}
	va_end(ap);

	return (length);
}
