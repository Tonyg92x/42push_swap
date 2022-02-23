/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/23 09:52:30 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	quarter(t_llists *l, int size)
{
	int		tab[size];
	int		i;
	int		plancher;
	t_llist	*temp;

	temp = l->start_a;
	while (temp->next != NULL)
		temp = temp->next;
	plancher = temp->position_wanted;
	i = 0;
	while (i < size)
		tab[i++] = smal_pos(l->start_a, &plancher);
	return (tab[size / 4]);
}
