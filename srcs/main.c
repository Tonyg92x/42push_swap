/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/10 08:12:11 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// Print every element of both list
void	print_list(t_llist **a, t_llist **b, int *len_a, int *len_b)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	ft_printf("\n------------------------\n");
	while (i < (*len_a) || y < (*len_b))
	{
		if (i < (*len_a))
		{
			ft_printf("%d \t", a[i]->content, i);
			i++;
		}
		else
			ft_printf(" \t");
		if (y < (*len_b))
		{
			ft_printf("%d \n", b[y]->content);
			y++;
		}
		else
			ft_printf("\n");
	}
	ft_printf("-\t-\na\tb\n\n");
}

// Fonction wich verify if arguments are not
// called 2 times.
bool	protection_doublon(t_llist **l, int len)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < len)
	{
		y = 0;
		while (y < i)
		{
			if (l[i]->content == l[y]->content)
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

int	main(int argc, char **argv)
{
	char		**n_argv;
	t_llist		**a;
	t_llist		**b;
	int		len_a;
	int		len_b;

	if (argc <= 1)
		return (0);
	ft_printf("argc = %d\n", argc);
	if (argc == 2)
	{
		n_argv = ft_split(argv[1], ' ');
		ft_printf("%d\n", argv_size(n_argv));
		a = malloc(argv_size(n_argv) + 1 * sizeof(t_llist*));
		b = malloc(argv_size(n_argv) + 1* sizeof(t_llist*));
		init_list_a(n_argv, &len_a, a);
		init_list_b(n_argv, &len_b, b);
	}
	else
	{
		a = malloc(argc * sizeof(t_llist*));
		b = malloc(argc * sizeof(t_llist*));
		init_list_a(&argv[1], &len_a, a);
		init_list_b(&argv[1], &len_b, b);
	}
	sort_ll(a, b, &len_a, &len_b);
	if (argc == 2)
		ft_free2d(n_argv);
	return (0);
}
