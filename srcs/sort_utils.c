/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/01/20 12:51:20 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonction that verify if the list entered
// is sorted
bool	l_sorted_a(t_llist **a, int *len)
{
	int	i;

	i = 0;
	while (i < (*len) - 1)
	{
		if (a[i]->content > a[i + 1]->content)
			return (false);
		i++;
	}
	return (true);
}

// Fonction that verify if the list entered
// is sorted
bool	l_sorted_b(t_llist **b, int *len)
{
	int	i;

	i = 0;
	while (i < (*len) - 1)
	{
		if (b[i]->content < b[i + 1]->content)
			return (false);
		i++;
	}
	return (true);
}

// Fonction that push all elements under the median in list b
void	push_med_b(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	int	i;
	int	y;
	int	median;

	median = get_median(a, len_a);
	i = 0;
	y = (*len_a);
	while (i < y)
	{
		if (a[0]->content <= median)
			pb(a, b, len_a, len_b);
		rra(a, len_a);
		i++;
	}
}
