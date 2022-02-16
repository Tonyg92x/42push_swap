/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 12:42:59 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// static void	shuffle(t_llists *l)
// {
// 	if (l_sorted_a(l) != true)
// 	{
// 		while (a[0]->content != smallest_list(a, len_a))
// 			rra(a, len_a);
// 		pb(a, b, len_a, len_b);
// 	}
// 	else if (l_sorted_b(b, len_b) != true)
// 	{
// 		while (b[0]->content != biggest_list(b, len_b))
// 			rrb(b, len_b);
// 		pa(a, b, len_a, len_b);
// 	}
// }

// // Sorting elements in both list using reverse rotate.
static void	sort(t_llists *l)
{
	int	nb_exec;

	nb_exec = 0;
	while (l_sorted_a(l) != true || l_sorted_b(l) != true)
	{
		if (l->start_a->content > l->start_a->next->content && l->start_b->content < l->start_b->next->content)
			ss(l);
		else if (l->start_a->content > l->start_a->next->content)
			sa(l, false);
		else if (l->start_b->content < l->start_b->next->content)
			sb(l, false);
		else if (l_sorted_a(l) != true && l_sorted_b(l) != true)
			rrr(l);
		else if (l_sorted_a(l) != true)
			rra(l, false);
		else if (l_sorted_b(l) != true)
			rrb(l, false);
		nb_exec++;
		if (nb_exec > (l->len_a * 3) || nb_exec > (l->len_b * 3))
		{
			shuffle(l);
			nb_exec = 0;
		}
	}
}

// Solve efficiently the sorting of integer agument
// with specified actions.
void	sort_ll(t_llists *l)
{
	if (l_sorted_a(l))
		return ;
	push_med_b(l);
	sort(l);
}
