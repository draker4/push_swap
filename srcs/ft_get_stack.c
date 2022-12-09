/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:02 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/09 13:06:45 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
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
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (result != (result * 10 + str[i] - 48) / 10)
			return (0);
		else
			result = result * 10 + str[i++] - '0';
	}
	if (result * sign < (long)INT_MIN || result * sign > (long)INT_MAX)
		return (0);
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
		return (ft_msg_error(NULL, 1, NULL));
	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_digit(argv[i]) || !ft_is_int(argv[i]))
			return (ft_msg_error(&stack, 1, NULL));
		current = ft_new_el_stack(ft_atoi(argv[i++]));
		if (!current)
			return (ft_msg_error(&stack, 0, NULL));
		ft_stack_back(&stack, current);
	}
	if (!ft_duplicate(stack))
		return (ft_msg_error(&stack, 1, NULL));
	return (stack);
}

t_stack	*ft_get_split(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*current;
	char	**split;
	int		i;

	stack = NULL;
	i = 0;
	split = ft_split(argv[argc - 1], ' ');
	if (!split || !*split)
		return (ft_msg_error(NULL, 0, split));
	while (split[i])
	{
		if (!ft_str_is_digit(split[i]) || !ft_is_int(split[i]))
			return (ft_msg_error(&stack, 1, split));
		current = ft_new_el_stack(ft_atoi(split[i++]));
		if (!current)
			return (ft_msg_error(&stack, 0, split));
		ft_stack_back(&stack, current);
	}
	if (!ft_duplicate(stack))
		return (ft_msg_error(&stack, 1, split));
	ft_free_split(split);
	return (stack);
}
