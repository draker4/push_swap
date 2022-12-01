/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:57:35 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 03:17:56 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static t_stack	*ft_msg_error(t_stack **stack, int msg)
{
	if (msg)
		write(2, "Error\n", 6);
	ft_stack_clear(stack);
	return (NULL);
}

static int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_int(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (result != (result * 10 + str[i] - 48) / 10)
			return (0);
		else
			result = result * 10 + str[i++] - '0';
	}
	return (1);
}

static int	ft_duplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*boucle;

	current = stack;
	while (current->down)
	{
		boucle = current->down;
		while (boucle)
		{
			if (boucle->value == current->value)
				return (0);
			boucle = boucle->down;
		}
		current = current->down;
	}
	return (1);
}

t_stack	*ft_get_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*current;
	int		i;

	if (argc < 2)
		return (ft_msg_error(NULL, 1));
	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_digit(argv[i]) || !ft_is_int(argv[i]))
			return (ft_msg_error(&stack, 1));
		current = ft_new_el_stack(ft_atoi(argv[i++]));
		if (!current)
			return (ft_msg_error(&stack, 0));
		ft_stack_back(&stack, current);
	}
	if (!ft_duplicate(stack))
		return (ft_msg_error(&stack, 1));
	return (stack);
}
