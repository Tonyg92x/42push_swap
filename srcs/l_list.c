/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 12:54:36 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonction wich look in the list if any value is not in int limit.
bool	lim_test(char **argv)
{
	int			i;
	long int	content;
	int			size;

	size = argv_size(argv);
	i = 0;
	while (size > 0)
	{
		content = ft_atol(argv[i]);
		if (content > 2147483647 || content < -2147483648)
		{
			ft_printf("Error\n");
			return (true);
		}
		i++;
		size--;
	}
	return (false);
}

// Comparer every element to look for "doulons"
static bool	compare_elements(int *content, int size)
{
	int	y;
	int	i;

	i = 0;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (content[i] == content[y])
			{
				ft_printf("Error\n");
				return (true);
			}
			y++;
		}
		i++;
	}
	free(content);
	return (false);
}

//	Fonction that return true if any arguments in
//	argv are identical.
bool	check_doublons(char **argv)
{
	int		i;
	int		*content;
	int		size;

	size = argv_size(argv);
	content = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		content[i] = ft_atoi(argv[i]);
		i++;
	}
	if (compare_elements(content, size))
		return (true);
	return (false);
}

//	Put every element of the string list in a linked list.
//	PS : Don't forget to free the memory.
t_llist	*init_list_a(char **argv, t_llists *l)
{
	int		i;

	if (lim_test(argv))
		return (NULL);
	if (check_doublons(argv))
		return (NULL);
	l->start_a = malloc(sizeof(t_llist));
	l->start_a->content = ft_atoi(argv[0]);
	i = 1;
	while (argv[i] != NULL && argv_size(argv) > i - 1)
	{
		add_list(l->start_a, ft_atoi(argv[i]));
		l->len_a++;
		i++;
	}
	return (l->start_a);
}

//	Put every element of the string list in a linked list.
//	PS : Don't forget to free the memory.
t_llist	*init_list_b(char **argv, t_llists *l)
{
	int		i;
	t_llist	*temp;

	l->start_b = malloc(sizeof(t_llist));
	i = 1;
	while (argv_size(argv) > i - 1)
	{
		temp = lst_last(l->start_b);
		temp->next = malloc(sizeof(t_llist));
		temp->next->prev = temp;
		i++;
	}
	return (l->start_b);
}
