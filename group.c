#include "lib/push_swap.h"

int	is_group(t_stack *a, int min, int max, int id)
{
	t_stack	*node;
	int		i;

	node = a;
	i = 0;
	while (node)
	{
		if (node->val >= min && node->val <= max)
		{
			node->group = id;
			i = 1;
		}
		node = node->next;
	}
	return (i);
}

int	pos_group_top(t_stack *a, int id)
{
	int	i;
	int	size;

	size = lst_size(a);
	i = 1;
	while (a && i <= (size / 2 + 1))
	{
		if (a->group == id)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	pos_group_bot(t_stack *a, int id)
{
	int	i;
	int	size;
	int	chunk;

	size = lst_size(a);
	chunk = 0;
	i = 0;
	while (a)
	{
		if (a->group == id && i >= size / 2)
			chunk = i + 1;
		i++;
		a = a->next;
	}
	return (chunk);
}

void	push_group(t_stack **a, t_stack **b, int id)
{
	int	pos_top;
	int	pos_bot;
	int	list_size;
	int	act_top;
	int	act_bot;

	pos_top = pos_group_top(*a, id);
	pos_bot = pos_group_bot(*a, id);
	list_size = lst_size(*a);
	act_top = pos_top - 1;
	act_bot = list_size - pos_bot + 1;
	if ((pos_top - pos_bot == 0 || pos_bot == 0) && pos_top != 0)
		push_top(a, b, pos_top);
	else if ((act_top <= act_bot) && (act_top >= 0))
		push_top(a, b, pos_top);
	else if ((act_top > act_bot) || (pos_top == 0 && pos_bot != 0))
		push_bot(a, b, pos_bot, list_size);
	//if (((*b)->next != NULL) && ((*b)->val > (*b)->next->val))
	//	sw_b(b);
}
