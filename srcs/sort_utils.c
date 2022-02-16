/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 12:29:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonction that verify if the list entered
// is sorted
bool	l_sorted_a(t_llists *l)
{
	t_llist	*a;

	a = l->start_a;
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}

// Fonction that verify if the list entered
// is sorted
bool	l_sorted_b(t_llists *l)
{
	t_llist	*b;

	b = l->start_b;
	while (b->next != NULL)
	{
		if (b->content > b->next->content)
			return (false);
		b = b->next;
	}
	return (true);
}

// Fonction that push all elements under the median in list b
void	push_med_b(t_llists *l)
{
	int		median;
	int		size;
	t_llist	*temp;

	size = l->len_a;
	temp = l->start_a;
	median = get_median(l);
	while (size > 0)
	{
		if (temp->position_wanted < median)
			pb(l);
		else
			ra(l, false);
		temp = l->start_a;
		size--;
	}
}
