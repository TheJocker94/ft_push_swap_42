#include "lib/push_swap.h"

int	is_min(d_list *a)
{
	int min;
	d_list *node = a;
	d_list *temp = node->next;
	
	while (temp)
	{
		while((temp) && (node->val < temp->val))
			temp = temp->next;
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	min = node->val;
	return(min);
}

int	is_max(d_list *a)
{
	int max;
	d_list *node = a;
	d_list *temp = node->next;
	
	while (temp)
	{
		while((temp) && (node->val > temp->val))
			temp = temp->next;
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	max = node->val;
	return(max);
}

int	find_min_pos(d_list *a)
{
	int i;
	d_list *last;
	
	last = lst_last(a);
	i = 0;
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
/*
void	push_min(d_list **a, d_list **b)
{
	int pos_min;
	int list_size;
	int i = 1;

	pos_min = find_min_pos(*a);
	list_size = lst_size(*a);
	if ((float)pos_min > (float)list_size/2)
	{
		while ((float)pos_min <= (float)(list_size))
		{
			rr_a(a);
			pos_min++;
		}
	}
	else if ((float)pos_min <= (float)list_size/2)
	{
		while (i != pos_min)
		{
			rot_a(a);
			i++;
		}
	}
	push_b(a, b);
}*/

void	push_min(d_list **a, d_list **b)
{
	int pos_min;
	int list_size;
	int i = 1;

	pos_min = find_min_pos(*a);
	list_size = lst_size(*a);
	

	if ((float)pos_min <= (float)(list_size/2 + 1))
	{
		while (i != pos_min)
		{
			rot_a(a);
			i++;
		}
	}
	else if ((float)pos_min > (float)(list_size/2 ))
	{
		while ((float)pos_min <= (float)(list_size))
		{
			rr_a(a);
			pos_min++;
		}
	}
	push_b(a, b);
}