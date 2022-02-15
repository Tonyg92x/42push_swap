/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 12:44:56 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stddef.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct linked_list
{
	struct linked_list	*next;
	struct linked_list	*prev;
	int					content;
	int					position;
}					t_llist;

typedef struct linked_lists
{
	struct linked_list	*start_a;
	struct linked_list	*start_b;
	int					len_a;
	int					len_b;
}					t_llists;

// Linked list fonctions
t_llist		*lst_last(t_llist *l);
void		add_list(t_llist *l, int content);
int			argv_size(char **argv);
bool		lim_test(char **argv);
t_llist		*init_list_a(char **argv, t_llists *l);
t_llist		*init_list_b(char **argv, t_llists *l);
void		print_list(t_llists *l);
void		ft_free_lists(t_llists *l);
void		add_top(t_llist *start, int contenu, int *len);
void		delete_top(t_llist *start, int *len);

// Push_swap functions
void		sa(t_llist *a, bool ss);
void		sb(t_llist *b, bool ss);
void		ss(t_llist *a, t_llist *b);
void		pa(t_llist *a, t_llist *b, int *len_a, int *len_b);
void		pb(t_llist *a, t_llist *b, int *len_a, int *len_b);
void		ra(t_llist *start_a, int *len, bool rr);
void		rb(t_llist *start_b, int *len, bool rr);
void		rr(t_llist *start_a, t_llist *start_b, int *len_a, int *len_b);
void		rra(t_llist *start_a, int *len, bool rrr);
void		rrb(t_llist *start_b, int *len, bool rrr);
void		rrr(t_llist *start_a, t_llist *start_b, int *len_a, int *len_b);

// libft addons
long int	ft_atol(char *string);
int			smallest(int *tab, int *len);
int			smallest_list(t_llist **tab, int *len);
int			biggest_list(t_llist **list, int *len);
int			get_median(t_llist **l, int *len);
void		ft_free2d(char **string);

// algo fonctions
bool		l_sorted_a(t_llist **l, int *len);
bool		l_sorted_b(t_llist **l, int *len);
void		sort_ll(t_llist **a, t_llist **b, int *len_a, int *len_b);
void		push_med_b(t_llist **a, t_llist **b, int *len_a, int *len_b);
#endif
