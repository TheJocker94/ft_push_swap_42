/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:42:02 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:42:04 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	is_group(t_stack *a, int id)
{
	t_stack	*node;
	int		i;

	node = a;
	i = 0;
	while (node)
	{
		if (node->group == id)
		{
			i = 1;
			break ;
		}
		node = node->next;
	}
	return (i);
}

int	pos_group_top(t_stack *a, int id)
{
	int	i;
	int	size;

	size = lst_size(a);
	i = 1;
	while (a && i <= (size / 2 + 1))
	{
		if (((a->group == id) || (a->group == (id + 1))))
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	pos_group_bot(t_stack *a, int id)
{
	int	i;
	int	size;
	int	pos;

	size = lst_size(a);
	pos = 0;
	i = 0;
	while (a)
	{
		if (((a->group == id) || (a->group == (id + 1))) && i >= size / 2)
			pos = i + 1;
		i++;
		a = a->next;
	}
	return (pos);
}

void	push_group(t_stack **a, t_stack **b, int id)
{
	int	list_size;
	int	act_top;
	int	act_bot;

	list_size = lst_size(*a);
	act_top = pos_group_top(*a, id) - 1;
	act_bot = list_size - pos_group_bot(*a, id) + 1;
	if ((pos_group_top(*a, id) - pos_group_bot(*a, id) == 0 || pos_group_bot(*a,
				id) == 0) && pos_group_top(*a, id) != 0)
		push_top(a, b, pos_group_top(*a, id));
	else if ((act_top <= act_bot) && (act_top >= 0))
		push_top(a, b, pos_group_top(*a, id));
	else if ((act_top > act_bot) || (pos_group_top(*a, id) == 0
			&& pos_group_bot(*a, id) != 0))
		push_bot(a, b, pos_group_bot(*a, id), list_size);
	if (((*b)->next != NULL) && ((*b)->group < (lst_last(*b))->group))
		return ;
	else
	{
		if (is_next_top(a, id))
			rr(a, b, 1);
		else
			rot_b(b, 1);
	}
}

int	is_next_top(t_stack **a, int id)
{
	int	pos_top;
	int	pos_bot;
	int	list_size;
	int	act_top;
	int	act_bot;

	pos_top = pos_group_top(*a, id);
	pos_bot = pos_group_bot(*a, id);
	if (pos_top == 1)
		return (0);
	list_size = lst_size(*a);
	act_top = pos_top - 1;
	act_bot = list_size - pos_bot + 1;
	if ((pos_top - pos_bot == 0 || pos_bot == 0) && pos_top != 0)
		return (1);
	else if ((act_top <= act_bot) && (act_top >= 0))
		return (1);
	else if ((act_top > act_bot) || (pos_top == 0 && pos_bot != 0))
		return (0);
	return (0);
}
