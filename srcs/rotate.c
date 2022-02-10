/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/01/20 12:51:11 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Rotate every element by one to the top.
// Element 0 go under the stack.
void	ra(t_llist **a, int *len)
{
	int	temp;
	int	i;

	if ((*len) == 0)
		return ;
	i = 0;
	temp = a[0]->content;
	while (i < (*len) - 1)
	{
		a[i]->content = a[i + 1]->content;
		i++;
	}
	a[i]->content = temp;
	ft_printf("ra\n");
}

// Rotate every element by one to the top.
// Element 0 go under the stack.
void	rb(t_llist **b, int *len)
{
	int	temp;
	int	i;

	if ((*len) == 0)
		return ;
	i = 0;
	temp = b[0]->content;
	while (i < (*len) - 1)
	{
		b[i]->content = b[i + 1]->content;
		i++;
	}
	b[i]->content = temp;
	ft_printf("rb\n");
}

void	rr(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	int	temp;
	int	i;

	if ((*len_a) == 0)
		return ;
	i = 0;
	temp = a[0]->content;
	while (i < (*len_a) - 1)
	{
		a[i]->content = a[i + 1]->content;
		i++;
	}
	a[i]->content = temp;
	if ((*len_b) == 0)
		return ;
	i = 0;
	temp = b[0]->content;
	while (i < (*len_b) - 1)
	{
		b[1]->content = b[i + 1]->content;
		i++;
	}
	b[i]->content = temp;
	ft_printf("rr\n");
}
