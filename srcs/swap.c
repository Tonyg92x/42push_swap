/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/08 13:37:37 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Switch the first element of the 
// stack a with the second element.
void	sa(t_llist **a)
{
	int	temp;

	if (!a[0] || !a[1])
		return ;
	temp = a[0]->content;
	a[0]->content = a[1]->content;
	a[1]->content = temp;
	ft_printf("sa \n");
}

// Switch the first element of the 
// stack b with the second element.
void	sb(t_llist **b)
{
	int	temp;

	if (!b[0] || !b[1])
		return ;
	temp = b[0]->content;
	b[0]->content = b[1]->content;
	b[1]->content = temp;
	ft_printf("sb \n");
}

// Switch the first element with the second
// element on both stack.
void	ss(t_llist **a, t_llist **b)
{
	int	temp;

	if (!a[0] || !a[1])
		return ;
	temp = a[0]->content;
	a[0]->content = a[1]->content;
	a[1]->content = temp;
	if (!b[0] || !b[1])
		return ;
	temp = b[0]->content;
	b[0]->content = b[1]->content;
	b[1]->content = temp;
	ft_printf("ss \n");
}
