#include "lib/push_swap.h"

void	sort_logic(t_stack ***stack_a, t_stack ***stack_b, int size, int div)
{
	size++;
	//int		div;
	int id = 1;
	int i = 0;
	//div = 5;
	//if (size > 100)
		//div = (size / 62.5) + 5;
	//while (i < size)
	//	{
			while (div != 0)
			{
				push_group(*stack_a, *stack_b, id);
				i++;
				if (!is_group(**stack_a, id) || !is_group(**stack_a, id + 1))
					{
						div--;
						id++;
					}
			}
	//		id += 2; 
	//	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int size, int div)
{
	int		j;
	int		min;
	int		max;

	int		i = 0;
	j = 0;
	sort_logic(&stack_a, &stack_b, size, div);
	//while (*stack_b)
	//{
	while (div != -1)
	{
		min = is_min_group(*stack_b, div);
		max = is_max(*stack_b);
		j = find_max_min_pos(*stack_b, div);
		i += push_max_min(stack_a, stack_b, j, min, max);
		if (!is_group(*stack_b, div))
		{
			while (i>0)
				{
					rr_a(stack_a);
					i--;
				}
			div--;
		}
		if (stack_b == NULL)
			break ;
	}
	//div--;
	//i = 0;
	//if (stack_b == NULL)
	//		break ;
	//}
}
