/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/03/07 09:59:28 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	**initiate_argv(char **argv, int argc, t_llists *l)
{
	char	**retour;
	int		i;

	i = 0;
	l->len_a = 1;
	l->len_b = 0;
	l->start_b = NULL;
	if (argc == 2)
	{
		retour = ft_split(argv[1], ' ');
		if (retour[1] == NULL)
		{
			free(retour[0]);
			if (retour)
				free(retour);
			return (NULL);
		}
		return (retour);
	}
	return (&argv[1]);
}

static bool	leave(t_llists *l, int argc, char **argv, char c)
{
	if (c == 'a')
	{
		if (argv == NULL)
		{
			free(l);
			return (true);
		}
	}
	else if (c == 'b')
	{
		if (l->start_a == NULL)
		{
			free(l);
			if (argc == 2)
				ft_free2d(argv);
			return (true);
		}
	}
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
	argv = initiate_argv(argv, argc, l);
	if (leave(l, argc, argv, 'a'))
		return (0);
	l->start_a = init_list(argv, l);
	if (leave(l, argc, argv, 'b'))
		return (0);
	init_pos_wanted(l);
	init_option(l);
	sort_ll(l);
	if (argc == 2)
		ft_free2d(argv);
	ft_free_lists(l);
	return (0);
}
