/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:00:58 by sashin            #+#    #+#             */
/*   Updated: 2021/06/25 18:11:26 by sashin           ###   ########.fr       */
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
	int				i;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

/*
** dlist.c
*/
t_dlist				*ft_dlstnew(int content, int i);
void				ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void				ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
t_dlist				*ft_dlstlast(t_dlist *dlst);
int					ft_dlstsize(t_dlist *dlst);
void				ft_dlstfree(t_dlist *dlst);

/*
** controls.c
*/
void				ct_rev_rotater(t_dlist **dlst);
void				ct_rotater(t_dlist **dlst);
void				ct_swapper(t_dlist **dlst);
void				ct_pusher(t_dlist **src_dlst, t_dlist **dest_dlst);

/*
** parse.c
*/
t_dlist				*parse(int argc, char **argv);

#endif
