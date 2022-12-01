/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:14:35 by ocastell          #+#    #+#             */
/*   Updated: 2022/12/01 21:14:38 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft.h"

typedef struct d_list
{
	int				val;
	struct d_list	*next;
}					d_list;

void	display_list(d_list *start);
d_list	*create_node(int val);
void	release(d_list *start);
void	reverse_list(d_list **stnode);
void	addtop(d_list **start, int new);
void	addbot(d_list **start, int new);
int	lst_size(d_list *start);
d_list	*create_list(int ac, char **av);
void	sw_a(d_list **start);
void	push_b(d_list **stack_a, d_list **stack_b);
d_list *lst_last(d_list *start);
void	rot_a(d_list **stack_a);
void	rr_a(d_list **stack_a);
int medium_val(d_list *list);
long	ft_atol(char *str);
int	ft_strdigit(char *str);
int	is_int(char *str);
int	check_args(int ac, char **av);
void	ft_sort_2(d_list **a);
void	ft_sort_3(d_list **a);
void first_sort_3_if(d_list *beholder, d_list *beholder2, d_list *beholder3, d_list **a);



#endif