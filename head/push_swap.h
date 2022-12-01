/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:55 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/30 20:15:55 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*down;
}	t_stack;

//prototypes listes chainees
t_stack	*ft_new_el_stack(int value);
void	ft_stack_back(t_stack **begin, t_stack *el);
void	ft_stack_clear(t_stack **stack);

//prototypes get_stack
t_stack	*ft_get_stack(int argc, char **argv);

//prototypes push_swap
void	ft_push_swap(t_stack *stack_a);

#endif
