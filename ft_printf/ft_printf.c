/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:06:20 by sashin            #+#    #+#             */
/*   Updated: 2021/02/20 14:59:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_putchar_padding(t_flag flags, int val_len)
{
	int			idx;

	idx = 0;
	while (flags.width - val_len - idx > 0)
	{
		ft_putchar_fd(flags.zero_padding, 1);
		++idx;
	}
}

int			printf_print(char *val, t_flag flags)
{
	int		val_len;

	val_len = ft_strlen(val);
	if (flags.width - val_len <= 0)
		ft_putstr_fd(val, 1);
	else
	{
		if (flags.minus_sign == 1)
		{
			ft_putstr_fd(val, 1);
			printf_putchar_padding(flags, val_len);
		}
		else if (flags.minus_sign == 0)
		{
			if (val[0] == '-' && flags.zero_padding == '0')
				ft_putchar_fd(*val++, 1);
			printf_putchar_padding(flags, val_len);
			ft_putstr_fd(val, 1);
		}
		return (flags.width);
	}
	return (val_len);
}

char		*printf_conversion(char **form, va_list *ap, t_flag flags)
{
	char		*val;

	val = ft_strdup("");
	if (ft_strchr("di", **form))
		val = printf_conversion_d(ap, flags);
	else if (ft_strchr("u", **form))
		val = printf_conversion_u(ap, flags);
	else if (ft_strchr("x", **form))
		val = printf_conversion_x(ap, flags);
	else if (ft_strchr("X", **form))
		val = printf_conversion_x_large(ap, flags);
	else if (ft_strchr("c", **form))
		val = printf_conversion_c(ap);
	else if (ft_strchr("s", **form))
		val = printf_conversion_s(ap, flags);
	else if (ft_strchr("p", **form))
		val = printf_conversion_p(ap, flags);
	else if (ft_strchr("%", **form))
		val = printf_conversion_percent();
	else
		ft_putstr_fd("wrong", 1);
	*form += sizeof(char);
	return (val);
}

int			printf_run(char **form, va_list *ap)
{
	t_flag		flags;
	char		*val;
	int			ret;

	printf_init_flags(&flags);
	printf_check_flags(form, &flags);
	printf_check_width(form, ap, &flags);
	printf_check_precision(form, ap, &flags);
	val = printf_conversion(form, ap, flags);
	ret = printf_print(val, flags);
	free(val);
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
			ft_putchar_fd(*form, 1);
			++form;
			++ret;
		}
	}
	va_end(ap);
	return (ret);
}
