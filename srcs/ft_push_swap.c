/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:16 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/04 18:23:31 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static void	ft_stack_three_el(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->down->value \
		&& (*stack_a)->value < (*stack_a)->down->down->value)
		ft_swap(stack_a, 1, 1);
	else if ((*stack_a)->value > (*stack_a)->down->value \
		&& (*stack_a)->down->value > (*stack_a)->down->down->value)
	{
		ft_swap(stack_a, 1, 1);
		ft_reverse_rotate(stack_a, 1, 1);
	}
	else if ((*stack_a)->value > (*stack_a)->down->down->value \
		&& (*stack_a)->down->down->value > (*stack_a)->down->value)
		ft_rotate(stack_a, 1, 1);
	else if ((*stack_a)->value < (*stack_a)->down->down->value \
		&& (*stack_a)->down->value > (*stack_a)->down->down->value)
	{
		ft_swap(stack_a, 1, 1);
		ft_rotate(stack_a, 1, 1);
	}
	else if ((*stack_a)->value < (*stack_a)->down->value \
		&& (*stack_a)->value > (*stack_a)->down->down->value)
		ft_reverse_rotate(stack_a, 1, 1);
}

static void	ft_stack_four_el(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_order(stack_a, 1, 0);
	if (ft_is_sorted(*stack_a, 1) == -1)
		return ;
	ft_push_b(stack_a, stack_b);
	ft_stack_three_el(stack_a);
	ft_push_a(stack_a, stack_b);
}

static void	ft_stack_five_el(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_order(stack_a, 1, 0);
	if (ft_is_sorted(*stack_a, 1) == -1)
		return ;
	ft_push_b(stack_a, stack_b);
	ft_stack_order(stack_a, 1, 0);
	ft_push_b(stack_a, stack_b);
	ft_stack_three_el(stack_a);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}

int	ft_push_swap(t_stack **stack_a)
{
	int		size;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_is_sorted(*stack_a, 1) == -1)
		return (1);
	size = (int)ft_stack_size(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->down->value)
			ft_swap(stack_a, 1, 1);
	}
	else if (size == 3)
		ft_stack_three_el(stack_a);
	else if (size == 4)
		ft_stack_four_el(stack_a, &stack_b);
	else if (size == 5)
		ft_stack_five_el(stack_a, &stack_b);
	else
		return (ft_stack_hundred(stack_a, &stack_b));
	return (1);
}
