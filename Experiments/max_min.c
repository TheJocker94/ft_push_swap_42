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

int	pos_max_min_top(t_stack *a, int min, int max)
{
	int	i;
	int	size;

	size = lst_size(a);
	i = 1;
	while (a && i <= (size / 2 + 1))
	{
		if (((a->val == max) || (a->val == min)))
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}


int	pos_max_min_bot(t_stack *a, int min, int max)
{
	int	i;
	int	size;
	int	pos;

	size = lst_size(a);
	pos = 0;
	i = 0;
	while (a)
	{
		if (((a->val == max) || (a->val == min)) && i >= size / 2)
			pos = i + 1;
		i++;
		a = a->next;
	}
	return (pos);
}
int	push_top_back(t_stack **a, t_stack **b, int pos, int min)
{
	int	i;
	//int min;
	//int size;
	//size = lst_size(*b);
	i = 1;
	//min = find_min_pos(*b);
	while (i != pos)
	{
		rot_b(b);
		i++;
	}
//	if (min < size && (*a)->val > min)
//		push_ordered(b, min);
	if ((*b)->val == min)
	{
		i = 1;
		push_a(a, b);
		rot_a(a);
	}
	else
	{
		i = 0;
		push_a(a, b);
	}
	return (i);
}

int	push_bot_back(t_stack **a, t_stack **b, int pos, int list_size, int min)
{
	//int min;
	int i;
	//int size;
	//size = lst_size(*b);
	//min = find_min_pos(*b);
	while ((float)pos <= (float)(list_size))
	{
		rr_b(b);
		pos++;
	}
	if ((*b)->val == min)
	{
		i = 1;
		push_a(a, b);
		rot_a(a);
	}
	else
	{
		i = 0;
		push_a(a, b);
	}
	return (i);
}
int	push_group_ret(t_stack **a, t_stack **b, int min, int max)
{
	int	pos_top;
	int	pos_bot;
	int	list_size;
	int	act_top;
	int	act_bot;
	int i;
	//int	id;

	//id = 1;
	pos_top = pos_max_min_top(*b, min, max);
	pos_bot = pos_max_min_bot(*b, min, max);
	list_size = lst_size(*b);
	act_top = pos_top - 1;
	act_bot = list_size - pos_bot + 1;

	//if (!is_group(*a, id) && !is_group(*a, id))
	//	id += 2;
	if ((pos_top - pos_bot == 0 || pos_bot == 0) && pos_top != 0)
		i = push_top_back(a, b, pos_top, min);
	else if ((act_top <= act_bot) && (act_top >= 0))
		i = push_top_back(a, b, pos_top, min);
	else if ((act_top > act_bot) || (pos_top == 0 && pos_bot != 0))
		i = push_bot_back(a, b, pos_bot, list_size, min);
	//if (((*b)->next != NULL) && ((*b)->group <= lst_last(*b)->group))
	//	rot_b(b);
	//else
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