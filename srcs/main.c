/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:33 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 03:50:33 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_get_stack(argc, argv);
	if (!stack_a)
		return (0);
	ft_push_swap(&stack_a);

	t_stack	*current;
	current = stack_a;
	while (current)
	{
		ft_printf("stack_a = %d\n", current->value);
		current = current->down;
	}

	free(stack_a);
	return (0);
}