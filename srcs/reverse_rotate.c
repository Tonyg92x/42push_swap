/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/01/20 12:51:00 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Shift down every element of the
// stack a. The last element become
// the first one.
void	rra(t_llist **a, int *len)
{
	int	temp;
	int	i;

	if ((*len) == 0)
		return ;
	i = (*len) - 1;
	temp = a[i]->content;
	while (i != 0)
	{
		a[i]->content = a[i - 1]->content;
		i--;
	}
	a[0]->content = temp;
	ft_printf("rra\n");
}

// Shift down every element of the
// stack b. The last element become
// the first one.
void	rrb(t_llist **b, int *len)
{
	int	temp;
	int	i;

	if ((*len) == 0)
		return ;
	i = (*len) - 1;
	temp = b[i]->content;
	while (i != 0)
	{
		b[i]->content = b[i - 1]->content;
		i--;
	}
	b[0]->content = temp;
	ft_printf("rrb\n");
}

// Shift down every element of the
// stack a and b. The last element 
// become the first one.
void	rrr(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	int	temp;
	int	i;

	if ((*len_a) == 0)
		return ;
	i = (*len_a) - 1;
	temp = a[i]->content;
	while (i != 0)
	{
		a[i]->content = a[i - 1]->content;
		i--;
	}
	a[0]->content = temp;
	if ((*len_b) == 0)
		return ;
	i = (*len_b) - 1;
	temp = b[i]->content;
	while (i != 0)
	{
		b[i]->content = b[i - 1]->content;
		i--;
	}
	b[0]->content = temp;
	ft_printf("rrr\n");
}
