/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 14:53:23 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	**initiate_argv(char **argv, int argc)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (&argv[1]);
}

int	main(int argc, char **argv)
{
	t_llist	*start_a;
	t_llist	*start_b;
	int		len_a;
	int		len_b;

	len_a = 1;
	len_b = 0;
	if (argc <= 1)
		return (0);
	argv = initiate_argv(argv, argc);
	start_a = init_list_a(argv, &len_a);
	if (start_a == NULL)
		return (0);
	start_b = init_list_b(argv);
	print_list(start_a, start_b, len_a, len_b);
	if (argc == 2)
		ft_free2d(argv);
	ft_free_lists(start_a, start_b);
	return (0);
}
