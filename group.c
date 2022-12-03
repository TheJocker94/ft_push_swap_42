#include "lib/push_swap.h"


void is_group(d_list *a, int min, int max)
{
	d_list *node = a;
	int i;

	i = 0;
	while(node)
	{
		if (node->val >= min && node->val <= max)
			node->group = 1;
		i++;
		node = node->next;
	}
	return;
}
int pos_group_top(d_list *a, int id)
{
	int i;
	int size = lst_size(a);
	i = 1;
	while (a && (float)i <= (float)(size/2 ))
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

/*void	push_group(d_list **a, d_list **b)
{
	int pos_g;
	int list_size;
	int i = 1;
	int min = is_min(a);
	int inter = groupon(a);

	pos_g = pos_group(*a, min, min +inter);
	list_size = lst_size(*a);
	

	if ((float)pos_g <= (float)(list_size/2 + 1))
	{
		while (i != pos_g)
		{
			rot_a(a);
			i++;
		}
	}
	else if ((float)pos_g > (float)(list_size/2 ))
	{
		while ((float)pos_g <= (float)(list_size))
		{
			rr_a(a);
			pos_g++;
		}
	}
	push_b(a, b);
}*/