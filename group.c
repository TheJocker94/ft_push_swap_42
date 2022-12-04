#include "lib/push_swap.h"


int is_group(d_list *a, int min, int max, int id)
{
	d_list *node = a;
	int i;

	i = 0;
	while(node)
	{
		if (node->val >= min && node->val <= max)
		{
			node->group = id;
			i = 1;
		}
		node = node->next;
	}
	return(i);
}
int pos_group_top(d_list *a, int id)
{
	int i;
	int size = lst_size(a);
	i = 1;
	while (a && i <= (size/2 + 1))
	{
		if (a->group == id)
			return(i);
		a = a->next;
		i++;
	}
	return (0);
	
}

int pos_group_bot(d_list *a, int id)
{
	int i;
	int size = lst_size(a);
	int chunk;

	chunk = 0;
	i = 0;
	while (a)
	{
		if (a->group == id && i >= size/2)
			chunk = i + 1;
		i++;
		a = a->next;
	}
	return (chunk);
	
}

int find_inter(d_list *a)
{
	int max = is_max(a);
	int min = is_min(a);
	int interv = (max - min)/5;
	return (interv);
}
void push_top(d_list **a, d_list **b, int pos)
{
	int i = 1;
	while (i != pos)
	{
		rot_a(a);
		i++;
	}
	push_b(a, b);
}

void push_bot(d_list **a, d_list **b, int pos, int list_size)
{
	while ((float)pos <= (float)(list_size))
	{
		rr_a(a);
		pos++;
	}
	push_b(a, b);
}

void	push_group(d_list **a, d_list **b, int id)
{
	int pos_top;
	int pos_bot;
	//int inter;
	int list_size;
	
	//inter = find_inter(*a);
	pos_top = pos_group_top(*a, id);
	pos_bot = pos_group_bot(*a, id);
	list_size = lst_size(*a);
	int act_top = pos_top - 1;
	int act_bot = list_size - pos_bot + 1;
	if ((pos_top - pos_bot == 0 || pos_bot == 0) && pos_top != 0)
		push_top(a, b, pos_top);
	else if ((act_top <= act_bot) && (act_top >= 0))
		push_top(a, b, pos_top);
	else if ((act_top > act_bot) || (pos_top == 0 && pos_bot != 0))
		push_bot(a, b, pos_bot, list_size);

}
