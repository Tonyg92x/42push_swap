/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/19 14:52:32 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// void	sort_by8(t_llists *l)
// {
	
// }

void	sort_by4(t_llists *l)
{
	get_highest_half_up(l);
	while (l->len_b > 0)
		pa(l);
	get_highest_quater_up(l);
	sort_b(l);
}

void	sort_by2(t_llists *l)
{
	get_highest_half_up(l);
	sort_b(l);
	get_highest_quater_up(l);
	sort_b(l);
}

// Solve efficiently the sorting of integer agument
// with specified actions.
void	sort_ll(t_llists *l)
{
	if (l->option == 2)
		sort_by2(l);
	else if (l->option == 3)
		sort_by4(l); // a retravailler
	// else if (l->option == 4)
	// 	sort_by8(l);
}
