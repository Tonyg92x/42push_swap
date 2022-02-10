/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/02 14:27:23 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Get the biggest content in the list entered
int	biggest_list(t_llist **list, int *len)
{
	int	i;
	int	retour;
	int	tab[1000000];

	if ((*len) == 0)
		return (0);
	i = 0;
	while (list[i]->next != NULL)
	{
		tab[i] = list[i]->content;
		i++;
	}
	tab[i] = list[i]->content;
	retour = 0;
	i = 0;
	while (i < (*len))
	{
		if (tab[i] > tab[retour])
			retour = i;
		i++;
	}
	i = tab[retour];
	return (i);
}

// Get the smallest content in the list entered
int	smallest_list(t_llist **list, int *len)
{
	int	i;
	int	retour;
	int	tab[1000000];

	i = 0;
	while (list[i]->next != NULL)
	{
		tab[i] = list[i]->content;
		i++;
	}
	tab[i] = list[i]->content;
	retour = 0;
	i = 0;
	while (i < (*len))
	{
		if (tab[i] < tab[retour])
			retour = i;
		i++;
	}
	i = tab[retour];
	return (i);
}

// Fonction that get the smallest
// integer in a interger table.
int	smallest(int *tab, int *len)
{
	int	i;
	int	retour;

	i = 0;
	retour = 0;
	while (i < (*len))
	{
		if (tab[i] < tab[retour])
			retour = i;
		i++;
	}
	i = tab[retour];
	tab[retour] = 2147483647;
	return (i);
}

// Get the value of the median
int	get_median(t_llist **l, int *len)
{
	int	temp[1000000];
	int	retour[1000000];
	int	i;

	i = 0;
	while (i < (*len))
	{
		temp[i] = l[i]->content;
		i++;
	}
	i = 0;
	while (i < (*len))
	{
		retour[i] = smallest(temp, len);
		i++;
	}
	i = retour[((*len)) / 2];
	return (i);
}
