/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/21 10:51:46 by aguay            ###   ########.fr       */
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
	t_llists	*l;

	l = malloc(sizeof(t_llists));
	if (!l)
		return (0);
	l->len_a = 1;
	l->len_b = 0;
	l->start_b = NULL;
	if (argc <= 1)
		return (0);
	argv = initiate_argv(argv, argc);
	l->start_a = init_list(argv, l);
	init_med(l);
	if (l->start_a == NULL)
		return (0);
	sort_ll(l);
	print_lists(l);
	if (argc == 2)
		ft_free2d(argv);
	ft_free_lists(l);
	return (0);
}
