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

	i = 1;
	while (i != pos)
	{
		rot_a(a);
		i++;
	}
	push_b(a, b);
}

void	push_bot(t_stack **a, t_stack **b, int pos, int list_size)
{
	while ((float)pos <= (float)(list_size))
	{
		rr_a(a);
		pos++;
	}
	push_b(a, b);
}

int	is_ordered(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}
