/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/11 14:47:07 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char		**n_argv;
	t_llist		**a;
	t_llist		**b;
	int			len_a;
	int			len_b;

	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		n_argv = ft_split(argv[1], ' ');
		a = malloc(argv_size(n_argv) + 1 * sizeof(t_llist*));
		b = malloc(argv_size(n_argv) + 1 * sizeof(t_llist*));
		a = init_list_a(n_argv, &len_a, a);
		if (a == NULL)
		{
			ft_free2d(n_argv);
			return(0);
		}
		init_list_b(n_argv, b);
	}
	else
	{
		a = malloc(argc * sizeof(t_llist*));
		b = malloc(argc * sizeof(t_llist*));
		init_list_a(&argv[1], &len_a, a);
		if (a == NULL)
			return(0);
		init_list_b(&argv[1], b);
	}
	if (protection_doublon(a, len_a))
	{
		if (n_argv)
			ft_free2d(n_argv);
		return (0);
	}
	print_list(a, b, &len_a, &len_b);
	sort_ll(a, b, &len_a, &len_b);
	print_list(a, b, &len_a, &len_b);
	if (argc == 2)
		ft_free2d(n_argv);
	return (0);
}
