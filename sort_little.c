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
void first_sort_3_if(d_list *beholder, d_list *beholder2, d_list *beholder3, d_list **a)
{
		if (beholder2->val < beholder3->val)
			return ;
		else if (beholder3->val < beholder->val)
			rr_a(a);
		else
		{
			rr_a(a);
			sw_a(a);
		}
}
void	ft_sort_3(d_list **a)
{
	d_list	*beholder;
	d_list	*beholder2;
	d_list	*beholder3;
	
	beholder = *a;
	beholder2 = beholder->next;
	beholder3 = beholder2->next;
	if (beholder->val < beholder2->val)
		first_sort_3_if(beholder, beholder2, beholder3, a);
	else if (beholder2->val < beholder3->val)
	{
		if (beholder3->val < beholder->val)
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

