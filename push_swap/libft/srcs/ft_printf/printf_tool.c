/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:30:19 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:33:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	printf_base_len(long long num, int base)
{
	int			len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / base;
		++len;
	}
	return (len);
}

int	printf_atoi(char **form)
{
	int			num;
	int			sign;

	num = 0;
	sign = 1;
	while (**form == '-')
	{
		sign = -1;
		*form += sizeof(char);
	}
	while (ft_isdigit(**form))
	{
		num = (num * 10) + (**form - '0');
		*form += sizeof(char);
	}
	return (sign * num);
}

char	*printf_itoa_base(long long num, char *val, int num_len, char *base)
{
	int			base_len;

	base_len = 0;
	while (base[base_len])
		++base_len;
	val[num_len] = '\0';
	--num_len;
	while (num_len >= 0 && val[num_len] != '-')
	{
		val[num_len] = base[num % base_len];
		num = num / base_len;
		--num_len;
	}
	return (val);
}

void	printf_putchar_padding(t_flag flags, int *val_len)
{
	int			idx;

	idx = 0;
	if (flags.null_char == 1)
	{
		if (flags.minus_sign == 1)
			ft_putchar_fd('\0', 1);
		*val_len += 1;
	}
	while (flags.width - *val_len - idx > 0)
	{
		ft_putchar_fd(flags.zero_padding, 1);
		++idx;
	}
	if (flags.null_char == 1 && flags.minus_sign == 0)
		ft_putchar_fd('\0', 1);
}
