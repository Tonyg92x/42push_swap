/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/24 11:09:10 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_back(t_llists *l, int len, int limit)
{
	int	size;

	size = len;
	while (size > 0)
	{
		if (l->start_b->position_wanted == l->count)
		{
			pa(l);
			ra(l, false);
			l->count++;
		}
		else if (l->start_b->position_wanted > limit)
			pa(l);
		else
			rb(l, false);
		size--;
	}
}
