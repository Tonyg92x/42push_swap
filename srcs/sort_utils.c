/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/22 21:09:46 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

//	Return true if the list start entered has
//	the smallest pos wanted in the list.
bool	smallest_pos_wanted(t_llist *l)
{
	int	i;

	i = l->position_wanted;
	while (l->prev != NULL)
		l = l->prev;
	while (l)
	{
		if (l->position_wanted < i)
			return (false);
		l = l->next;
	}
	return (true);
}

//	Return true if the list start entered has
//	the biggest pos wanted in the list.
bool	biggest_pos_wanted(t_llist *l)
{
	int	i;

	i = l->position_wanted;
	while (l->prev != NULL)
		l = l->prev;
	while (l)
	{
		if (l->position_wanted > i)
			return (false);
		l = l->next;
	}
	return (true);
}

//	Get in the start of a list with his size.
//	get out the median of the pos wanted.
int	get_median(t_llist *l, int size) // NOT DONE NEED TO CLASSE THE TABLE WHEN FULLING IT
{
	int		tab[size];
	int		i;
	t_llist	*temp;

	i = 0;
	temp = l;
	while (temp)
	{
		tab[i++] = temp->position_wanted;
		temp = temp->next;
	}
	return (tab[size / 2]);
}