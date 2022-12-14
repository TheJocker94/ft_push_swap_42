#include "lib/push_swap.h"

void	ft_display_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	exec_check(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rr_a(a, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rr_b(b, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		ft_display_exit();
}

void	ft_exec_sort(t_stack **a, t_stack **b, char *str)
{
	while (str != NULL)
	{
		if (ft_strncmp(str, "sa\n", 3) == 0)
			sw_a(a, 0);
		else if (ft_strncmp(str, "sb\n", 3) == 0)
			sw_b(b, 0);
		else if (ft_strncmp(str, "ss\n", 3) == 0)
			ss(a, b, 0);
		else if (ft_strncmp(str, "pa\n", 3) == 0)
			push_a(a, b, 0);
		else if (ft_strncmp(str, "pb\n", 3) == 0)
			push_b(a, b, 0);
		else if (ft_strncmp(str, "ra\n", 3) == 0)
			rot_a(a, 0);
		else if (ft_strncmp(str, "rb\n", 3) == 0)
			rot_b(b, 0);
		else
			exec_check(a, b, str);
		str = get_next_line(0);
	}
}

void	ft_check_sort(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->val > (stack_a->next)->val)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else
	{
		if (check_args(ac, av))
			ft_display_exit();
	}
	stack_a = create_list(ac, av);
	str = get_next_line(0);
	ft_exec_sort(&stack_a, &stack_b, str);
	ft_check_sort(stack_a);
	free(str);
	release(stack_a);
	release(stack_b);
	return (0);
}
