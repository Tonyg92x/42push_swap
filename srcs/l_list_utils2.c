/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 11:00:00 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Add the contenu element at the top of the list entered.
void	add_top(t_llist *start, int contenu, int *len, int wanted)
{
	t_llist	*temp;
	int		tempor;

	tempor = (*len);
	temp = start;
	while (tempor > 0)
	{
		temp = temp->next;
		tempor--;
	}
	while (temp != start)
	{
		temp->content = temp->prev->content;
		temp->position_wanted = temp->position_wanted;
		temp = temp->prev;
	}
	start->content = contenu;
	start->position_wanted = wanted;
	(*len) = (*len) + 1;
}

// Delete the content at the top of the list
void	delete_top(t_llist *start, int *len)
{
	while (start->next != NULL)
	{
		start->content = start->next->content;
		start->position_wanted = start->next->position_wanted;
		start = start->next;
	}
	(*len) = (*len) - 1;
}
