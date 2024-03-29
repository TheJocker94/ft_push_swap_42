/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:41:16 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:41:18 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	find_inter(t_stack *a)
{
	int	max;
	int	min;
	int	interv;

	max = is_max(a);
	min = is_min(a);
	interv = (max - min) / 5;
	return (interv);
}

void	push_top(t_stack **a, t_stack **b, int pos)
{
	int	i;

	i = 1;
	while (i != pos)
	{
		rot_a(a, 1);
		i++;
	}
	push_b(a, b, 1);
}

void	push_bot(t_stack **a, t_stack **b, int pos, int list_size)
{
	while ((float)pos <= (float)(list_size))
	{
		rr_a(a, 1);
		pos++;
	}
	push_b(a, b, 1);
}

int	is_ordered(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}
