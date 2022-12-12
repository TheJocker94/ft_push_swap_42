/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:40:31 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:40:34 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	rot_a(a);
	rot_b(b);
	write(1, "rr\n", 3);
}

void	rr_base(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*head;
	t_stack	*new_last;

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

void	rrr(t_stack **a, t_stack **b)
{
	rr_a(a);
	rr_b(b);
	write(1, "rrr\n", 4);
}
