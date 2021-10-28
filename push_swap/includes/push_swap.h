/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:00:58 by sashin            #+#    #+#             */
/*   Updated: 2021/10/28 15:16:46 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/includes/lib_sashin.h"

typedef struct s_dlist
{
	int				content;
	int				i;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct s_all
{
	t_dlist			*a;
	t_dlist			*b;
	int				idx_min;
	int				idx_max;
}					t_all;

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
void				ct_rev_rotater(t_dlist **dlst, t_dlist **dlst_two,
						char *operator);
void				ct_rotater(t_dlist **dlst, t_dlist **dlst_two,
						char *operator);
void				ct_swapper(t_dlist **dlst, t_dlist **dlst_two,
						char *operator);
void				ct_pusher(t_dlist **src_dlst, t_dlist **dest_dlst,
						char *operator);

/*
** parse.c
*/
t_dlist				*parse_check_dup(int argc, char **argv);

#endif
