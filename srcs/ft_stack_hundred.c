/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:16:59 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/04 22:12:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

// static int	ft_fill_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	size_t	i;
// 	size_t	len;

// 	i = 0;
// 	len = ft_stack_size(*stack_b);
// 	while (i < len)
// 	{
// 		ft_push_a(stack_a, stack_b);
// 		i++;
// 	}
// 	return (1);
// }

// int	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_stack_order(stack_a, 1, 0);
// 	if (ft_is_sorted(*stack_a, 1) == -1 && *stack_b == NULL)
// 		return (1);
// 	else if (*stack_a == NULL)
// 		return (ft_fill_a(stack_a, stack_b));
// 	ft_push_b(stack_a, stack_b);
// 	return (ft_stack_hundred(stack_a, stack_b));
// }

void	ft_print_stack(t_stack *stack, int who)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("stack %d = %d et %d\n", who, current->value, current->seq);
		current = current->down;
	}
}

// static void	ft_rotate_stacks(t_stack **stack_a, t_stack **stack_b, 
// 	int move_a, int move_b)
// {
// 	int	i;

// 	i = 0;
// 	if (move_a > 0 && move_a <= move_b)
// 	{
// 		while (i++ < move_a)
// 			ft_rotate_both(stack_a, stack_b);
// 		while (i++ < move_b + 1)
// 			ft_rotate(stack_b, 2, 1);
// 	}
// 	else if (move_a > 0 && move_a > move_b)
// 	{
// 		while (i++ < move_b)
// 			ft_rotate_both(stack_a, stack_b);
// 		while (i++ < move_a + 1)
// 			ft_rotate(stack_a, 1, 1);
// 	}
// 	else if (move_a < 0 && - move_a <= - move_b)
// 	{
// 		while (i++ < -move_a)
// 			ft_reverse_rotate_both(stack_a, stack_b);
// 		while (i++ < -move_b + 1)
// 			ft_reverse_rotate(stack_b, 2, 1);
// 	}
// 	else if (move_a < 0 && - move_a > - move_b)
// 	{
// 		while (i++ < -move_b)
// 			ft_reverse_rotate_both(stack_a, stack_b);
// 		while (i++ < -move_a + 1)
// 			ft_reverse_rotate(stack_a, 1, 1);
// 	}
// }

// static void	ft_sort_both(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	min_a;
// 	int	max_b;
// 	int	move_a;
// 	int	move_b;

// 	// ft_printf("AVANT SORT BOTH\n");
// 	// ft_print_stack(*stack_a, 1);
// 	// ft_print_stack(*stack_b, 2);
// 	min_a = ft_get_max(*stack_a, 0);
// 	max_b = ft_get_max(*stack_b, 1);
// 	if (ft_is_sorted(*stack_b, 0) == -1)
// 		return ;
// 	if (min_a < (int)ft_stack_size(*stack_a) - min_a)
// 		move_a = min_a;
// 	else
// 		move_a = ((int)ft_stack_size(*stack_a) - min_a) * (-1);
// 	if (max_b < (int)ft_stack_size(*stack_b) - max_b)
// 		move_b = max_b;
// 	else
// 		move_b = ((int)ft_stack_size(*stack_b) - max_b) * (-1);
// 	if (move_a == 0 && move_b == 0)
// 		return ;
// 	if (move_a * move_b > 0)
// 		ft_rotate_stacks(stack_a, stack_b, move_a, move_b);
// 	else
// 	{
// 		ft_stack_order(stack_a, 1, 0);
// 		ft_stack_order(stack_b, 2, 1);
// 	}
// 	// ft_printf("movea = %d et moveb = %d\n", move_a, move_b);
// 	// ft_printf("APRES MOOOVE\n");
// 	// ft_print_stack(*stack_a, 1);
// 	// ft_print_stack(*stack_b, 2);
// 	if ((*stack_a)->value > ((*stack_b)->value))
// 		return ;
// 	ft_push_a(stack_a, stack_b);
// 	ft_swap(stack_a, 1, 1);
// 	ft_push_b(stack_a, stack_b);
// 	// ft_printf("APRES SORT BOTH\n");
// 	// ft_print_stack(*stack_a, 1);
// 	// ft_print_stack(*stack_b, 2);
// 	ft_sort_both(stack_a, stack_b);
// }

// int	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	i;

// 	i = 0;
// 	//ft_stack_order(stack_a, 0);
// 	// if (ft_is_sorted(*stack_a, 1) && *stack_b == NULL)
// 	// 	return (1);
	
// 		// ft_printf("debut :\n");
// 		// ft_print_stack(*stack_a, 1);
// 		while (i++ < (int)ft_stack_size(*stack_a))
// 			ft_push_b(stack_a, stack_b);
// 		// ft_printf("partage\n");
// 		// ft_print_stack(*stack_a, 1);
// 		// ft_print_stack(*stack_b, 2);
// 		ft_sort_both(stack_a, stack_b);
// 		// ft_printf("apres sort both : \n");
// 		// ft_print_stack(*stack_a, 1);
// 		// ft_print_stack(*stack_b, 2);
// 		i = 0;
// 		ft_sort_one(stack_a, stack_b);
// 		// ft_printf("apres sort one : \n");
// 		// ft_print_stack(*stack_a, 1);
// 		// ft_print_stack(*stack_b, 2);
// 		ft_stack_order(stack_a, 1, 0);
// 		ft_stack_order(stack_b, 2, 1);
// 		while (i++ < (int)ft_stack_size(*stack_a))
// 			ft_push_a(stack_a, stack_b);
// 		// ft_printf("fin : \n");
// 		// ft_print_stack(*stack_a, 1);
	
// 	// ft_printf("fin stack hundred\n");
// 	// ft_print_stack(*stack_a, 1);
// 	//ft_stack_hundred(stack_a, stack_b);

// 	return (1);
// }

// int	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*current;

// 	current = *stack_a;
// 	while (current)
// 	{
// 		ft_printf("stack_a = %d\n", current->value);
// 		current = current->down;
// 	}
// 	ft_printf("\n");

// 	if (ft_is_sorted(*stack_a, 1) && *stack_b == NULL)
// 		return (1);
// 	else if (ft_get_max(*stack_a, 1) == 0)
// 	{
// 		ft_rotate_a(stack_a, 1);
// 		ft_stack_hundred(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		if ((*stack_a)->value > (*stack_a)->down->value)
// 			ft_swap_a(stack_a, 1);
// 		if (!ft_is_sorted(*stack_a, 1))
// 			ft_rotate_a(stack_a, 1);
// 		ft_stack_hundred(stack_a, stack_b);
// 	}
// 	return (1);
// }

void	ft_initialize_seq(t_stack **stack_a, int max_seq)
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

void	ft_push_others(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp = tmp->down;
		if (!(*stack_a)->seq)
			ft_push_b(stack_a, stack_b);
		//push tous les 0 !!!
	}
}

int	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b)
{
	ft_find_sequence(stack_a);
	ft_push_others(stack_a, stack_b);
	ft_print_stack(*stack_a, 1);
	return (1);
}
