/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 04:14:47 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/12 11:43:27 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	ft_rotate(t_stack **stack, int which, int msg)
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
	if (msg && which == 1)
		ft_printf("ra\n");
	else if (msg && which == 2)
		ft_printf("rb\n");
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int msg)
{
	ft_rotate(stack_a, 1, 0);
	ft_rotate(stack_b, 2, 0);
	if (msg)
		ft_printf("rr\n");
}
