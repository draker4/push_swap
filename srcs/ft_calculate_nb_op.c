/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_nb_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:18:42 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/09 17:12:37 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	ft_return_index(t_stack *stack_a, int value, \
t_stack *current, int index)
{
	int	len;

	len = (int)ft_stack_size(stack_a);
	if (current->value < value)
	{
		index = ft_get_max(stack_a, 1);
		if (index <= len / 2)
			return (index + 1);
		else
			return (-(len - index - 1));
	}
	else
	{
		index = ft_get_max(stack_a, 0);
		if (index <= len / 2)
			return (index);
		else
			return (-(len - index));
	}
}

static int	ft_find_index(t_stack *stack_a, int value)
{
	t_stack	*current;
	int		index;

	current = stack_a;
	index = 0;
	while (current)
	{
		if (!index && current->value > value && \
		(ft_stack_last(stack_a)->value < value))
			return (0);
		if (index == (int)ft_stack_size(stack_a) - 1)
			return (ft_return_index(stack_a, value, current, index));
		if (current->down && current->value < value && \
		current->down->value > value)
		{
			if (index <= (int)ft_stack_size(stack_a) / 2)
				return (index + 1);
			else
				return (-((int)ft_stack_size(stack_a) - index - 1));
		}
		index++;
		current = current->down;
	}
	return ((int)ft_stack_size(stack_a));
}

void	ft_calculate_op(t_stack *stack_a, t_stack **stack_b, int *min)
{
	t_stack	*current;
	int		index;
	int		index_b;
	int		len;

	current = *stack_b;
	index = 0;
	len = (int)ft_stack_size(*stack_b);
	*min = len + (int)ft_stack_size(stack_a);
	while (current)
	{
		if (index <= len / 2)
			index_b = index;
		else
			index_b = -(len - index);
		current->nb_op_a = ft_find_index(stack_a, current->value);
		current->nb_op_b = index_b;
		if (ft_abs(current->nb_op_a) + ft_abs(current->nb_op_b) < *min)
			*min = ft_abs(current->nb_op_a) + ft_abs(current->nb_op_b);
		index++;
		current = current->down;
	}
}
