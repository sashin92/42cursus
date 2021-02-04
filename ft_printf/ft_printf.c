/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:06:20 by sashin            #+#    #+#             */
/*   Updated: 2021/02/04 13:55:28 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_flags_init(t_flag *flags)
{
	flags->minus_sign = 0;
	flags->plus_sign = 0;
	flags->star_sign = 0;
	flags->space_char = 0;
	flags->sharp_sign = 0;
	flags->zero_padding = 0;
	flags->precision = 0;
	flags->width = 0;
}

static int	printf_allocate_length(int width, int precision, va_list *ap)
{
	char	*val;
	char	*box;
	int		digit;


	val = ft_itoa(va_arg(*ap, int));
	digit = ft_strlen(val);
	if (digit > width && digit > precision)
	{
		ft_putstr_fd(val, 1);
		return (digit);
	}
	if (digit < precision && width < precision)
	{
		box = (char *)malloc(sizeof(char) * (precision - digit + 1));
	}
	return (0);
}

static int	printf_isvalid(char **format_head, va_list *ap)
{
	t_flag	*flags;
	int		width;
	int		precision;
	char	*val;
	char	*pt;
	int		digit;
	int		length;


	flags = (t_flag *)malloc(sizeof(t_flag));
	printf_flags_init(flags);
	width = 0;
	precision = 0;
	length = 0;

	pt = *format_head;

	while (*++pt)
	{
		if (*pt == '-')
			flags->minus_sign = 1;
		else if (*pt == '+')
			flags->plus_sign = 1;
		else if (*pt == ' ')
			flags->space_char = 1;
		else if (*pt == '#')
			flags->sharp_sign = 1;
		else
			break ;
	}

	if (*pt == '0')
	{
		flags->zero_padding = 1;
		++pt;
	}
	if (ft_isdigit(*pt))
	{
		while (ft_isdigit(*pt))
			width = width * 10 + (*pt++) - '0';
	}
	else if (*pt == '*')
	{
		width = va_arg(*ap, int);
		if (width < 0)
		{
			flags->minus_sign = 1;
			width = width * (-1);
			++pt;
		}
	}
	if (*pt == '.')
	{
		flags->precision = 1;
		++pt;
		if (ft_isdigit(*pt))
		{
			while (ft_isdigit(*pt))
				precision = precision * 10 + (*pt++) - '0';
		}
		else if (*pt == '*')
		{
			precision = va_arg(*ap, int);
			if (precision < 0)
			{
				flags->precision = 1;
				precision = precision * (-1);
				++pt;
			}
		}
	}
	else if (*pt == 'd')
	{
		
		length += printf_allocate_length(width, precision, ap);
	}
	else
		write(1, "\nwrong\n", 7);
	*format_head = pt;
	return (length);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*format_head;
	int			ret;

	ret = 0;
	format_head = (char *)format;
	va_start(ap, format);
	while (*format_head)
	{
		if (*format_head == '%')
			ret += printf_isvalid(&format_head, &ap);
		else
		{
			ft_putchar_fd(*format_head, 1);
			++ret;
		}
		++format_head;
	}
	va_end(ap);
	return (ret);
}
