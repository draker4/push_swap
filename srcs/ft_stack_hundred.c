/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:16:59 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 10:06:42 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	ft_fill_a(t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_stack_size(*stack_b);
	while (i < len)
	{
		ft_push_a(stack_a, stack_b);
		i++;
	}
	return (1);
}

int	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_order(stack_a);
	if (ft_is_sorted(*stack_a, 1) && *stack_b == NULL)
		return (1);
	else if (ft_is_sorted(*stack_b, 0) && *stack_a == NULL)
		return (ft_fill_a(stack_a, stack_b));
	ft_push_b(stack_a, stack_b);
	ft_stack_hundred(stack_a, stack_b);
	return (1);
}
