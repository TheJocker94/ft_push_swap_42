/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:39:36 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:39:40 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	sort_logic(t_stack ***stack_a, t_stack ***stack_b, int div)
{
	int	id;
	int	min;

	id = 1;
	while (**stack_a)
	{
		while ((is_group(**stack_a, id) || is_group(**stack_a, id + 1)))
			push_group(*stack_a, *stack_b, id);
		id += 2;
		if ((!is_group(**stack_a, (div - 1))))
			break ;
	}
	while (**stack_a)
	{
		min = find_min_pos(**stack_a);
		push_max(*stack_a, *stack_b, min);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int div)
{
	int		min;
	int		max;
	int		i;

	i = 0;
	if (is_ordered(*stack_a))
		return ;
	sort_logic(&stack_a, &stack_b, div);
	while (*stack_b)
	{
		min = is_min_group(*stack_b, div);
		max = is_max(*stack_b);
		i += push_group_back(stack_a, stack_b, min, max);
		if (!is_group(*stack_b, div))
		{
			while (i--)
				rr_a(stack_a, 1);
			div--;
			i = 0;
		}
	}
}
