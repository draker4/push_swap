/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:21 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 19:34:08 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, int msg)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->down;
	tmp->down = *stack_a;
	*stack_a = tmp;
	if (msg)
		ft_printf("pa\n");
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b, int msg)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->down;
	tmp->down = *stack_b;
	*stack_b = tmp;
	if (msg)
		ft_printf("pb\n");
}
