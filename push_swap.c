/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:54:20 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/01 20:54:23 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"
#include <string.h>

int	main(int ac, char **av)
{
	int size;
	d_list	*stack_a;
	d_list	*stack_b;
	//int min;
	//int max;
	int	id = 1;
	//int	i = 0;
	size = ac - 1;
	stack_a = NULL;
	stack_b = NULL;
	if (size < 1)
		return (0);
	if (check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = create_list(ac, av);
	printf("List size : %d\n", lst_size(stack_a));
	display_list(stack_a);
	//printf("Min is : %d\n", is_min(stack_a));
	//printf("Max is : %d\n", is_max(stack_a));
	//printf("Min position is :%d\n", find_min_pos(stack_a));
	//if (size <= 5)
	//	ft_sort_5(&stack_a, &stack_b, size);
	//while (size > 5 && size <= 9)
	//{
		/*if (size == 6)
		{
			push_min(&stack_a, &stack_b);
			push_min(&stack_a, &stack_b);
			push_min(&stack_a, &stack_b);
			ft_sort_3(&stack_a);
			push_a(&stack_a, &stack_b);
			push_a(&stack_a, &stack_b);
			push_a(&stack_a, &stack_b);
			break;
		}*/
		/*while ((size - i) > 5)
		{
			push_min(&stack_a, &stack_b);
			i++;
		}
		ft_sort_5(&stack_a, &stack_b, (size - i));
		while (i--)
		{
			push_a(&stack_a, &stack_b);
		}
		
		5break;	}*/
	float max = is_max(stack_a);
	float min = is_min(stack_a);
	float inter = (max - min)/5;
	float i = 0;

	while (size > 5 && size <= 100)
	{

		while(is_group(stack_a, min, min + inter, id))
			push_group(&stack_a, &stack_b, id);
		id++;
		min += inter + 1;
		i++;
		if (i == 5)
			break;
	}

	
	/*push_b(stack_a, stack_b);
	display_list(stack_a);
	display_list(stack_b);
	rot_a(&stack_a);
	rr_a(&stack_a);
	printf("%d\n", medium_val(stack_a));*/
	//push_min(&stack_a, &stack_b);
	display_list(stack_a);
	display_list(stack_b);
	//release(stack_a);
	//release(stack_b);
}
