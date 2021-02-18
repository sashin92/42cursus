/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:22:47 by sashin            #+#    #+#             */
/*   Updated: 2021/02/18 14:23:28 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_check_flags(char **form, t_flag *flags)
{
	while (1)
	{
		if (**form == '-')
			flags->minus_sign = 1;
		else if (**form == '+')
			flags->plus_sign = 1;
		else if (**form == '#')
			flags->sharp_sign = 1;
		else if (**form == ' ')
			flags->space_char = 1;
		else if (**form == '0')
			flags->zero_padding = 1;
		else
			break ;
		*form += sizeof(char);
	}
}

void		printf_check_width(char **form, va_list *ap, t_flag *flags)
{
	if (ft_isdigit(**form))
	{
		while (ft_isdigit(**form))
		{
			flags->width = (flags->width * 10) + (**form - '0');
			*form += sizeof(char);
		}
	}
	else if (**form == '*')
	{
		flags->width = va_arg(*ap, int);
		*form += sizeof(char);
	}
}

void		printf_check_precision(char **form, va_list *ap, t_flag *flags)
{
	if (**form == '.')
	{
		*form += sizeof(char);
		if (ft_isdigit(**form))
		{
			while (ft_isdigit(**form))
			{
				flags->precision = (flags->precision * 10) + (**form - '0');
				*form += sizeof(char);
			}
		}
		else if (**form == '*')
		{
			flags->precision = va_arg(*ap, int);
			*form += sizeof(char);
		}
	}
}