/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:06:20 by sashin            #+#    #+#             */
/*   Updated: 2021/02/18 14:29:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_init_flags(t_flag *flags)
{
	flags->minus_sign = 0;
	flags->plus_sign = 0;
	flags->sharp_sign = 0;
	flags->space_char = 0;
	flags->zero_padding = 0;
	flags->star_sign = 0;
	flags->precision = 0;
	flags->width = 0;
}

int			printf_print(char *val, t_flag flags)
{
	int		val_len;
	int		count;

	val_len = ft_strlen(val);
	if (flags.width - val_len <= 0)
		ft_putstr_fd(val, 1);
	else
	{
		if (flags.minus_sign == 1)
		{
			ft_putstr_fd(val, 1);
		}
	}
	return (0);
}

int			printf_run(char **form, va_list *ap)
{
	t_flag		flags;
	int			ret;

	printf_init_flags(&flags);
	ret = 0;

	printf_check_flags(form, &flags);
	printf_check_width(form, ap, &flags);
	printf_check_precision(form, ap, &flags);

	if (ft_strchr("d", **form))
		printf_conversion_d(ap, flags);
	else
		ft_putstr_fd("wrong", 1);
	*form += sizeof(char);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*form;
	int			ret;

	va_start(ap, format);
	form = (char *)format;
	ret = 0;
	while (*form)
	{
		if (*form == '%')
		{
			++form;
			ret += printf_run(&form, &ap);
		}
		else
		{
			write(1, form, 1);
			++form;
			++ret;
		}
	}
	va_end(ap);
	return (ret);
}
