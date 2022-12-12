/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouponize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:41:50 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/12 15:41:52 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	init_min(t_stack *a)
{
	t_stack	*node;
	t_stack	*temp;

	node = a;
	temp = node->next;
	while (temp)
	{
		while ((temp) && (node->val < temp->val))
			temp = temp->next;
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	node->order = 1;
	node->group = 1;
	return ;
}

void	is_newmin(t_stack *a, int order, int group)
{
	t_stack	*node;
	t_stack	*temp;

	node = a;
	temp = node->next;
	while (temp)
	{
		while ((temp) && ((node->val < temp->val) || (temp->order != 0)))
		{
			if (node->order > 0)
				break ;
			temp = temp->next;
		}
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	if (node->group == 0)
		node->group = group;
	node->order = order;
	return ;
}

void	group_logic(t_stack **a, int div, int g_size, int j)
{
	int	i;
	int	order;
	int	group;

	group = 1;
	order = 2;
	i = 1;
	while (group <= div)
	{
		while (i < g_size)
		{
			is_newmin(*a, order, group);
			i++;
			order++;
		}
		j--;
		group ++;
		i = 0;
		if (j == 0)
			g_size--;
	}
}

void	groupon(t_stack **a, int size, int div)
{
	int		g_size;
	int		j;

	g_size = size / div;
	j = size % div;
	if (j > 0)
		g_size++;
	group_logic(a, div, g_size, j);
}
