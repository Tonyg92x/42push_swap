/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 10:59:23 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Push the first element of the stack b to the
// First element of the stack a.
void	pa(t_llists *l)
{
	if (l->len_b > 0)
	{
		add_top(l->start_a, l->start_b->content, &l->len_a, l->start_b->position_wanted);
		delete_top(l->start_b, &l->len_b);
		ft_printf("pa\n");
		return ;
	}
}

// Push the first element of the stack a to the
// first element b.
void	pb(t_llists *l)
{
	if (l->len_a > 0)
	{
		add_top(l->start_b, l->start_a->content, &l->len_b, l->start_a->position_wanted);
		delete_top(l->start_a, &l->len_a);
		ft_printf("pb\n");
		return ;
	}
}
