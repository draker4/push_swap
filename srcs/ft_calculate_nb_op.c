/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_nb_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:18:42 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/15 10:34:23 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	ft_return_index(t_stack *stack_a, int value, \
t_stack *current, int index)
{
	int	len;

	len = index + 1;
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

static int	ft_find_index(t_stack *stack_a, int value, int len_a)
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
		if (index == len_a - 1)
			return (ft_return_index(stack_a, value, current, index));
		if (current->down && current->value < value && \
		current->down->value > value)
		{
			if (index <= len_a / 2)
				return (index + 1);
			else
				return (-(len_a - index - 1));
		}
		index++;
		current = current->down;
	}
	return (len_a);
}

static int	ft_total_op(int op_a, int op_b)
{
	if (op_a * op_b > 0)
	{
		if (op_a > 0)
		{
			if (op_a > op_b)
				return (ft_abs(op_a));
			else
				return (ft_abs(op_b));
		}
		else
		{
			if (op_a < op_b)
				return (ft_abs(op_a));
			else
				return (ft_abs(op_b));
		}
	}
	else
		return (ft_abs(op_a) + ft_abs(op_b));
}

void	ft_calculate_op(t_stack *stack_a, t_stack *stack_b, int *min, int len_b)
{
	t_stack			*current;
	int				index;
	static int		len_a;

	current = stack_b;
	index = 0;
	*min = len_b + len_a;
	while (current)
	{
		if (index <= len_b / 2)
			current->nb_op_b = index;
		else
			current->nb_op_b = -(len_b - index);
		if (ft_abs(current->nb_op_b) > *min)
			current->nb_op_a = len_b + len_a;
		else
			current->nb_op_a = ft_find_index(stack_a, current->value, len_a);
		current->nb_op = ft_total_op(current->nb_op_a, current->nb_op_b);
		if (current->nb_op < *min)
			*min = current->nb_op;
		index++;
		current = current->down;
	}
	len_a++;
}
