#include "lib/push_swap.h"

int	find_inter(t_stack *a)
{
	int	max;
	int	min;
	int	interv;

	max = is_max(a);
	min = is_min(a);
	interv = (max - min) / 5;
	return (interv);
}

void	push_top(t_stack **a, t_stack **b, int pos)
{
	int	i;
	int min;
	int size;

	size = lst_size(*b);
	i = 1;
	min = find_min_pos(*b);
	while (i != pos)
	{
		rot_a(a);
		i++;
	}
	if (min < size && (*a)->val > min)
		push_ordered(b, min);
	push_b(a, b);
}

void	push_bot(t_stack **a, t_stack **b, int pos, int list_size)
{
	int min;
	//int size;

	//size = lst_size(*b);
	min = find_min_pos(*b);
	while ((float)pos <= (float)(list_size))
	{
		rr_a(a);
		pos++;
	}
	if (min < list_size && (*a)->val > min)
		push_ordered(b, min);
	push_b(a, b);
}
// Pusha min in b giu
void push_ordered(t_stack **b, int min)
{
	int	list_size;
	//int	i;

	//i = 1;
	list_size = lst_size(*b);
	if ((float)min >= (float)(list_size / 2))
	{
		while (min != list_size)
		{
			rr_b(b);
			min++;
		}
	}
	else if ((float)min < (float)(list_size / 2))
	{
		while ((float)min >= 1)
		{
			rot_b(b);
			min--;
		}
	}
}
//Pusha min su
/*void push_ordered(t_stack **b, int min)
{
	int	list_size;
	int	i;

	i = 1;
	list_size = lst_size(*b);
	if ((float)min <= (float)(list_size / 2 + 1))
	{
		while (i != min)
		{
			rot_b(b);
			i++;
		}
	}
	else if ((float)min > (float)(list_size / 2))
	{
		while ((float)min <= (float)(list_size))
		{
			rr_b(b);
			min++;
		}
	}
}*/

/*int	is_ordered(t_stack *a)
{
	while(a != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}*/