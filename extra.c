/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:05:37 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/14 12:05:41 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	divine(int size)
{
	int	div;

	div = 3;
	while (size - 65 > 0)
	{
		div += 2;
		size -= 65;
	}
	return (div);
}

void	ft_display_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	push_top_last(t_stack **a, t_stack **b, int pos, int max)
{
	int	i;

	i = 1;
	while (i != pos)
	{
		rot_a(a, 1);
		i++;
	}
	if ((*a)->val == max && (*a)->val != is_min(*a))
	{
		push_b(a, b, 1);
		rot_b(b, 1);
	}
	else
		push_b(a, b, 1);
	return ;
}

void	push_bot_last(t_stack **a, t_stack **b, int pos, int max)
{
	int	list_size;

	list_size = lst_size(*a);
	while ((float)pos <= (float)(list_size))
	{
		rr_a(a, 1);
		pos++;
	}
	if ((*a)->val == max && (*a)->val != is_min(*a))
	{
		push_b(a, b, 1);
		rot_b(a, 1);
	}
	else
		push_b(a, b, 1);
	return ;
}

void	push_group_2(t_stack **a, t_stack **b, int min, int max)
{
	int	list_size;
	int	act_top;
	int	act_bot;

	list_size = lst_size(*a);
	act_top = pos_max_min_top(*a, min, max) - 1;
	act_bot = list_size - pos_max_min_bot(*a, min, max) + 1;
	if ((act_top - act_bot == 0 || pos_max_min_bot(*a, min, max) == 0)
		&& pos_max_min_top(*a, min, max) != 0)
		push_top_last(a, b, pos_max_min_top(*a, min, max), max);
	else if ((act_top <= act_bot) && (act_top >= 0))
		push_top_last(a, b, pos_max_min_top(*a, min, max), max);
	else if ((act_top > act_bot) || (pos_max_min_top(*a, min, max) == 0
			&& pos_max_min_bot(*a, min, max) != 0))
		push_bot_last(a, b, pos_max_min_bot(*a, min, max), max);
	return ;
}
