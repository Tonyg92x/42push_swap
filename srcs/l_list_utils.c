/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/16 14:47:01 by aguay            ###   ########.fr       */
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

bool	check_digit(char **argv)
{
	int	i;
	int	y;
	int	size;

	size = argv_size(argv);
	i = 0;
	while (i < size)
	{
		y = 0;
		while (argv[i][y])
		{
			if (isdigit(argv[i][y]) == false && argv[i][y] != ' ' &&
			argv[i][y] != '-')
			{
				ft_printf("Error\n");
				return (true);
			}
			y++;
		}
		i++;
	}
	return (false);
}

// Print every element of both list
void	print_lists(t_llists *l)
{
	t_llist	*a;
	t_llist	*b;
	int		len_a;
	int		len_b;

	len_a = l->len_a;
	len_b = l->len_b;
	a = l->start_a;
	b = l->start_b;
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

void	ft_free_lists(t_llists *l)
{
	t_llist	*a;
	t_llist	*b;

	a = l->start_a;
	b = l->start_b;
	while (a->next != NULL)
	{
		a = a->next;
		free(a->prev);
	}
	free(a);
	while (b->next != NULL)
	{
		b = b->next;
		free(b->prev);
	}
	free(b);
	free(l);
}
