/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/18 10:55:53 by aguay            ###   ########.fr       */
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
	int					position_wanted;
	int					content;
	int					position_actuel;
}					t_llist;

typedef struct linked_lists
{
	struct linked_list	*start_a;
	struct linked_list	*start_b;
	int					len_a;
	int					len_b;
}					t_llists;

// Linked list fonctions
int			argv_size(char **argv);
bool		lim_test(char **argv);
bool		check_digit(char **argv);
bool		check_doublons(char **argv);
t_llist		*init_list(char **argv, t_llists *l);
void		print_lists(t_llists *l);
void		ft_free_lists(t_llists *l);
void		add_top(t_llist *start, int contenu, int *len, int wanted);
void		delete_top(t_llist *start, int *len);

// Push_swap functions
void		sa(t_llists *l, bool ss);
void		sb(t_llists *l, bool ss);
void		ss(t_llists *l);
void		pa(t_llists *l);
void		pb(t_llists *l);
void		ra(t_llists *l, bool rr);
void		rb(t_llists *l, bool rr);
void		rr(t_llists *l);
void		rra(t_llists *l, bool rrr);
void		rrb(t_llists *l, bool rrr);
void		rrr(t_llists *l);

// libft addons
long int	ft_atol(char *string);
int			smallest(int *tab, int *len);
int			smallest_list(t_llists *l);
int			biggest_list(t_llists *l);
int			get_median(t_llists *l);
void		ft_free2d(char **string);

// algo fonctions
bool		l_sorted_a(t_llists *l);
bool		l_sorted_b(t_llists *l);
void		sort_ll(t_llists *l);
void		push_med_b(t_llists *l);
#endif
