/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/24 11:09:19 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Switch the first element of the 
// stack a with the second element.
void	sa(t_llists *l, bool ss)
{
	t_llist	*temp;
	t_llist	*temp2;

	if (l->len_a < 1)
		return ;
	if (l->len_a == 2)
	{
		temp = l->start_a;
		temp->prev = l->start_a->next;
		l->start_a = l->start_a->next;
		l->start_a->next = temp;
		l->start_a->prev = NULL;
		l->start_a->next->next = NULL;
	}
	else
	{
		temp = l->start_a;
		temp2 = temp->next->next;
		temp->next->next->prev = temp;
		temp->next->prev = NULL;
		temp->next->next = temp;
		temp->prev = temp->next;
		l->start_a = temp->next;
		temp->next = temp2;
	}
	if (ss == false)
		ft_printf("sa \n");
}

// Switch the first element of the 
// stack b with the second element.
void	sb(t_llists *l, bool ss)
{
	t_llist	*temp;
	t_llist	*temp2;

	if (l->len_b < 1)
		return ;
	else if (l->len_b == 2)
	{
		temp = l->start_b;
		temp->prev = l->start_b->next;
		l->start_b = l->start_b->next;
		l->start_b->next = temp;
		l->start_b->prev = NULL;
		l->start_b->next->next = NULL;
	}
	else
	{
		temp = l->start_b;
		temp2 = temp->next->next;
		temp->next->next->prev = temp;
		temp->next->prev = NULL;
		temp->next->next = temp;
		temp->prev = temp->next;
		l->start_b = temp->next;
		temp->next = temp2;
	}
	if (ss == false)
		ft_printf("sb \n");
}

// Switch the first element with the second
// element on both stack.
void	ss(t_llists *l)
{
	if (l->len_a > 1)
		sa(l, true);
	if (l->len_b > 1)
		sb(l, true);
	ft_printf("ss \n");
}
