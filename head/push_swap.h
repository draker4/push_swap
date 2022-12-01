/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:50:41 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/01 03:50:41 by bperriol         ###   ########lyon.fr   */
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
size_t	ft_stack_size(t_stack *stack);

//prototypes get_stack
t_stack	*ft_get_stack(int argc, char **argv);

//prototypes push_swap
void	ft_push_swap(t_stack **stack_a);

//prototypes operations
void	ft_swap_a(t_stack **stack, int msg);
void	ft_swap_b(t_stack **stack, int msg);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack, int msg);
void	ft_rotate_b(t_stack **stack, int msg);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_a(t_stack **stack, int msg);
void	ft_reverse_rotate_b(t_stack **stack, int msg);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif