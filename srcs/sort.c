/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/23 10:59:50 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

//	sort 3 elements of list a
static void	sort_o3(t_llists *l)
{
	t_llist	*temp;

	temp = l->start_a;
	while (sorted_a(l) != true)
	{
		if (smallest_pos_wanted(temp))
		{
			ra(l, false);
			sa(l, false);
			rra(l, false);
		}
		else if (smallest_pos_wanted(temp->next) && biggest_pos_wanted(temp->next->next))
			sa(l, false);
		else if  (smallest_pos_wanted(temp->next))
			ra(l, false);
		else if (smallest_pos_wanted(temp->next->next) && biggest_pos_wanted(temp->next))
			rra(l, false);
		else
		{
			sa(l, false);
			rra(l, false);
		}
	}
}

//	sort 5 element of list a
static void	sort_o5(t_llists *l)
{
	int	i;

	i = 5;
	while (i > 0)
	{
		if (l->start_a->position_wanted < 2)
			pb(l);
		else
			ra(l, false);
		i--;
	}
	if (l->start_b->position_wanted == 0)
		sb(l, false);
	sort_o3(l);
	pa(l);
	pa(l);
}

//	sort the list
static void	sort(t_llists *l)
{
	int	median;
	int	quarter;

	median = get_median(l->start_a, l->len_a);
	first_push(l);
	quarter = get_median(l->start_b, l->len_b);
	push_back(l, l->len_b, quarter);
	while (l->len_b > 0 && l->start_a->position_wanted != quarter)
	{
		while (l->len_b > 12)
			push_med_b(l);
		sort_b(l);
		while (l->start_a->position_wanted <= quarter)
		{
			if (l->start_a->position_wanted == l->count)
			{
				l->count++;
				ra(l, false);
			}
			else
				pb(l);
		}
	}
	while (l->start_a->position_wanted <= median)
	{
		if (l->start_a->position_wanted == l->count)
		{
			l->count++;
			ra(l, false);
		}
		else
			pb(l);
	}
	while (l->len_b > 0 && l->start_a->position_wanted != median)
	{
		while (l->len_b > 12)
			push_med_b(l);
		sort_b(l);
		while (l->start_a->position_wanted <= median)
		{
			if (l->start_a->position_wanted == l->count)
			{
				l->count++;
				ra(l, false);
			}
			else
				pb(l);
		}
	}
	while (l->start_a->position_wanted != 0)
	{
		if (l->start_a->position_wanted == l->count)
		{
			l->count++;
			ra(l, false);
		}
		else
			pb(l);
	}
	quarter = get_median(l->start_b, l->len_b);
	ft_printf("%d\n", quarter);
	push_back(l, l->len_b, quarter);
	while (l->len_b > 0 && l->start_a->position_wanted != quarter)
	{
		while (l->len_b > 12)
			push_med_b(l);
		sort_b(l);
		while (l->start_a->position_wanted <= quarter)
		{
			if (l->start_a->position_wanted == l->count)
			{
				l->count++;
				ra(l, false);
			}
			else
				pb(l);
		}
	}
	while (l->start_a->position_wanted != 0)
	{
		if (l->start_a->position_wanted == l->count)
		{
			l->count++;
			ra(l, false);
		}
		else
			pb(l);
	}
	while (l->len_b > 0 || l->start_a->position_wanted != 0)
	{
		while (l->len_b > 12)
			push_med_b(l);
		sort_b(l);
		while (l->start_a->position_wanted != 0)
		{
			if (l->start_a->position_wanted == l->count)
			{
				l->count++;
				ra(l, false);
			}
			else
				pb(l);
		}
	}
	
}

// Solve efficiently the sorting of integer agument
// with specified actions.
void	sort_ll(t_llists *l)
{
	if (sorted_a(l))
		return;
	if (l->option == 3)
		sort_o3(l);
	else if (l->option == 5)
		sort_o5(l);
	else
		sort(l);
}
