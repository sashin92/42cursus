/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:06:20 by sashin            #+#    #+#             */
/*   Updated: 2021/02/08 18:38:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 주의
#include <stdio.h>
// 주의

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

// int			printf_handle_flags(va_list *ap, t_flag *flags)
// {
	
// }

static int	printf_allocate_length(t_flag *flags, va_list *ap)
{
	char	*val;
	char	*buf;
	int		digit;
	int		idx;

	idx = 0;

	val = ft_itoa(va_arg(*ap, int));
	digit = ft_strlen(val);
	// 대소비교
	// flags->width flags->precision, 
	// 크기가 다 같을때?, ("%4.4d", 1234); 일 때, 
	if (flags->precision >= flags->width)
	{
		
	}
	if (digit < flags->precision && flags->width < flags->precision)
	{
		buf = (char *)malloc(sizeof(char) * (flags->precision - digit + 1));
	}
	return (0);
}

// int			printf_check_flags()
// {
	
// }

int			printf_check_flag(t_flag *flags, char *pt)
{
	if (*pt == '-')
		flags->minus_sign = 1;
	else if (*pt == '+')
		flags->plus_sign = 1;
	else if (*pt == ' ')
		flags->space_char = 1;
	else if (*pt == '#')
		flags->sharp_sign = 1;
	else if (*pt == '0')
		flags->zero_padding = 1;
	else
		return (0);
	return (1);
}

static int	printf_isvalid(char **format_head, va_list *ap)
{
	t_flag	*flags;
	char	*val;
	char	*pt;
	int		digit;
	int		length;


	flags = (t_flag *)malloc(sizeof(t_flag));
	printf_flags_init(flags);
	length = 0;

	pt = *format_head;

	while (printf_check_flag(flags, pt)) // 플래그 확인
		++pt;
	flags->width += '0';
	write (1, &flags->width, 1);

	if (ft_isdigit(*pt)) // 넓이 확인
	{
		while (ft_isdigit(*pt))
			flags->width = flags->width * 10 + (*pt++) - '0';
	}
	else if (*pt == '*')
	{
		flags->width = va_arg(*ap, int);
		if (flags->width < 0)
		{
			flags->minus_sign = 1;
			flags->width = flags->width * (-1);
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
				flags->precision = flags->precision * 10 + (*pt++) - '0';
		}
		else if (*pt == '*')
		{
			flags->precision = va_arg(*ap, int);
			if (flags->precision < 0) // invalid
			{
				return (-1);
				flags->precision = flags->precision * (-1);
				++pt;
			}
		}
	}
	// printf_handle_flags();
	else if (*pt == 'd')
		length += printf_allocate_length(flags, ap);
	else
		write(1, "\nwrong\n", 7);
	*format_head = pt;
	return (length);
}



int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	char		*format_head;

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
