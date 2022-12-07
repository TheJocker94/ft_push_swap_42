#include "lib/push_swap.h"

t_stack	*create_node(int val)
{
	t_stack	*i;

	i = (t_stack *)malloc(sizeof(t_stack));
	i->val = val;
	i->group = 0;
	i->order = 0;
	i->next = NULL;
	return (i);
}

void	addtop(t_stack **start, int new, int group)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	head->val = new;
	head->group = group;
	head->next = *start;
	*start = head;
}

void	addbot(t_stack **start, int new)
{
	t_stack	*last;
	t_stack	*tmp;

	last = (t_stack *)malloc(sizeof(t_stack));
	last->val = new;
	last->next = NULL;
	tmp = *start;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
}

t_stack	*create_list(int ac, char **av)
{
	int		i;
	t_stack	*start;
	t_stack	*tmp;
	t_stack	*next;

	i = 1;
	start = NULL;
	tmp = NULL;
	next = NULL;
	while (i < ac)
	{
		next = create_node(atoi(av[i]));
		if (start == NULL)
			start = next;
		if (tmp != NULL)
			tmp->next = next;
		tmp = next;
		i++;
	}
	return (start);
}

t_stack	*lst_last(t_stack *start)
{
	if (start == NULL)
		return (NULL);
	while (start->next != NULL)
		start = start->next;
	return (start);
}
