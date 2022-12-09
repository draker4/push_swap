/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:16:59 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/09 13:27:33 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static void	ft_push_min_op(t_stack **stack_a, t_stack **stack_b, int min)
{
	t_stack	*current;

	current = *stack_b;
	while (current)
	{
		if (ft_abs(current->nb_op_a) + ft_abs(current->nb_op_b) == min)
		{
			ft_rotation_both_min_op(stack_a, stack_b, current);
			ft_push_a(stack_a, stack_b);
			return ;
		}
		current = current->down;
	}
}

int	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	ft_find_sequence(stack_a);
	ft_push_others(stack_a, stack_b);
	while (*stack_b)
	{
		ft_calculate_op(*stack_a, stack_b, &min);
		ft_push_min_op(stack_a, stack_b, min);
	}
	ft_stack_order(stack_a, 1, 0);
	return (1);
}
