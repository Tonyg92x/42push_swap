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

//	Fonction that return true if any arguments in
//	argv are identical.
bool	check_doublons(char **argv)
{
	int		i;
	int		y;
	int		*content;
	int		size;

	size = argv_size(argv);
	content = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		y = 0;
		while (y < size)
		{
			if (content[y] == ft_atoi(argv[i]))
			{
				ft_printf("Error\n");
				return (true);
			}
			y++;
		}
		content[i] = ft_atoi(argv[i]);
		i++;
	}
	return (false);
}

//	Put every element of the string list in a linked list.
//	PS : Don't forget to free the memory.
t_llist	*init_list_a(char **argv,  int *len)
{
	int		i;
	t_llist	*l;

	if (lim_test(argv))
		return (NULL);
	if (check_doublons(argv))
		return (NULL);
	l = malloc(sizeof(t_llist));
	l->content = ft_atoi(argv[0]);
	i = 1;
	while (argv[i] != NULL && argv_size(argv) > i - 1)
	{
		(*len) = (*len) + 1;
		add_list(l, ft_atoi(argv[i]));
		i++;
	}
	return (l);
}

//	Put every element of the string list in a linked list.
//	PS : Don't forget to free the memory.
t_llist	*init_list_b(char **argv)
{
	int		i;
	t_llist	*l;
	t_llist	*temp;

	if (lim_test(argv))
		return (NULL);
	if (check_doublons(argv))
		return (NULL);
	l = malloc(sizeof(t_llist));
	i = 1;
	while (argv_size(argv) > i - 1)
	{
		temp = lst_last(l);
		temp->next = malloc(sizeof(t_llist));
		temp->next->prev = temp;
		i++;
	}
	return (l);
}