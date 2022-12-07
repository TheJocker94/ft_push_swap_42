#include "lib/push_swap.h"

void	init_min(t_stack *a)
{
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
	node->order = 1;
	node->group = 1;
	return ;
}

void	is_newmin(t_stack *a, int order, int group)
{
	t_stack	*node;
	t_stack	*temp;

	node = a;
	temp = node->next;
	while (temp)
	{
		while ((temp) && ((node->val < temp->val) || (temp->order != 0 )))
		{
			if (node->order > 0)
				break;	
			temp = temp->next;
		}
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	if (node->group == 0)
		node->group = group;
	//if (node->order == 0)
	node->order = order;
	return ;
}

void	groupon(t_stack **a, int size, int div)
{
	int		i;
	//int		div;
	int		g_size;
	int		group;
	int		order;
	int		j;

	order = 2;
	group = 1;
	i = 1;
	init_min(*a);
	//if (size > 100)
	//	div = (size / 62.5) + 10;
	g_size = size / div;
	j = size % div;
	if (j > 0)
		g_size++;
	while (group <= div)
	{
		while (i < g_size)
		{
			is_newmin(*a, order, group);
			i++;
			order++;
		}
		j--;
		group ++;
		i = 0;
		if (j == 0)
			g_size--;
	}
}