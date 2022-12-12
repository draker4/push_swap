/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_thousand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:18:42 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/10 17:46:58 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

static int	*ft_sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static int	*ft_index_tab(t_stack *stack)
{
	int		*tab;
	int		i;
	int		len;

	len = ft_stack_size(stack);
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = 0;
	while (stack)
	{
		tab[i++] = stack->value;
		stack = stack->down;
	}
	return (ft_sort_tab(tab, len));
}

int	ft_index_pos(t_stack **stack_a)
{
	t_stack	*current;
	int		*tab;
	int		i;

	tab = ft_index_tab(*stack_a);
	if (!tab)
		return (0);
	current = *stack_a;
	while (current)
	{
		i = 0;
		while (current->value != tab[i])
			i++;
		current->index_pos = i;
		current = current->down;
	}
	free(tab);
	return (1);
}

void	ft_stack_thousand(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	top_value;
	int	i;
	int	j;

	if (!ft_index_pos(stack_a))
		return ;
	size_a = (int)ft_stack_size(*stack_a);
	i = 0;
	while (!ft_is_sorted(*stack_a, 1, 0))
	{
		j = 0;
		while (j < size_a)
		{
			top_value = ft_top_value(*stack_a);
			if ((top_value >> i) & 1)
				ft_rotate(stack_a, 1, 1);
			else
				ft_push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_push_a(stack_a, stack_b);
		i++;
	}
}
