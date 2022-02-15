/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/15 13:10:05 by aguay            ###   ########.fr       */
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
	t_llists	*lists;

	lists = malloc(sizeof(t_llists));
	lists->len_a = 1;
	lists->len_b = 0;
	if (argc <= 1)
		return (0);
	argv = initiate_argv(argv, argc);
	lists->start_a = init_list_a(argv, lists);
	if (lists->start_a == NULL)
		return (0);
	lists->start_b = init_list_b(argv, lists);
	ft_free2d(argv);
	print_list(lists);
	ft_free_lists(lists);
	return (0);
}
