/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/11 13:08:28 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// Delete the element on the top of the stack.
void	delete_top(t_llist **list, int *len)
{
	int	i;

	i = 0;
	while (i + 1 < (*len))
	{
		list[i]->content = list[i + 1]->content;
		i++;
	}
	list[i]->content = 2147483647;
	(*len)--;
}

// Add the element on the top of the stack.
void	add_top(t_llist **list, int contenu, int *len)
{
	int	i;

	if ((*len) == 0)
	{
		add_element(contenu, len, list[0]);
		return ;
	}
	i = (*len);
	while (i > 0)
	{
		list[i]->content = list[i - 1]->content;
		i--;
	}
	list[0] = add_element(contenu, len, list[0]);
}

// Add the element in the list entered.
t_llist	*add_element(int element, int *len, t_llist *list)
{
	list->content = element;
	(*len)++;
	return (list);
}
