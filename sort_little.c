/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:55:05 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/01 21:55:07 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	ft_sort_2(d_list **a)
{
	d_list	*beholder;
	d_list	*beholder2;

	beholder = *a;
	beholder2 = beholder->next;
	if (beholder->val > beholder2->val)
		sw_a(a);
}

void	first_sort_3_if(d_list *tmp, d_list *tmp2, d_list *tmp3, d_list **a)
{
	if (tmp2->val < tmp3->val)
		return ;
	else if (tmp3->val < tmp->val)
		rr_a(a);
	else
	{
		rr_a(a);
		sw_a(a);
	}
}

void	ft_sort_3(d_list **a)
{
	d_list	*tmp;
	d_list	*tmp2;
	d_list	*tmp3;

	tmp = *a;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp->val < tmp2->val)
		first_sort_3_if(tmp, tmp2, tmp3, a);
	else if (tmp2->val < tmp3->val)
	{
		if (tmp3->val < tmp->val)
			rot_a(a);
		else
			sw_a(a);
	}
	else
	{
		sw_a(a);
		rr_a(a);
	}
}

int	check_order_little(d_list **list, int size)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	if (size < 4)
		return (0);
	a = (*list)->val;
	b = (*list)->next->val;
	c = (*list)->next->next->val;
	d = (*list)->next->next->next->val;
	if (size == 5)
		e = (*list)->next->next->next->next->val;
	if (((a < b) && (b < c) && (c < d)) && size == 4)
		return (1);
	else if (((a < b) && (b < c) && (c < d) && (d < e)) && size == 5)
		return (1);
	return (0);
}

void	ft_sort_5(d_list **a, d_list **b, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		ft_sort_2(a);
	if (size == 3)
		ft_sort_3(a);
	if ((check_order_little(a, size)) && size >= 4)
		return ;
	if (size == 4)
	{
		push_min(a, b);
		ft_sort_3(a);
		push_a(a, b);
	}
	if (size == 5)
	{
		push_min(a, b);
		push_min(a, b);
		ft_sort_3(a);
		push_a(a, b);
		push_a(a, b);
	}
}
