/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:40:47 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:40:49 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	sw_b(t_stack **start)
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
	write(1, "sb\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp1;

	temp1 = *stack_a;
	addtop(stack_b, (*stack_a)->val, (*stack_a)->group);
	*stack_a = temp1->next;
	free(temp1);
	write(1, "pb\n", 3);
}

void	rot_b(t_stack **stack_a)
{
	rot_base(stack_a);
	write(1, "rb\n", 3);
}

void	rr_b(t_stack **stack_a)
{
	rr_base(stack_a);
	write(1, "rrb\n", 4);
}
