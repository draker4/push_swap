/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:19:21 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/04 20:46:20 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	ft_sort_one(t_stack **stack_a, t_stack **stack_b)
{
	int	index_a;
	int	index_b;
	int	rot_a;
	int	rot_b;
	int	i;

	i = 0;
	// ft_printf("iciiii debut sort one\n");
	// ft_print_stack(*stack_a, 1);
	// ft_print_stack(*stack_b, 2);
	index_a = ft_is_rotated(*stack_a, 1);
	index_b = ft_is_rotated(*stack_b, 0);
	if (index_a == -1 && index_b == -1)
		return ;
	if (index_a < (int)ft_stack_size(*stack_a) / 2)
		rot_a = 0;
	else
		rot_a = 1;
	if (index_b < (int)ft_stack_size(*stack_b) / 2)
		rot_b = 0;
	else
		rot_b = 1;
	// ft_printf("rota= %d et indexa = %d\n", rot_a, index_a);
	// ft_printf("maxa = %d\n", ft_get_max(*stack_a, 1));
	// ft_printf("rotb= %d et indexb = %d\n", rot_b, index_b);
	if (rot_a == rot_b && rot_a == 0)
	{
		while (index_a <= index_b && i++ < index_a)
			ft_rotate_both(stack_a, stack_b);
		while (index_a <= index_b && i++ < index_b + 1)
			ft_rotate(stack_b, 2, 1);
		while (index_a > index_b && i++ < index_b)
			ft_rotate_both(stack_a, stack_b);
		while (index_a > index_b && i++ < index_a + 1)
			ft_rotate(stack_a, 1, 1);
	}
	else if (rot_a == rot_b && rot_a == 1)
	{
		while (index_a <= index_b && i++ < index_a)
			ft_reverse_rotate_both(stack_a, stack_b);
		while (index_a <= index_b && i++ < index_b)
			ft_reverse_rotate(stack_b, 2, 1);
		while (index_a > index_b && i++ < index_b)
			ft_reverse_rotate_both(stack_a, stack_b);
		while (index_a > index_b && i++ < index_a)
			ft_reverse_rotate(stack_a, 1, 1);
	}
	else if (rot_a == 0)
	{
		while (i++ < index_a)
			ft_rotate(stack_a, 1, 1);
		i = 0;
		while (i++ < index_b)
			ft_reverse_rotate(stack_b, 2, 1);
	}
	else if (rot_b == 0)
	{
		while (i++ < index_b)
			ft_rotate(stack_b, 2, 1);
		i = 0;
		while (i++ < index_a)
			ft_reverse_rotate(stack_a, 1, 1);
	}
	if (!index_a && !index_b)
		ft_reverse_rotate_both(stack_a, stack_b);
	else if (!index_a)
		ft_reverse_rotate(stack_a, 1, 1);
	else if (!index_b)
		ft_reverse_rotate(stack_b, 2, 1);
	if (index_a != -1 && index_b != -1)
		ft_swap_both(stack_a, stack_b);
	else if (index_a == -1)
		ft_swap(stack_b, 2, 1);
	else if (index_b == -1)
		ft_swap(stack_a, 1, 1);
	// ft_printf("iciiii finnnn sort one indexa = %d et indexb = %d\n", index_a, index_b);
	// ft_print_stack(*stack_a, 1);
	// ft_print_stack(*stack_b, 2);
	ft_sort_one(stack_a, stack_b);
}
