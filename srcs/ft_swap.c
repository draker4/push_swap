/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:27 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 04:46:01 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	ft_swap_a(t_stack **stack, int msg)
{
	int		tmp;

	if ((int)ft_stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->down->value;
	(*stack)->down->value = tmp;
	if (msg)
		ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack, int msg)
{
	int		tmp;

	if ((int)ft_stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->down->value;
	(*stack)->down->value = tmp;
	if (msg)
		ft_printf("sb\n");
}

void	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a, 0);
	ft_swap_b(stack_b, 0);
	ft_printf("ss\n");
}
