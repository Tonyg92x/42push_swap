/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 14:52:11 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Shift down every element of the
// stack a. The last element become
// the first one.
void	rra(t_llists *l, bool rrr)
{
	int		temp;
	int		temp_wanted;
	t_llist	*a;

	a = l->start_a;
	if (l->len_a < 2)
		return ;
	while (a->next != NULL)
		a = a->next;
	temp = a->content;
	temp_wanted = a->position_wanted;
	while (a->prev != NULL)
	{
		a->content = a->prev->content;
		a->position_wanted = a->prev->position_wanted;
		a = a->prev;
	}
	a->content = temp;
	a->position_wanted = temp_wanted;
	if (rrr == false)
		ft_printf("rra\n");
}

// Shift down every element of the
// stack b. The last element become
// the first one.
void	rrb(t_llists *l, bool rrr)
{
	int		temp;
	int		temp_wanted;
	t_llist	*b;

	b = l->start_b;
	if (l->len_b)
		return ;
	temp = l->len_b;
	while (temp > 1)
	{
		b = b->next;
		temp--;
	}
	temp = b->content;
	temp_wanted = b->position_wanted;
	while (b->prev != NULL)
	{
		b->content = b->prev->content;
		b->position_wanted = b->prev->position_wanted;
		b = b->prev;
	}
	b->content = temp;
	b->position_wanted = temp_wanted;
	if (rrr == false)
		ft_printf("rrb\n");
}

// Shift down every element of the
// stack a and b. The last element 
// become the first one.
void	rrr(t_llists *l)
{
	rra(l, true);
	rrb(l, true);
	ft_printf("rrr\n");
}
