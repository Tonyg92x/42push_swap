/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 10:03:16 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

//	Return the smallest value of the list a
int	smallest_value(t_llists *l, int *plancher)
{
	t_llist		*p;
	int			retour;

	p = l->start_a;
	retour = 2147483647;
	while (p)
	{
		if (p->content < retour && p->content >= (*plancher))
		{
			retour = p->content;
		}
		p = p->next;
	}
	(*plancher) = retour;
	return (retour);
}

//	Class every element in the wanted order
int	*class_table(t_llists *l)
{
	int		*tab;
	int		size;
	int		i;
	int		plancher;

	plancher = -2147483648;
	size = l->len_a;
	tab = malloc(sizeof(int) * l->len_a);
	i = 0;
	while (size > 0)
	{
		tab[i] = smallest_value(l, &plancher);
		i++;
		size--;
	}
	return (tab);
}

//	Put the wanted position to every elements
void	fill_wanted_pos(t_llists *l, int *tab)
{
	int		i;
	t_llist	*temp;

	i = 0;
	while (i < l->len_a)
	{
		temp = l->start_a;
		while (true)
		{
			if (tab[i] == temp->content)
			{
				temp->position_wanted = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}

// Get the value of the median
int	init_pos_wanted(t_llists *l)
{
	int	*tab;

	tab = class_table(l);
	fill_wanted_pos(l, tab);
	free(tab);
	return (l->len_a / 2);
}
