/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 06:28:06 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/04 20:39:35 by bperriol         ###   ########lyon.fr   */
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
	int		index;
	t_stack	*current;

	if (!stack)
		return (-1);
	current = stack->down;
	previous_value = stack->value;
	index = 0;
	while (current)
	{
		if (order && current->value < previous_value)
			return (index);
		else if (!order && current->value > previous_value)
			return (index);
		previous_value = current->value;
		current = current->down;
		index++;
	}
	return (-1);
}

int	ft_is_rotated(t_stack *stack, int order)
{
	int		previous_value;
	int		i;
	int		prev_i;
	t_stack	*current;
	t_stack	*last;

	if (!stack)
		return (-1);
	current = stack;
	last = ft_get_last_stack(stack);
	previous_value = last->value;
	prev_i = ft_stack_size(stack) - 1;
	i = 0;
	while (current)
	{
		//ft_printf("index = %d et current value = %d\n", i, current->value);
		if (order && current->value < previous_value \
		&& !(prev_i == ft_get_max(stack, 1) && i == ft_get_max(stack, 0)))
		{
			//ft_printf("current=%d\n", current->value);
			return (i);
		}
		else if (!order && current->value > previous_value \
		&& !(prev_i == ft_get_max(stack, 0) && i == ft_get_max(stack, 1)))
			return (i);
		previous_value = current->value;
		current = current->down;
		prev_i = i;
		i++;
	}
	return (-1);
}
