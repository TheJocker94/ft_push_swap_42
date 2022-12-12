#include "lib/push_swap.h"

int	is_group(t_stack *a, int id)
{
	t_stack	*node;
	int		i;

	node = a;
	i = 0;
	while (node)
	{
		if (node->group == id)
		{
			i = 1;
			break ;
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
		if (((a->group == id) || (a->group == (id + 1))))
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
	int	pos;

	size = lst_size(a);
	pos = 0;
	i = 0;
	while (a)
	{
		if (((a->group == id) || (a->group == (id + 1))) && i >= size / 2)
			pos = i + 1;
		i++;
		a = a->next;
	}
	return (pos);
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
	if (((*b)->next != NULL) && ((*b)->group >= lst_last(*b)->group))
	{
		rot_b(b);
	}
	else
		return ;
}

int	is_next_top(t_stack **a, int id)
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
		return (1);
	else if ((act_top <= act_bot) && (act_top >= 0))
		return (1);
	else if ((act_top > act_bot) || (pos_top == 0 && pos_bot != 0))
		return (0);
	else
		return (0);
}
