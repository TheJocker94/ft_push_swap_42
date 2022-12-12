/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:34:40 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/01 21:34:42 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

long	ft_atol(char *str)
{
	int		sign;
	long	nmb;

	sign = 1;
	nmb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nmb *= 10;
		nmb += (*str - '0');
		str++;
	}
	return (nmb *= sign);
}

int	ft_strdigit(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *str)
{
	long	check;

	check = ft_atol(str);
	if (check > 2147483647 || check < -2147483648)
		return (0);
	return (1);
}

int	check_double(int i, int j, int ac, char **av)
{
	while (i < ac)
	{
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (1)
	{
		if (check_double(i, j, ac, av) == 1)
			return (1);
		else if (check_double(i, j, ac, av) == 0)
			break ;
	}
	i = 1;
	while (i < ac)
	{
		if ((av[i][0] != '-' && av[i][0] != '+') && (av[i][0] < '0'
				|| av[i][0] > '9'))
			return (1);
		else if (!ft_strdigit(av[i]))
			return (1);
		else if (!is_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}
