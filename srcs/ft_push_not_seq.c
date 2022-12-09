/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_not_seq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:17:07 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/09 13:17:30 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	ft_is_not_only_seq(t_stack *stack_a)
{
	t_stack	*current;
	int		index;

	current = stack_a;
	index = 0;
	while (current)
	{
		if (!current->seq)
		{
			if (index <= (int)ft_stack_size(stack_a) / 2)
				return (1);
			else
				return (-1);
		}
		index++;
		current = current->down;
	}
	return (0);
}

void	ft_push_others(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && !(*stack_a)->seq)
	{
		ft_push_b(stack_a, stack_b);
		ft_push_others(stack_a, stack_b);
	}
	else if (*stack_a && ft_is_not_only_seq(*stack_a))
	{
		if (ft_is_not_only_seq(*stack_a) == 1)
			ft_rotate(stack_a, 1, 1);
		else
			ft_reverse_rotate(stack_a, 1, 1);
		ft_push_others(stack_a, stack_b);
	}
}
