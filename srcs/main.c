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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (*split)
	{
		while (split[i])
			free(split[i++]);
	}
	free(split);
}

t_stack	*ft_msg_error(t_stack **stack, int msg, char **split)
{
	if (msg)
		write(2, "Error\n", 6);
	ft_stack_clear(stack);
	if (split)
		ft_free_split(split);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 2)
		stack_a = ft_get_split(argc, argv);
	else
		stack_a = ft_get_stack(argc, argv);
	if (!stack_a)
		return (0);
	ft_push_swap(&stack_a);
	ft_stack_clear(&stack_a);
	return (0);
}
