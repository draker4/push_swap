/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:16:59 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/10 18:30:49 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

// static void	ft_push_min_op(t_stack **stack_a, t_stack **stack_b, int min)
// {
// 	t_stack	*current;

// 	current = *stack_b;
// 	while (current)
// 	{
// 		if (ft_abs(current->nb_op_a) + ft_abs(current->nb_op_b) == min)
// 		{
// 			ft_choose_rotation_min_op(stack_a, stack_b, current);
// 			ft_push_a(stack_a, stack_b);
// 			return ;
// 		}
// 		current = current->down;
// 	}
// }

// void	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	min;

// 	ft_find_sequence(stack_a);
// 	ft_push_others(stack_a, stack_b);
// 	while (*stack_b)
// 	{
// 		ft_calculate_op(*stack_a, *stack_b, &min);
// 		ft_push_min_op(stack_a, stack_b, min);
// 	}
// 	ft_stack_order(stack_a, 1, 0);
// }

static void	ft_push_chunk2(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		top_value;
	int		chunk_min;
	int		len_a;

	chunk_min = -100;
	while (*stack_a)
	{
		i = 0;
		chunk_min += 100;
		len_a = (int)ft_stack_size(*stack_a);
		// ft_printf("chunk=%d et len = %d\n", chunk_min, len_a);
		// ft_print_stack(*stack_a, 1);
		// ft_print_stack(*stack_b, 2);
		while (i < len_a)
		{
			top_value = (*stack_a)->index_pos;
			if (top_value >= chunk_min && top_value < chunk_min + 100)
				ft_push_b(stack_a, stack_b);
			else
				ft_rotate(stack_a, 1, 1);
			i++;
		}
	}
}

void	ft_stack_hundred2(t_stack **stack_a, t_stack **stack_b)
{
	int	len_b;

	if (!ft_index_pos(stack_a))
		return ;
	// ft_print_stack(*stack_a, 1);
	// ft_print_stack(*stack_b, 2);
	ft_push_chunk2(stack_a, stack_b);
	// ft_printf("apres push\n");
	// ft_print_stack(*stack_a, 1);
	// ft_print_stack(*stack_b, 2);
	len_b = ft_stack_size(*stack_b);
	while (*stack_b)
	{
		ft_push_back_order(stack_a, stack_b, len_b);
		len_b--;
	}
	ft_stack_order(stack_a, 1, 0);
}
