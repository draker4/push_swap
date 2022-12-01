/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:08:57 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 03:24:04 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

t_stack	*ft_new_el_stack(int value)
{
	t_stack	*el;

	el = malloc(sizeof(t_stack));
	if (!el)
		return (NULL);
	el->value = value;
	el->down = NULL;
	return (el);
}

void	ft_stack_back(t_stack **begin, t_stack *el)
{
	t_stack	*current;

	if (begin && *begin)
	{
		current = *begin;
		while (current->down)
			current = current->down;
		current->down = el;
	}
	else if (begin)
		*begin = el;
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	if (!stack || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		previous = current;
		current = current->down;
		free(previous);
	}
	*stack = NULL;
}
