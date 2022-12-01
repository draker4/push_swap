/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:16 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 06:53:34 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	ft_is_sorted(t_stack *stack)
{
	int		previous_value;
	t_stack	*current;

	current = stack->down;
	previous_value = stack->value;
	while (current)
	{
		if (current->value < previous_value)
			return (0);
		previous_value = current->value;
		current = current->down;
	}
	return (1);
}

static int	ft_stack_two_el(t_stack **stack_a)
{
	ft_swap_a(stack_a, 1);
	return (1);
}

static int	ft_stack_three_el(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->down->value \
		&& (*stack_a)->value < (*stack_a)->down->down->value)
		ft_swap_a(stack_a, 1);
	else if ((*stack_a)->value > (*stack_a)->down->value \
		&& (*stack_a)->down->value > (*stack_a)->down->down->value)
	{
		ft_swap_a(stack_a, 1);
		ft_reverse_rotate_a(stack_a, 1);
	}
	else if ((*stack_a)->value > (*stack_a)->down->down->value \
		&& (*stack_a)->down->down->value > (*stack_a)->down->value)
		ft_rotate_a(stack_a, 1);
	else if ((*stack_a)->value < (*stack_a)->down->down->value \
		&& (*stack_a)->down->value > (*stack_a)->down->down->value)
	{
		ft_swap_a(stack_a, 1);
		ft_rotate_a(stack_a, 1);
	}
	else
		ft_reverse_rotate_a(stack_a, 1);
	return (1);
}

static int	ft_stack_five_el(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	size = ft_stack_size(*stack_a);
	stack_b = NULL;
	ft_push_b(stack_a, &stack_b);
	if (size == 5)
		ft_push_b(stack_a, &stack_b);
	ft_stack_three_el(stack_a);
	while (size >= 4)
	{
		while (!((*stack_a)->value > stack_b->value \
			&& ft_stack_last(*stack_a)->value < stack_b->value) \
			&& ft_get_max(*stack_a, 1) > stack_b->value
			&& ft_get_max(*stack_a, 0) < stack_b->value)
			ft_rotate_a(stack_a, 1);
		ft_push_a(stack_a, &stack_b);
		size--;
	}
	ft_stack_order(stack_a);
	return (1);
}

int	ft_push_swap(t_stack **stack_a)
{
	int		size;

	if (ft_is_sorted(*stack_a))
		return (1);
	size = (int)ft_stack_size(*stack_a);
	if (size == 2)
		return (ft_stack_two_el(stack_a));
	else if (size == 3)
		return (ft_stack_three_el(stack_a));
	else if (size <= 5)
		return (ft_stack_five_el(stack_a));
	return (1);
}
