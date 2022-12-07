#include "lib/push_swap.h"

int	find_max_min_pos(t_stack *a, int div)
{
	int		i;
	t_stack	*last;

	last = lst_last(a);
	i = 0;
	if (last == NULL)
		return (0);
	if ((last->val == is_max(a) || last->val == is_min_group(a, div)) && last->group == div)
		return (lst_size(a));
	while ((a->val != is_max(a) || a->val != is_min_group(a, div)) && ((a != NULL)))
	{
		a = a->next;
		i++;
	}
	i++;
	return (i);
}

int	push_max_min(t_stack **a, t_stack **b, int pos, int min, int max)
{
	int	list_size;
	int	i;

	i = 1;
	list_size = lst_size(*b);
	if ((float)pos <= (float)(list_size / 2 + 1))
	{
		while (i != pos)
		{
			rot_b(b);
			i++;
		}
	}
	else if ((float)pos > (float)(list_size / 2))
	{
		while ((float)pos <= (float)(list_size))
		{
			rr_b(b);
			pos++;
		}
	}
	if ((*b)->val == max)
		{//rot_a(a);
			push_a(a, b);
		}
	else if ((*b)->val == min)
		{
			push_a(a, b);
			rot_a(a);
			return (1);
		}
		return(0);

}