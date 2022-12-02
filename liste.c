/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:17:28 by ocastell          #+#    #+#             */
/*   Updated: 2022/11/30 18:17:36 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	display_list(d_list *start)
{
	d_list	*i;

	i = start;
	while (i != NULL)
	{
		printf(" %d", i->val);
		i = i->next;
		if (i == NULL)
			printf("\n");
	}
}

d_list	*create_node(int val)
{
	d_list	*i;

	i = (d_list *)malloc(sizeof(d_list));
	i->val = val;
	i->next = NULL;
	return (i);
}

void	release(d_list *start)
{
	d_list	*i;
	d_list	*next;

	i = start;
	next = NULL;
	while (i)
	{
		next = i->next;
		free(i);
		i = next;
	}
}

void	reverse_list(d_list **stnode)
{
	d_list	*prev;
	d_list	*curr;

	if (stnode != NULL)
	{
		prev = *stnode;
		curr = (*stnode)->next;
		*stnode = (*stnode)->next;
		prev->next = NULL; //convert the first node as last
		while (*stnode != NULL)
		{
			*stnode = (*stnode)->next;
			curr->next = prev;
			prev = curr;
			curr = *stnode;
		}
		*stnode = prev; //convert the last node as head
	}
}

void	addtop(d_list **start, int new)
{
	d_list	*head;

	head = (d_list *)malloc(sizeof(d_list));
	head->val = new;
	head->next = *start;
	*start = head;
}

void	addbot(d_list **start, int new)
{
	d_list	*last;
	d_list	*tmp;

	last = (d_list *)malloc(sizeof(d_list));
	last->val = new;
	last->next = NULL;
	tmp = *start;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
}

int	lst_size(d_list *start)
{
	int		i;
	d_list	*tmp;

	i = 0;
	tmp = start;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

d_list	*create_list(int ac, char **av)
{
	int		i;
	d_list	*start;
	d_list	*tmp;
	d_list	*next;

	i = 1;
	start = NULL;
	tmp = NULL;
	next = NULL;
	while (i < ac)
	{
		next = create_node(atoi(av[i]));
		if (start == NULL) //first node is equal to start
			start = next;
		if (tmp != NULL)
			tmp->next = next;
		tmp = next;
		i++;
	}
	return (start);
}

void	sw_a(d_list **start)
{
	d_list	*head;
	d_list	*temp;
	d_list	*next;

	head = NULL;
	temp = NULL;
	next = NULL;
	if ((*start)->next == NULL || *start == NULL)
		return ;
	head = (*start)->next;
	temp = (*start)->next->next;
	next = *start;
	head->next = next;
	next->next = temp;
	*start = head;
	write(1, "sa\n", 3);
}

void	push_b(d_list **stack_a, d_list **stack_b)
{
	d_list	*temp1;

	temp1 = *stack_a;
	addtop(stack_b, (*stack_a)->val);
	*stack_a = temp1->next;
	free(temp1);
	write(1, "pb\n", 3);
}

void	push_a(d_list **stack_a, d_list **stack_b)
{
	d_list	*temp1;

	temp1 = *stack_b;
	addtop(stack_a, (*stack_b)->val);
	*stack_b = temp1->next;
	free(temp1);
	write(1, "pa\n", 3);
}

d_list	*lst_last(d_list *start)
{
	while (start->next != NULL)
		start = start->next;
	return (start);
}

void	rot_a(d_list **stack_a)
{
	d_list	*last;
	d_list	*head;
	d_list	*new_head;

	if ((*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	new_head = (*stack_a)->next;
	last = lst_last(*stack_a);
	last->next = head;
	head->next = NULL;
	*stack_a = new_head;
	write(1, "ra\n", 3);
}

void	rr_a(d_list **stack_a)
{
	d_list	*last;
	d_list	*head;
	d_list	*new_last;

	if ((*stack_a)->next == NULL || *stack_a == NULL)
		return ;
	head = *stack_a;
	new_last = head;
	last = lst_last(*stack_a);
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	last->next = head;
	new_last->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
}

int	medium_val(d_list *list)
{
	int	medium;
	int	size;

	size = lst_size(list);
	medium = 0;
	while (list)
	{
		medium += list->val;
		list = list->next;
	}
	medium /= size;
	return (medium);
}
