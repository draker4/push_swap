/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_both_min_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:27:51 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/10 19:25:01 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static void	ft_reverse_one_min_op(t_stack **stack_a, \
t_stack **stack_b, t_stack *current)
{
	if (current->nb_op_a <= 0 && current->nb_op_b >= 0)
	{
		while (current->nb_op_a++)
			ft_reverse_rotate(stack_a, 1, 1);
		while (current->nb_op_b--)
			ft_rotate(stack_b, 2, 1);
	}
	else if (current->nb_op_a >= 0 && current->nb_op_b <= 0)
	{
		while (current->nb_op_a--)
			ft_rotate(stack_a, 1, 1);
		while (current->nb_op_b++)
			ft_reverse_rotate(stack_b, 2, 1);
	}
}

static void	ft_reverse_rotation_both_min_op(t_stack **stack_a, \
t_stack **stack_b, t_stack *current)
{
	if (current->nb_op_a >= current->nb_op_b)
	{
		while (current->nb_op_a++)
		{
			ft_reverse_rotate_both(stack_a, stack_b);
			current->nb_op_b++;
		}
		while (current->nb_op_b++)
			ft_reverse_rotate(stack_b, 2, 1);
	}
	else
	{
		while (current->nb_op_b++)
		{
			ft_reverse_rotate_both(stack_a, stack_b);
			current->nb_op_a++;
		}
		while (current->nb_op_a++)
			ft_reverse_rotate(stack_a, 1, 1);
	}
}

static void	ft_rotation_both_min_op(t_stack **stack_a, t_stack **stack_b, \
t_stack *current)
{
	if (current->nb_op_a >= current->nb_op_b)
	{
		while (current->nb_op_b--)
		{
			ft_rotate_both(stack_a, stack_b);
			current->nb_op_a--;
		}
		while (current->nb_op_a--)
			ft_rotate(stack_a, 1, 1);
	}
	else
	{
		while (current->nb_op_a--)
		{
			ft_rotate_both(stack_a, stack_b);
			current->nb_op_b--;
		}
		while (current->nb_op_b--)
			ft_rotate(stack_b, 2, 1);
	}
}

void	ft_choose_rotation_min_op(t_stack **stack_a, t_stack **stack_b, \
t_stack *current)
{
	if (current->nb_op_a * current->nb_op_b <= 0)
		ft_reverse_one_min_op(stack_a, stack_b, current);
	else if (current->nb_op_a > 0)
		ft_rotation_both_min_op(stack_a, stack_b, current);
	else
		ft_reverse_rotation_both_min_op(stack_a, stack_b, current);
}
