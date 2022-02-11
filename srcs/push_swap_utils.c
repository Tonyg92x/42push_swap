/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/11 14:20:56 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonction wich verify if arguments are not
// called 2 times.
bool	protection_doublon(t_llist **l, int len)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < len)
	{
		y = 0;
		while (y < i)
		{
			if (l[i]->content == l[y]->content)
			{
				ft_printf("Error\n");
				return (true);
			}
			y++;
		}
		i++;
	}
	return (false);
}

// Print every element of both list
void	print_list(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	ft_printf("\n------------------------\n");
	while (i < (*len_a) || y < (*len_b))
	{
		if (i < (*len_a))
		{
			ft_printf("%d \t", a[i]->content, i);
			i++;
		}
		else
			ft_printf(" \t");
		if (y < (*len_b))
		{
			ft_printf("%d \n", b[y]->content);
			y++;
		}
		else
			ft_printf("\n");
	}
	ft_printf("-\t-\na\tb\n\n");
}