/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/22 20:47:46 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


//	Return true if the list a is sorted
bool	sorted_a(t_llists *l)
{
	t_llist	*temp;

	temp = l->start_a;
	if (l->start_a != NULL && l->start_a->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (temp->position_wanted > temp->next->position_wanted)
				return (false);
			temp = temp->next;
		}
	}
	return (true);
}

//	Return true if the list b is sorted
bool	sorted_b(t_llists *l)
{
	t_llist	*temp;

	temp = l->start_b;
	if (l->start_b != NULL && l->start_b->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (temp->position_wanted < temp->next->position_wanted)
				return (false);
			temp = temp->next;
		}
	}
	return (true);
}

bool	sorted(t_llists *l)
{
	if (sorted_a(l) == false)
		return (false);
	if (sorted_b(l) == false)
		return (false);
	return (true);
}