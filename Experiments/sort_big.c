#include "lib/push_swap.h"

void	sort_logic(t_stack ***stack_a, t_stack ***stack_b, int size, int div)
{
	//size++;
	//int		div;
	div++;
	int id = 1;
	while (size--)
	{
		while (is_group(**stack_a, id) || is_group(**stack_a, id + 1))
			push_group(*stack_a, *stack_b, id);
		id += 2; 
	}
	//		id += 2; 
	//	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int size, int div)
{
	//int		j;
	int		min;
	int		max;

	int		i = 0;
	//j = 0;
	sort_logic(&stack_a, &stack_b, size, div);
	//while (*stack_b)
	//{
	while (*stack_b)
	{
		min = is_min_group(*stack_b, div);
		max = is_max(*stack_b);
		//j = find_max_min_pos(*stack_b, div);
		i += push_group_ret(stack_a, stack_b, min, max);
		if (!is_group(*stack_b, div))
		{
			while (i--)
				{
					rr_a(stack_a);
					//i--;
				}
			div--;
			i = 0;
		}
		
		//if (stack_b == NULL)
		//	break ;
		//i = 0;
	}
	//div--;
	//i = 0;
	//if (stack_b == NULL)
	//		break ;
	//}
}
