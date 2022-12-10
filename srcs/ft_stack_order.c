/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 06:28:06 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/10 10:51:51 by bperriol         ###   ########lyon.fr   */
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

void	ft_stack_order(t_stack **stack_a, int which, int max)
{
	int	rotation;

	if (!(*stack_a))
		return ;
	if (ft_get_max(*stack_a, max) <= (int)ft_stack_size(*stack_a) / 2)
		rotation = 0;
	else
		rotation = 1;
	while (ft_get_max(*stack_a, max) != 0)
	{
		if (rotation)
			ft_reverse_rotate(stack_a, which, 1);
		else
			ft_rotate(stack_a, which, 1);
	}
}

int	ft_is_sorted(t_stack *stack, int order)
{
	int		previous_value;
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack->down;
	previous_value = stack->value;
	while (current)
	{
		if (order && current->value < previous_value)
			return (0);
		else if (!order && current->value > previous_value)
			return (0);
		previous_value = current->value;
		current = current->down;
	}
	return (1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_top_value(t_stack *stack)
{
	if (stack)
		return (stack->index_pos);
	else
		return (0);
}
