#include "lib/push_swap.h"

void	sw_a(t_stack **start)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*next;

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

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp1;

	temp1 = *stack_b;
	addtop(stack_a, (*stack_b)->val,(*stack_b)->group);
	*stack_b = temp1->next;
	free(temp1);
	write(1, "pa\n", 3);
}

void	rot_base(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*head;
	t_stack	*new_head;

	if ((*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	new_head = (*stack_a)->next;
	last = lst_last(*stack_a);
	last->next = head;
	head->next = NULL;
	*stack_a = new_head;
}

void	rot_a(t_stack **stack_a)
{
	rot_base(stack_a);
	write(1, "ra\n", 3);
}

void	rr_a(t_stack **stack_a)
{
	rr_base(stack_a);
	write(1, "rra\n", 4);
}
