/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 10:08:47 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Switch the first element of the 
// stack a with the second element.
void	sa(t_llists *l, bool ss)
{
	int	temp_content;
	int	temp_wanted;

	if (l->len_a < 2)
		return ;
	temp_content = l->start_a->content;
	temp_wanted = l->start_a->position_wanted;
	l->start_a->content = l->start_a->next->content;
	l->start_a->position_wanted = l->start_a->next->position_wanted;
	l->start_a->next->content = temp_content;
	l->start_a->next->position_wanted = temp_wanted;
	if (ss == false)
		ft_printf("sa \n");
}

// Switch the first element of the 
// stack b with the second element.
void	sb(t_llists *l, bool ss)
{
	int	temp;
	int	temp_wanted;

	if (l->len_b < 2)
		return ;
	temp = l->start_b->content;
	temp_wanted = l->start_a->position_wanted;
	l->start_b->content = l->start_b->next->content;
	l->start_b->position_wanted = l->start_b->next->position_wanted;
	l->start_b->next->content = temp;
	l->start_b->next->position_wanted = temp_wanted;
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
