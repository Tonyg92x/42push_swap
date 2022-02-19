/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/19 14:48:31 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_b(t_llists *l)
{
	while (l->len_b > 0)
	{
		if (l->start_b->position_wanted == l->count)
		{
			pa(l);
			rra(l, false);
			l->count++;
		}
		else
			rb(l, false);
	}
}

// Fonction that push all elements under the median in list b
void	get_lowest_half_up(t_llists *l)
{
	int	i;

	i = l->len_a;
	while (i > 0)
	{
		if (l->start_a->position_wanted < l->median)
			pb(l);
		else
			ra(l, false);
		i--;
	}
	i = l->len_b;
}

void	get_highest_quater_up(t_llists *l)
{
	int	i;

	i = l->median;
	while (i > 0)
	{
		if (l->start_a->position_wanted > l->un_quart)
			pb(l);
		i--;
	}
}

void	get_highest_half_up(t_llists *l)
{
	while (l->start_a->position_wanted >= l->median)
		pb(l);
}
