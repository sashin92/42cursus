/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:35:14 by sashin            #+#    #+#             */
/*   Updated: 2021/06/18 18:20:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

/*
** tools.c in tools folder
*/
int		ft_isdigit(char c);
int		ft_atoi(char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_power(int num, int pow);

/*
** ft_itoa.c in tools folder
*/
char	*ft_itoa(int n);

#endif
