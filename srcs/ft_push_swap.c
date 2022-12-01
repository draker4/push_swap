/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:06:04 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 03:22:00 by bperriol         ###   ########lyon.fr   */
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

void	ft_push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!ft_is_sorted(stack_a))
		ft_printf("not sorted\n");
}
