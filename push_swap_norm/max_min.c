/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:41:36 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:41:39 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	pos_max_min_top(t_stack *a, int min, int max)
{
	int	i;
	int	size;

	size = lst_size(a);
	i = 1;
	while (a && i <= (size / 2 + 1))
	{
		if (((a->val == max) || (a->val == min)))
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	pos_max_min_bot(t_stack *a, int min, int max)
{
	int	i;
	int	size;
	int	pos;

	size = lst_size(a);
	pos = 0;
	i = 0;
	while (a)
	{
		if (((a->val == max) || (a->val == min)) && i >= size / 2)
			pos = i + 1;
		i++;
		a = a->next;
	}
	return (pos);
}

int	push_top_back(t_stack **a, t_stack **b, int pos, int min)
{
	int	i;

	i = 1;
	while (i != pos)
	{
		rot_b(b);
		i++;
	}
	if ((*b)->val == min)
	{
		i = 1;
		push_a(a, b);
		rot_a(a);
	}
	else
	{
		i = 0;
		push_a(a, b);
	}
	return (i);
}

int	push_bot_back(t_stack **a, t_stack **b, int pos, int min)
{
	int	i;
	int	list_size;

	list_size = lst_size(*b);
	while ((float)pos <= (float)(list_size))
	{
		rr_b(b);
		pos++;
	}
	if ((*b)->val == min)
	{
		i = 1;
		push_a(a, b);
		rot_a(a);
	}
	else
	{
		i = 0;
		push_a(a, b);
	}
	return (i);
}

int	push_group_back(t_stack **a, t_stack **b, int min, int max)
{
	int	list_size;
	int	act_top;
	int	act_bot;
	int	i;

	i = 0;
	list_size = lst_size(*b);
	act_top = pos_max_min_top(*b, min, max) - 1;
	act_bot = list_size - pos_max_min_bot(*b, min, max) + 1;
	if ((act_top - act_bot == 0 || pos_max_min_bot(*b, min, max) == 0)
		&& pos_max_min_top(*b, min, max) != 0)
		i = push_top_back(a, b, pos_max_min_top(*b, min, max), min);
	else if ((act_top <= act_bot) && (act_top >= 0))
		i = push_top_back(a, b, pos_max_min_top(*b, min, max), min);
	else if ((act_top > act_bot) || (pos_max_min_top(*b, min, max) == 0
			&& pos_max_min_bot(*b, min, max) != 0))
		i = push_bot_back(a, b, pos_max_min_bot(*b, min, max), min);
	return (i);
}
