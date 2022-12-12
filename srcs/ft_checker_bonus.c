/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:55 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/12 15:35:12 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap_bonus.h"

static t_operation	*ft_read_operations(void)
{
	t_operation	*op;
	t_operation	*new;
	char		*line;
	int			new_line;

	op = NULL;
	new_line = 0;
	line = get_next_line(0);
	if (!line || !ft_is_not_op(line))
		return (ft_return_free(&op, 1));
	while (line)
	{
		new = ft_new_op(line);
		if (!new || !ft_op_back(&op, new))
			return (ft_return_free(&op, 0));
		line = get_next_line(0);
		if ((!line && read(0, line, 1) != 0) || !ft_is_not_op(line))
			return (ft_return_free(&op, 1));
	}
	free(line);
	return (op);
}

static void	ft_do_operation(t_stack **stack_a, t_stack **stack_b, \
t_operation *op)
{
	if (!ft_strncmp(op->op, "sa\n", ft_strlen("sa\n")))
		ft_swap(stack_a, 1, 0);
	else if (!ft_strncmp(op->op, "sb\n", ft_strlen("sb\n")))
		ft_swap(stack_b, 2, 0);
	else if (!ft_strncmp(op->op, "ss\n", ft_strlen("ss\n")))
		ft_swap_both(stack_a, stack_b, 0);
	else if (!ft_strncmp(op->op, "pa\n", ft_strlen("pa\n")))
		ft_push_a(stack_a, stack_b, 0);
	else if (!ft_strncmp(op->op, "pb\n", ft_strlen("pb\n")))
		ft_push_b(stack_a, stack_b, 0);
	else if (!ft_strncmp(op->op, "ra\n", ft_strlen("ra\n")))
		ft_rotate(stack_a, 1, 0);
	else if (!ft_strncmp(op->op, "rb\n", ft_strlen("rb\n")))
		ft_rotate(stack_b, 2, 0);
	else if (!ft_strncmp(op->op, "rr\n", ft_strlen("rr\n")))
		ft_rotate_both(stack_a, stack_b, 0);
	else if (!ft_strncmp(op->op, "rra\n", ft_strlen("rra\n")))
		ft_reverse_rotate(stack_a, 1, 0);
	else if (!ft_strncmp(op->op, "rrb\n", ft_strlen("rrb\n")))
		ft_reverse_rotate(stack_b, 1, 0);
	else if (!ft_strncmp(op->op, "rrr\n", ft_strlen("rrr\n")))
		ft_reverse_rotate_both(stack_a, stack_b, 0);
	else
		op->error = 1;
}

static void	ft_checker(t_stack **stack_a, t_operation *op)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (op)
	{
		ft_do_operation(stack_a, &stack_b, op);
		op = op->next;
	}
	if (!stack_b && ft_is_sorted(*stack_a, 1, 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_operation	*op;

	if (argc == 2)
		stack_a = ft_get_split(argc, argv);
	else
		stack_a = ft_get_stack(argc, argv);
	if (!stack_a)
		return (0);
	op = ft_read_operations();
	if (!op)
	{
		ft_stack_clear(&stack_a);
		return (0);
	}
	ft_checker(&stack_a, op);
	ft_stack_clear(&stack_a);
	ft_op_clear(&op);
	return (0);
}
