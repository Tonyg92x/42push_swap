/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 10:05:54 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Rotate every element by one to the top.
// Element 0 go under the stack.
void	ra(t_llists *l, bool rr)
{
	int		temp_content;
	int		temp_wanted;
	int		temp_len;
	t_llist	*a;

	if (l->len_a < 2)
		return ;
	a = l->start_a;
	temp_len = l->len_a;
	temp_content = a->content;
	temp_wanted = a->position_wanted;
	while (temp_len > 1)
	{
		a->content = a->next->content;
		a->position_wanted = a->next->position_wanted;
		a = a->next;
		temp_len--;
	}
	a->content = temp_content;
	a->position_wanted = temp_wanted;
	if (rr == false)
		ft_printf("ra\n");
}

// Rotate every element by one to the top.
// Element 0 go under the stack.
void	rb(t_llists *l, bool rr)
{
	int		temp_content;
	int		temp_wanted;
	int		temp_len;
	t_llist	*b;

	if (l->len_b < 2)
		return ;
	b = l->start_b;
	temp_len = l->len_b;
	temp_content = b->content;
	temp_wanted = b->position_wanted;
	while (temp_len > 1)
	{
		b->content = b->next->content;
		b->position_wanted = b->next->position_wanted;
		b = b->next;
		temp_len--;
	}
	b->content = temp_content;
	b->position_wanted = temp_wanted;
	if (rr == false)
		ft_printf("rb\n");
}

void	rr(t_llists *l)
{
	ra(l, true);
	rb(l, true);
	ft_printf("rr\n");
}
