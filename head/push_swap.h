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
	int				nb_order;
	int				nb_op_a;
	int				nb_op_b;
	int				seq;
	struct s_stack	*down;
}	t_stack;

//prototypes main
t_stack	*ft_msg_error(t_stack **stack, int msg, char **split);
void	ft_free_split(char **split);

//prototypes listes chainees
t_stack	*ft_new_el_stack(int value);
void	ft_stack_back(t_stack **begin, t_stack *el);
void	ft_stack_clear(t_stack **stack);
size_t	ft_stack_size(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);

//prototypes get_stack
t_stack	*ft_get_stack(int argc, char **argv);
t_stack	*ft_get_split(int argc, char **argv);

//prototype push_swap
int		ft_push_swap(t_stack **stack_a);

//prototypes operations
void	ft_swap(t_stack **stack, int which, int msg);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack, int which, int msg);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, int which, int msg);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

//prototypes stack order
void	ft_stack_order(t_stack **stack_a, int which, int max);
int		ft_get_max(t_stack *stack, int max);
int		ft_is_sorted(t_stack *stack, int order);
int		ft_abs(int nb);

//prototype stack hundred
int		ft_stack_hundred(t_stack **stack_a, t_stack **stack_b);

//prototype find sequence
void	ft_find_sequence(t_stack **stack_a);

//prototype push other that are not seq = 1
void	ft_push_others(t_stack **stack_a, t_stack **stack_b);

//prototype calculate nb op
void	ft_calculate_op(t_stack *stack_a, t_stack **stack_b, int *min);

//prototype rotation both stack knowing min operations to do
void	ft_rotation_both_min_op(t_stack **stack_a, t_stack **stack_b, \
		t_stack *current);



void	ft_print_stack(t_stack *stack, int who);

#endif
