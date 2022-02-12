/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyg <tonyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2022/02/12 09:28:59 by tonyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char		**n_argv;
	t_llist		*start_a;
	t_llist		*start_b;
	int			len_a;
	int			len_b;

	len_a = 1;
	len_b = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		n_argv = ft_split(argv[1], ' ');
		start_a = init_list_a(n_argv, &len_a);
		if (start_a == NULL)
		{
			ft_free2d(n_argv);
			return(0);
		}
		start_b = init_list_b(n_argv);
	}
	else
	{
		start_a = init_list_a(&argv[1], &len_a);
		if (start_a == NULL)
			return (0);
		start_b = init_list_b(&argv[1]);
	}
	print_list(start_a, start_b, len_a, len_b);
	// sort_ll(a, b, &len_a, &len_b);
	if (argc == 2)
		ft_free2d(n_argv);
	ft_free_lists(start_a, start_b);
	return (0);
}
