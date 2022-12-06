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

int	main(int ac, char **av)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	size = ac - 1;
	stack_a = NULL;
	stack_b = NULL;
	if (size < 1)
		exit (0);
	if (check_args(ac, av))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	stack_a = create_list(ac, av);
	groupon(&stack_a, size);
	//printf("List size : %d\n", lst_size(stack_a));
	//display_list(stack_a);
	//printf("Min is : %d\n", is_min(stack_a));
	//printf("Max is : %d\n", is_max(stack_a));
	//printf("Min position is :%d\n", find_min_pos(stack_a));
	//if (is_ordered(stack_a));
	//	return (0);
	display_group(stack_a);
	if (size <= 5)
		ft_sort_5(&stack_a, &stack_b, size);
	if (size > 5)
		sort_big(&stack_a, &stack_b, size);
	//int min;
	//printf("Min pos is : %d\n", min = find_min_pos(stack_a));
	//push_ordered(&stack_a, min);
	//display_list(stack_a);
	//display_list(stack_b);
	/*display_list(stack_a);
	display_list(stack_b);
	rot_a(&stack_a);
	rr_a(&stack_a);
	printf("%d\n", medium_val(stack_a));*/
	//push_min(&stack_a, &stack_b);
	//write(1, "A:\n", 3);
	//display_list(stack_a);
	//write(1, "B:\n", 3);
	//display_list(stack_b);
	//printf("Max b is %d\n", j);
	display_group(stack_a);
	release(stack_a);
	release(stack_b);
}
