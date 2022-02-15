/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 09:54:13 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Shift down every element of the
// stack a. The last element become
// the first one.
void	rra(t_llist *start_a, int *len, bool rrr)
{
	int		temp;

	if ((*len) < 1)
		return ;
	temp = (*len);
	while (temp > 1)
	{
		start_a = start_a->next;
		temp--;
	}
	temp = start_a->content;
	while (start_a->prev != NULL)
	{
		start_a->content = start_a->prev->content;
		start_a = start_a->prev;
	}
	start_a->content = temp;
	if (rrr == false)
		ft_printf("rra\n");
}

// Shift down every element of the
// stack b. The last element become
// the first one.
void	rrb(t_llist *start_b, int *len, bool rrr)
{
	int		temp;

	if ((*len) < 1)
		return ;
	temp = (*len);
	while (temp > 1)
	{
		start_b = start_b->next;
		temp--;
	}
	temp = start_b->content;
	while (start_b->prev != NULL)
	{
		start_b->content = start_b->prev->content;
		start_b = start_b->prev;
	}
	start_b->content = temp;
	if (rrr == false)
		ft_printf("rrb\n");
}

// Shift down every element of the
// stack a and b. The last element 
// become the first one.
void	rrr(t_llist *start_a, t_llist *start_b, int *len_a, int *len_b)
{
	rra(start_a, len_a, true);
	rrb(start_b, len_b, true);
	ft_printf("rrr\n");
}
