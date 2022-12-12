#include "lib/push_swap.h"

void	release(t_stack *start)
{
	t_stack	*i;
	t_stack	*next;

	i = start;
	next = NULL;
	while (i)
	{
		next = i->next;
		free(i);
		i = next;
	}
}

int	lst_size(t_stack *start)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = start;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
