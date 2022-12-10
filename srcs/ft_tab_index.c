/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_thousand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:18:42 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/10 19:33:55 by bperriol         ###   ########lyon.fr   */
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
