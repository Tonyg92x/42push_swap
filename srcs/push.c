/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 09:54:02 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Push the first element of the stack b to the
// First element of the stack a.
void	pa(t_llist *start_a, t_llist *start_b, int *len_a, int *len_b)
{
	if ((*len_b) > 0)
	{
		add_top(start_a, start_b->content, len_a);
		delete_top(start_b, len_b);
		ft_printf("pa\n");
		return ;
	}
}

// Push the first element of the stack a to the
// first element b.
void	pb(t_llist *start_a, t_llist *start_b, int *len_a, int *len_b)
{
	if ((*len_a) > 0)
	{
		add_top(start_b, start_a->content, len_b);
		delete_top(start_a, len_a);
		ft_printf("pb\n");
		return ;
	}
}
