/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:21:49 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/13 15:13:53 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap_bonus.h"

t_operation	*ft_new_op(char	*str)
{
	t_operation	*el;

	el = malloc(sizeof(t_operation));
	if (!el)
		return (NULL);
	el->op = str;
	el->next = NULL;
	return (el);
}

void	ft_op_back(t_operation **begin, t_operation *el)
{
	t_operation	*current;

	if (begin && *begin)
	{
		current = *begin;
		while (current->next)
			current = current->next;
		current->next = el;
	}
	else if (begin)
		*begin = el;
}

void	ft_op_clear(t_operation **op)
{
	t_operation	*current;
	t_operation	*previous;

	if (!op || *op == NULL)
		return ;
	current = *op;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous->op);
		free(previous);
	}
	*op = NULL;
}
