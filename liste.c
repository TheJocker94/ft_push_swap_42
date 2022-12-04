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

void	display_list(t_stack *start)
{
	t_stack	*i;

	i = start;
	while (i != NULL)
	{
		printf(" %d", i->val);
		i = i->next;
		if (i == NULL)
			printf("\n");
	}
}

void	release(t_stack *start)
{
	t_stack	*i;
	t_stack	*next;

	i = start;
	next = NULL;
	while (i)
	{
		next = i->next;
		free(i);
		i = next;
	}
}

void	reverse_list(t_stack **stnode)
{
	t_stack	*prev;
	t_stack	*curr;

	if (stnode != NULL)
	{
		prev = *stnode;
		curr = (*stnode)->next;
		*stnode = (*stnode)->next;
		prev->next = NULL;
		while (*stnode != NULL)
		{
			*stnode = (*stnode)->next;
			curr->next = prev;
			prev = curr;
			curr = *stnode;
		}
		*stnode = prev;
	}
}

int	lst_size(t_stack *start)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = start;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	medium_val(t_stack *list)
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
