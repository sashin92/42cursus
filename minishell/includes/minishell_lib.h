/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:56:37 by sashin            #+#    #+#             */
/*   Updated: 2021/12/26 15:56:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LIB_H
# define MINISHELL_LIB_H

# include <stddef.h>

int		ft_isspace(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);

void	*ft_memset(void *b, int c, size_t len);

/*
** Malloc Function
*/
char	*ft_itoa(int n);
char	*ft_strnew(void);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, size_t s2_len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_dfree(char **var);

#endif