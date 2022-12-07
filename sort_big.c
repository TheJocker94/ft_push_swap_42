#include "lib/push_swap.h"

void	sort_logic(t_stack ***stack_a, t_stack ***stack_b, int size)
{

	//int		div;
	int id = 1;
	int i = 0;
	//div = 5;
	//if (size > 100)
		//div = (size / 62.5) + 5;
	while (i < size)
	{
		while (is_group(**stack_a, id) || is_group(**stack_a, id + 1))
		{
			push_group(*stack_a, *stack_b, id);
			i++;
		}
		id += 2; 
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		j;

	j = 0;
	sort_logic(&stack_a, &stack_b, size);
	while (*stack_b)
	{
		j = find_max_pos(*stack_b);
		push_max(stack_a, stack_b, j);
		if (stack_b == NULL)
			break ;
	}
}
