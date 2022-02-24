/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/24 11:16:21 by aguay            ###   ########.fr       */
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

static bool	initialise(t_llists *l, char **argv, int argc)
{
	argv = initiate_argv(argv, argc);
	l->start_a = init_list(argv, l);
	init_pos_wanted(l);
	if (l->start_a == NULL)
	{
		free(l);
		if (argc == 2)
			ft_free2d(argv);
		return (true);
	}
	init_option(l);
	if (l->start_a == NULL)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_llists	*l;

	if (argc <= 1)
		return (0);
	l = malloc(sizeof(t_llists));
	if (!l)
		return (0);
	l->len_a = 1;
	l->len_b = 0;
	l->start_b = NULL;
	if (initialise(l, argv, argc))
		return (0);
	sort_ll(l);
	if (argc == 2)
		ft_free2d(argv);
	ft_free_lists(l);
	return (0);
}
