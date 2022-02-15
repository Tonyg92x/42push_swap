/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 09:48:28 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Switch the first element of the 
// stack a with the second element.
void	sa(t_llist *a, bool ss)
{
	int	temp;

	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	if (ss == false)
		ft_printf("sa \n");
}

// Switch the first element of the 
// stack b with the second element.
void	sb(t_llist *b, bool ss)
{
	int	temp;

	temp = b->content;
	b->content = b->next->content;
	b->next->content = temp;
	if (ss == false)
		ft_printf("sa \n");
}

// Switch the first element with the second
// element on both stack.
void	ss(t_llist *a, t_llist *b)
{
	sa(a, true);
	sb(b, true);
	ft_printf("ss \n");
}
