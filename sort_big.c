#include "lib/push_swap.h"

void	sort_logic(t_stack ***stack_a, t_stack ***stack_b, int size, int id)
{
	int		i;
	int		div;
	float	inter;
	float	min;

	i = 0;
	div = 5;
	min = is_min(**stack_a);
	//if (size <= 100)
	//	div = (size / 19);
	if (size > 100)
		div = (size / 62.5) + 5;
	inter = ((float)is_max(**stack_a) - min) / div;
	while (size > div)
	{
		while (is_group(**stack_a, min, min + inter, id))
			push_group(*stack_a, *stack_b, id);
		id++;
		min += inter + 1;
		i++;
		if (i == div)
			break ;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int size, int id)
{
	int		j;

	j = 0;
	sort_logic(&stack_a, &stack_b, size, id);
	while (*stack_b)
	{
		j = find_max_pos(*stack_b);
		push_max(stack_a, stack_b, j);
		if (stack_b == NULL)
			break ;
	}
}
