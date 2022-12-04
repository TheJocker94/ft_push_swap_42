#include "lib/push_swap.h"

int	is_max(t_stack *a)
{
	int		max;
	t_stack	*node;
	t_stack	*temp;

	node = a;
	temp = node->next;
	while (temp)
	{
		while ((temp) && (node->val > temp->val))
			temp = temp->next;
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	max = node->val;
	return (max);
}

int	find_max_pos(t_stack *a)
{
	int		i;
	t_stack	*last;

	last = lst_last(a);
	i = 0;
	if (last == NULL)
		return (0);
	if (last->val == is_max(a))
		return (lst_size(a));
	while ((a->val != is_max(a)) && (a != NULL))
	{
		a = a->next;
		i++;
	}
	i++;
	return (i);
}

void	push_max(t_stack **a, t_stack **b, int max)
{
	int	list_size;
	int	i;

	i = 1;
	list_size = lst_size(*b);
	if ((float)max <= (float)(list_size / 2 + 1))
	{
		while (i != max)
		{
			rot_b(b);
			i++;
		}
	}
	else if ((float)max > (float)(list_size / 2))
	{
		while ((float)max <= (float)(list_size))
		{
			rr_b(b);
			max++;
		}
	}
	push_a(a, b);
}
