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
	int		i;
	d_list	*stack_a;
	d_list	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = create_list(ac, av);
	i = lst_size(stack_a);
	printf("List size : %d\n", i);
	display_list(stack_a);
	/*stack_a = push_b(stack_a, stack_b);
	display_list(stack_a);
	display_list(stack_b);*/
	//rot_a(&stack_a);
	//rr_a(&stack_a);
	printf("%d\n", medium_val(stack_a));
	//display_list(stack_a);
	//display_list(stack_b);

	release(stack_a);
	release(stack_b);
}