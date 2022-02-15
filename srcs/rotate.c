/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 09:31:35 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Rotate every element by one to the top.
// Element 0 go under the stack.
void	ra(t_llist *start_a, int *len, bool rr)
{
	int	temp;
	int	temp_len;

	temp_len = (*len);
	temp = start_a->content;
	while (temp_len > 1)
	{
		start_a->content = start_a->next->content;
		start_a = start_a->next;
		temp_len--;
	}
	start_a->content = temp;
	if (rr == false)
		ft_printf("ra\n");
}

// Rotate every element by one to the top.
// Element 0 go under the stack.
void	rb(t_llist *start_b, int *len, bool rr)
{
	int	temp;
	int	temp_len;

	temp_len = (*len);
	temp = start_b->content;
	while (temp_len > 1)
	{
		start_b->content = start_b->next->content;
		start_b = start_b->next;
		temp_len--;
	}
	start_b->content = temp;
	if (rr == false)
		ft_printf("rb\n");
}

void	rr(t_llist *start_a, t_llist *start_b, int *len_a, int *len_b)
{
	ra(start_a, len_a, true);
	rb(start_b, len_b, true);
	ft_printf("rr\n");
}
