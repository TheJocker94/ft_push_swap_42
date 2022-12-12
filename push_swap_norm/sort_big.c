#include "lib/push_swap.h"

void	sort_logic(t_stack ***stack_a, t_stack ***stack_b, int size)
{
	int	id;

	id = 1;
	while (size--)
	{
		while (is_group(**stack_a, id) || is_group(**stack_a, id + 1))
			push_group(*stack_a, *stack_b, id);
		id += 2;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int size, int div)
{
	int		min;
	int		max;
	int		i;

	i = 0;
	sort_logic(&stack_a, &stack_b, size);
	while (*stack_b)
	{
		min = is_min_group(*stack_b, div);
		max = is_max(*stack_b);
		i += push_group_back(stack_a, stack_b, min, max);
		if (!is_group(*stack_b, div))
		{
			while (i--)
				rr_a(stack_a);
			div--;
			i = 0;
		}
	}
}
