/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/18 08:55:15 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonction that verify if the list entered
// is sorted
bool	l_sorted_a(t_llists *l)
{
	int		temp;
	t_llist	*a;

	temp = l->len_a;
	a = l->start_a;
	while (temp > 1)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
		temp--;
	}
	return (true);
}

// Fonction that verify if the list entered
// is sorted
bool	l_sorted_b(t_llists *l)
{
	int		temp;
	t_llist	*b;

	temp = l->len_b;
	b = l->start_b;
	while (temp > 1)
	{
		if (b->content < b->next->content)
			return (false);
		b = b->next;
		temp--;
	}
	return (true);
}

//	Verify if all element are already in the
//	list b to eleminate extra rotation.
bool	is_done(t_llists *l, int median)
{
	int		len;
	t_llist	*a;

	a = l->start_a;
	len = l->len_a;
	while (len > 0)
	{
		if (a->position_wanted < median)
			return (false);
		a = a->next;
		len--;
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
	while (size > 0 && is_done(l, median) == false)
	{
		if (temp->position_wanted < median)
			pb(l);
		else
			ra(l, false);
		temp = l->start_a;
		size--;
	}
}
