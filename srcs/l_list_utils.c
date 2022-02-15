/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 14:58:07 by aguay            ###   ########.fr       */
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
	t_llist	*temp;
	
	temp = lst_last(l);
	temp->next = malloc(sizeof(t_llist));
	temp->next->prev = l;
	temp->next->content = content;
}

// Print every element of both list
void	print_list(t_llist *start_a, t_llist *start_b, int len_a, int len_b)
{
	ft_printf("\na\t\tb");
	ft_printf("\n------------------------\n");
	while (len_a > 0 || len_b > 0)
	{
		if (len_a > 0)
		{
			ft_printf("%d", start_a->content);
			start_a = start_a->next;
			len_a--;
		}
		ft_printf("\t\t");
		if (len_b > 0)
		{
			ft_printf("%d", start_b->content);
			start_b = start_b->next;
			len_b--;
		}
		ft_printf("\n");
	}
	ft_printf("------------------------\n");
}

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
