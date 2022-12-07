#include "lib/push_swap.h"

int	is_min(t_stack *a)
{
	int		min;
	t_stack	*node;
	t_stack	*temp;

	node = a;
	temp = node->next;
	while (temp)
	{
		while ((temp) && (node->val < temp->val))
			temp = temp->next;
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	min = node->val;
	return (min);
}
int	is_min_group(t_stack *a, int div)
{
	int		min;
	t_stack	*node;
	t_stack	*temp;

	min = 0;
	node = a;
	temp = node->next;
	while (temp)
	{
		
		while (((temp) && (node->val < temp->val)) || temp->group != div)
		{
			if (node->group != div)
				break;
			temp = temp->next;
			if (temp == NULL)
				break;
		}
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	if (node->group == div)
		min = node->val;
	return (min);
}

int	find_min_pos(t_stack *a)
{
	int		i;
	t_stack	*last;

	last = lst_last(a);
	i = 0;
	if (last == NULL)
		return (0);
	if (last->val == is_min(a))
		return (lst_size(a));
	while ((a->val != is_min(a)) && (a != NULL))
	{
		a = a->next;
		i++;
	}
	i++;
	return (i);
}

void	push_min(t_stack **a, t_stack **b)
{
	int	pos_min;
	int	list_size;
	int	i;

	i = 1;
	pos_min = find_min_pos(*a);
	list_size = lst_size(*a);
	if ((float)pos_min <= (float)(list_size / 2 + 1))
	{
		while (i != pos_min)
		{
			rot_a(a);
			i++;
		}
	}
	else if ((float)pos_min > (float)(list_size / 2))
	{
		while ((float)pos_min <= (float)(list_size))
		{
			rr_a(a);
			pos_min++;
		}
	}
	push_b(a, b);
}
