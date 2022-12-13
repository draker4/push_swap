/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:08 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/13 15:17:41 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap_bonus.h"

t_operation	*ft_return_free(t_operation **op, int msg)
{
	if (*op)
		ft_op_clear(op);
	if (msg)
		write(2, "Error\n", 6);
	return (NULL);
}

int	ft_is_not_op(char *str)
{
	if (str && ft_strncmp(str, "sa\n\0", 4) && ft_strncmp(str, "sb\n\0", 4) \
	&& ft_strncmp(str, "ss\n\0", 4) && ft_strncmp(str, "pa\n\0", 4) \
	&& ft_strncmp(str, "pb\n\0", 4) && ft_strncmp(str, "ra\n\0", 4) \
	&& ft_strncmp(str, "rb\n\0", 4) && ft_strncmp(str, "rr\n\0", 4) \
	&& ft_strncmp(str, "rra\n\0", 5) && ft_strncmp(str, "rrb\n\0", 5) \
	&& ft_strncmp(str, "rrr\n\0", 5))
		return (0);
	return (1);
}

t_operation	*ft_not_any_op(t_operation *op)
{
	t_operation	*new;
	char		*str;

	str = ft_strdup("null");
	if (!str)
		return (NULL);
	new = ft_new_op(str);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	ft_op_back(&op, new);
	return (op);
}
