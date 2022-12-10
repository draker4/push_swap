/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_five_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:09:56 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/10 17:50:40 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

// static int	*ft_sort_tab(int *tab, int len)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = 0;
// 	while (i < len)
// 	{
// 		j = i + 1;
// 		while (j < len)
// 		{
// 			if (tab[j] < tab[i])
// 			{
// 				tmp = tab[i];
// 				tab[i] = tab[j];
// 				tab[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (tab);
// }

// static int	*ft_index_tab(t_stack *stack)
// {
// 	int		*tab;
// 	int		i;
// 	int		len;

// 	len = ft_stack_size(stack);
// 	tab = malloc(sizeof(int) * len);
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	while (stack)
// 	{
// 		tab[i++] = stack->value;
// 		stack = stack->down;
// 	}
// 	return (ft_sort_tab(tab, len));
// }

// int	ft_index_pos(t_stack **stack_a)
// {
// 	t_stack	*current;
// 	int		*tab;
// 	int		i;

// 	tab = ft_index_tab(*stack_a);
// 	if (!tab)
// 		return (0);
// 	current = *stack_a;
// 	while (current)
// 	{
// 		i = 0;
// 		while (current->value != tab[i])
// 			i++;
// 		current->index_pos = i;
// 		current = current->down;
// 	}
// 	free(tab);
// 	return (1);
// }

static void	ft_push_chunk(t_stack **stack_a, t_stack **stack_b, \
int chunk_min, int len_a)
{
	int		i;
	int		top_value;

	i = 0;
	while (i < len_a)
	{
		top_value = ft_top_value(*stack_a);
		if (top_value >= chunk_min && top_value < chunk_min + 100)
			ft_push_b(stack_a, stack_b);
		else
			ft_rotate(stack_a, 1, 1);
		i++;
	}
}

static void	ft_push_min(t_stack **stack_a, t_stack **stack_b, int min)
{
	// ft_printf("min = %d\n", min);
	if (min >= 0)
	{
		while (min--)
			ft_rotate(stack_b, 2, 1);
	}
	else
	{
		while (min++)
			ft_reverse_rotate(stack_b, 2, 1);
	}
	ft_push_a(stack_a, stack_b);
	ft_rotate(stack_a, 1, 1);
}

static void	ft_push_max(t_stack **stack_a, t_stack **stack_b, int max)
{
	// ft_printf("max = %d\n", max);
	if (max >= 0)
	{
		while (max--)
			ft_rotate(stack_b, 2, 1);
	}
	else
	{
		while (max++)
			ft_reverse_rotate(stack_b, 2, 1);
	}
	ft_push_a(stack_a, stack_b);
}

void	ft_push_back_order(t_stack **stack_a, t_stack **stack_b, int len_b)
{
	int		min;
	int		max;

	min = ft_get_max(*stack_b, 0);
	max = ft_get_max(*stack_b, 1);
	// ft_printf("min = %d et max = %d\n", min, max);
	if (len_b == 1)
		ft_push_a(stack_a, stack_b);
	else if (min <= max && min <= len_b - min && min <= len_b - max)
		ft_push_min(stack_a, stack_b, min);
	else if (len_b - min <= max && len_b - min <= min \
	&& len_b - min <= len_b - max)
		ft_push_min(stack_a, stack_b, -(len_b - min));
	else if (max <= min && max <= len_b - min && max <= len_b - max)
		ft_push_max(stack_a, stack_b, max);
	else
		ft_push_max(stack_a, stack_b, -(len_b - max));
}

void	ft_stack_five_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	int		len_b;
	int		chunk_min;

	len_a = ft_stack_size(*stack_a);
	chunk_min = -100;
	if (!ft_index_pos(stack_a))
		return ;
	while (!ft_is_sorted(*stack_a, 1, 1))// && chunk_min < 60)
	{
		// ft_printf("sorted = %d\n", ft_is_sorted(*stack_a, 1, 1));
		chunk_min += 100;
		// ft_printf("debut chunkmin = %d\n", chunk_min);
		// ft_print_stack(*stack_a, 1);
		// ft_print_stack(*stack_b, 2);
		ft_push_chunk(stack_a, stack_b, chunk_min, len_a);
		// ft_printf("apres push chuck = %d\n", chunk_min);
		// ft_print_stack(*stack_a, 1);
		// ft_print_stack(*stack_b, 2);
		len_b = ft_stack_size(*stack_b);
		while (*stack_b)
		{
			// ft_printf("dans stack b et lenb = %d\n", len_b);
			// ft_print_stack(*stack_a, 1);
			// ft_print_stack(*stack_b, 2);
			ft_push_back_order(stack_a, stack_b, len_b);
			len_b--;
		}
		ft_stack_order(stack_a, 1, 0);
	}
	//ft_print_stack(*stack_a, 1);
}
