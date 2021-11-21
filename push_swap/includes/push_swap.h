/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:00:58 by sashin            #+#    #+#             */
/*   Updated: 2021/11/21 11:17:48 by sashin           ###   ########.fr       */
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
}					t_all;

typedef struct s_count
{
	int				ra;
	int				rb;
	int				pa;
	int				pb;
	int				pivot_one;
	int				pivot_two;
}					t_count;


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
** controls*.c
*/
void				ct_rev_rotater(t_dlist **dlst);
void				ct_rotater(t_dlist **dlst);
void				ct_swapper(t_dlist **dlst);
void				ct_pusher(t_dlist **src_dlst, t_dlist **dest_dlst);

void				pa(t_all *s);
void				pb(t_all *s);
void				sa(t_all *s);
void				sb(t_all *s);
void				ss(t_all *s);
void				ra(t_all *s);
void				rb(t_all *s);
void				rr(t_all *s);
void				rra(t_all *s);
void				rrb(t_all *s);
void				rrr(t_all *s);

/*
** small_sort.c
*/
void				sort_three(t_all *s);
void				sort_four(t_all *s);
void				sort_five(t_all *s);
void				small_sort(t_all *s, int size);

/*
** get_pivot.c
*/
void				get_pivot(t_dlist *lst, t_count *count, int size);
int					get_max(t_dlist *lst, int size);
int					get_min(t_dlist *lst, int size);
int					get_mid(t_dlist *lst, int size);

/*
** a_to_b.c
*/
void				a_to_b(t_all *s, int size);

/*
** a_to_b_sort.c
*/
void				a_to_b_sort(t_all *s, t_count *count, int size);
void				three_a(t_all *s);
void				four_a(t_all *s);
void				five_a(t_all *s);

/*
** a_to_b_command.c
*/
void				ra_sa_rra(t_all *s);
void				ra_sa_rra_sa(t_all *s);
void				sa_ra_sa_rra(t_all *s);
void				sa_ra_sa_rra_sa(t_all *s);


/*
** b_to_a.c
*/
void				b_to_a(t_all *s, int size);

/*
** b_to_a_sort.c
*/
void				b_to_a_sort(t_all *s, t_count *count, int size);
void				three_b(t_all *s);
void				four_b(t_all *s);
void				five_b(t_all *s);

/*
** b_to_a_command.c
*/
void				sb_rb_sb_rrb_sb(t_all *s);
void				sb_rb_sb_rrb(t_all *s);
void				rb_sb_rrb_sb(t_all *s);
void				rb_sb_rrb(t_all *s);

/*
** parse.c
*/
t_dlist				*parse_check_dup(int argc, char **argv);

/*
** init.c
*/
void				init_s(t_all *s);
void				init_count(t_count *count);

/*
** push_swap.c
*/
void				ft_rewind(t_all *s, t_count count);

#endif
