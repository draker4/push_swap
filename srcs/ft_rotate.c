/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 04:14:47 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 06:53:56 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	ft_rotate_a(t_stack **stack, int msg)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !(*stack) || (int)ft_stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->down;
	current = *stack;
	while (current->down)
		current = current->down;
	current->down = tmp;
	tmp->down = NULL;
	if (msg)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack, int msg)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !(*stack) || (int)ft_stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->down;
	current = *stack;
	while (current->down)
		current = current->down;
	current->down = tmp;
	tmp->down = NULL;
	if (msg)
		ft_printf("rb\n");
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a, 0);
	ft_rotate_b(stack_b, 0);
	ft_printf("rr\n");
}
