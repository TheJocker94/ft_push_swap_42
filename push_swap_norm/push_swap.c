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
	int		div;

	size = ac - 1;
	div = 15;
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
	init_min(stack_a);
	groupon(&stack_a, size, div);
	if (size <= 5)
		ft_sort_5(&stack_a, &stack_b, size);
	if (size > 5)
		sort_big(&stack_a, &stack_b, size, div);
	release(stack_a);
	release(stack_b);
}
