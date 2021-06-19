/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:00:58 by sashin            #+#    #+#             */
/*   Updated: 2021/06/19 20:35:55 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/includes/lib_sashin.h"

typedef struct		s_dlist
{
	int				content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

/*
** dlist.c
*/
t_dlist		*ft_dlstnew(int content);
void		ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void		ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
t_dlist		*ft_dlstlast(t_dlist *dlst);
void		ft_dlstfree(t_dlist *dlst);
// t_dlist		*ft_dlstfind(t_dlist *dlst, void *search);


#endif
