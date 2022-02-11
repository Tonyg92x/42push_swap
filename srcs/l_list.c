#include "libft.h"
#include "push_swap.h"

// Get the number of strings in a string list
int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

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

//	Put every element of the string list in a linked list.
//	PS : Don't forget to free the memory.
t_llist	**init_list_a(char **argv,  int *len_a, t_llist **a)
{
	int	i;

	if (lim_test(argv))
		return (NULL);
	i = 0;
	while (argv[i] != NULL && argv_size(argv) > i - 1)
	{
		a[i] = malloc(sizeof(t_llist));
		add_element(ft_atoi(argv[i]), len_a, a[i]);
		i++;
	}
	return (a);
}

//	Allocate all the memory necessery for the b list
//	PS : Don't forget to free the memory
t_llist	**init_list_b(char **argv, t_llist **b)
{
	int	i;

	i = 0;
	while (argv[i] != NULL && argv_size(argv) > i - 1)
	{
		b[i] = malloc(sizeof(t_llist));
		i++;
	}
	return (b);
}
