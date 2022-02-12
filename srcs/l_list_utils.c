/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/12 09:24:21 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// Get the number of strings in a string list
int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

t_llist	*lst_last(t_llist *l)
{
	while (l->next != NULL)
		l = l->next;
	return (l);
}

void	add_list(t_llist *l, int content)
{
	l = lst_last(l);
	l->next = malloc(sizeof(t_llist));
	l->next->prev = l;
	l->next->content = content;	
}

// Print every element of both list
void	print_list(t_llist *a, t_llist *b, int len_a, int len_b)
{
	ft_printf("\na\t\tb");
	ft_printf("\n------------------------\n");
	while (len_a > 0 || len_b > 0)
	{
		if (len_a > 0)
		{
			ft_printf("%d", a->content);
			a = a->next;
			len_a--;
		}
		ft_printf("\t\t");
		if (len_b > 0)
		{
			ft_printf("%d", b->content);
			b = b->next;
			len_b--;
		}
		ft_printf("\n");
	}
	ft_printf("------------------------\n");
}