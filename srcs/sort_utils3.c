/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/23 09:06:53 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pushed_back(t_llists *l)
{
	while (l->pushed > 0)
	{
		if (l->start_a->position_wanted == l->count)
		{
			if (l->len_b > 1 && l->start_b->position_wanted > l->start_b->next->position_wanted)
				rr(l);
			else
				ra(l, false);
			l->count++;
			l->pushed--;
		}
		else
		{
			pb(l);
			l->pushed--;
		}
	}
}
