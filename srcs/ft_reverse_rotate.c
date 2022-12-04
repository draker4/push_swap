/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 04:26:18 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/04 18:17:49 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	ft_reverse_rotate(t_stack **stack, int which, int msg)
{
	t_stack	*tmp;
	t_stack	*current;
	t_stack	*last;

	if (!stack || !(*stack) || (int)ft_stack_size(*stack) < 2)
		return ;
	current = *stack;
	while (current->down->down)
		current = current->down;
	last = current;
	tmp = current->down;
	tmp->down = *stack;
	*stack = tmp;
	last->down = NULL;
	if (msg && which == 1)
		ft_printf("rra\n");
	else if (msg && which == 2)
		ft_printf("rrb\n");
}

void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, 1, 0);
	ft_reverse_rotate(stack_b, 2, 0);
	ft_printf("rrr\n");
}
