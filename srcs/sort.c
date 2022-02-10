/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/01/20 14:05:23 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	shuffle(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	if (l_sorted_a(a, len_a) != true)
	{
		while (a[0]->content != smallest_list(a, len_a))
			rra(a, len_a);
		pb(a, b, len_a, len_b);
	}
	else if (l_sorted_b(b, len_b) != true)
	{
		while (b[0]->content != biggest_list(b, len_b))
			rrb(b, len_b);
		pa(a, b, len_a, len_b);
	}
}

// Sorting elements in both list using reverse rotate.
static void	sort(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	int	nb_exec;

	nb_exec = 0;
	while (l_sorted_a(a, len_a) != true || l_sorted_b(b, len_b) != true)
	{
		if (a[0]->content > a[1]->content && b[0]->content < b[1]->content)
			ss(a, b);
		else if (a[0]->content > a[1]->content)
			sa(a);
		else if (b[0]->content < b[1]->content)
			sb(b);
		else if (l_sorted_a(a, len_a) != true && l_sorted_b(b, len_b) != true)
			rrr(a, b, len_a, len_b);
		else if (l_sorted_a(a, len_a) != true)
			rra(a, len_a);
		else if (l_sorted_b(b, len_b) != true)
			rrb(b, len_b);
		nb_exec++;
		if (nb_exec > (*len_a) * 3 || nb_exec > (*len_b) * 3)
		{
			shuffle(a, b, len_a, len_b);
			nb_exec = 0;
		}
	}
}

// Solve efficiently the sorting of integer agument
// with specified actions.
void	sort_ll(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	if (l_sorted_a(a, len_a))
		return ;
	push_med_b(a, b, len_a, len_b);
	sort(a, b, len_a, len_b);
	while ((*len_b) > 0)
		pa(a, b, len_a, len_b);
}
