/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:46:15 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 19:33:27 by bperriol         ###   ########lyon.fr   */
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
