/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:14:04 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/09 13:15:42 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static void	ft_initialize_seq(t_stack **stack_a, int max_seq)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->seq != max_seq)
	{
		current->seq = 0;
		current = current->down;
	}
	while (max_seq--)
	{
		current->seq = 1;
		current = current->down;
	}
	while (current)
	{
		current->seq = 0;
		current = current->down;
	}
}

void	ft_find_sequence(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		seq;
	int		max_seq;

	max_seq = 0;
	current = *stack_a;
	while (current)
	{
		seq = 1;
		tmp = current;
		while (tmp->down && tmp->value < tmp->down->value)
		{
			seq++;
			tmp = tmp->down;
		}
		if (max_seq < seq)
			max_seq = seq;
		current->seq = seq;
		current = current->down;
	}
	ft_initialize_seq(stack_a, max_seq);
}
