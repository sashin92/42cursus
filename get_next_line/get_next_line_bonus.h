/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:27:46 by sashin            #+#    #+#             */
/*   Updated: 2021/01/13 22:33:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int				get_next_line(int fd, char **line);

char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(char const *str);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
