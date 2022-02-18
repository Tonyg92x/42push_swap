/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/18 14:08:15 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	smallest_list(t_llists *l)
{
	t_llist	*temp;
	int		retour;
	int		len;

	len = l->len_a;
	retour = 2147483647;
	temp = l->start_a;
	while(len > 0)
	{
		if (temp->position_wanted < retour)
			retour = temp->position_wanted;
		temp = temp->next;
		len--;
	}
	return (retour);
}

int	biggest_list(t_llists *l)
{
	t_llist	*temp;
	int		retour;
	int		len;

	len = l->len_b;
	retour = -2147483648;
	temp = l->start_b;
	while (len > 0)
	{
		if (temp->position_wanted > retour)
			retour = temp->position_wanted;
		temp = temp->next;
		len--;
	}
	return (retour);
}

static void	shuffle(t_llists *l)
{
	if (l_sorted_a(l) != true)
	{
		while (l->start_a->position_wanted != smallest_list(l))
			rra(l, false);
		pb(l);
	}
	else if (l_sorted_b(l) != true)
	{
		while (l->start_b->position_wanted != biggest_list(l))
			rrb(l, false);
		pa(l);
	}
}

// Sorting elements in both list using reverse rotate.
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
		if (nb_exec > (l->len_a * 2) || nb_exec > (l->len_b * 3))
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
	while (l->len_b > 0)
		pa(l);
}
