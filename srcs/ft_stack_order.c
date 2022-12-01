/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 06:28:06 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 06:59:54 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	ft_get_max(t_stack *stack, int max)
{
	int	index;
	int	value;
	int	i;

	index = 0;
	i = 0;
	value = stack->value;
	while (stack)
	{
		if ((max && stack->value > value) || (!max && stack->value < value))
		{
			value = stack->value;
			index = i;
		}
		i++;
		stack = stack->down;
	}
	return (index);
}

void	ft_stack_order(t_stack **stack_a)
{
	int	rotation;

	if (ft_get_max(*stack_a, 0) < (int)ft_stack_size(*stack_a) / 2)
		rotation = 0;
	else
		rotation = 1;
	while (ft_get_max(*stack_a, 0) != 0)
	{
		if (rotation)
			ft_reverse_rotate_a(stack_a, 1);
		else
			ft_rotate_a(stack_a, 1);
	}
}


