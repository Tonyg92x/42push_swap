/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/12 09:28:23 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_free_lists(t_llist *a, t_llist *b)
{
	a = lst_last(a);
	b = lst_last(b);
	while (a->prev != NULL)
	{
		a = a->prev;
		free(a->next);
	}
	free(a);
	while (b->prev != NULL)
	{
		b = b->prev;
		free(b->next);
	}
	free(b);
}