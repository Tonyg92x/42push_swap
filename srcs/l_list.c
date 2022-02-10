#include "libft.h"
#include "push_swap.h"

int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

// Fonction wich look in the list if any value is not in int limit.
bool     lim_test(char **argv)
{
        int		i;
        long int        content;
	int		size;

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

t_llist	**init_list_a(char **argv,  int *len_a, t_llist **a)
{
	int	i;

	if (lim_test(argv))
		return (NULL);
	i = 0;
	while (argv[i] != NULL)
	{
		a[i] = malloc(sizeof(t_llist));
		a[i]->content = ft_atoi(argv[i]);
		if (i > 0)
		{
			a[i]->prev = a[i - 1];
			a[i - 1]->next = a[i];
		}
		(*len_a)++;
		i++;
	}
	return (a);
}

t_llist	**init_list_b(char **argv, int *len_b, t_llist **b)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		b[i] = malloc(sizeof(t_llist));
		if (i > 0)
		{
			b[i]->prev = b[i - 1];
			b[i - 1]->next = b[i];
		}
		(*len_b)++;
		i++;
	}
	return (b);
}
