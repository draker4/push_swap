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

# define CHUNK_SIZE 100

typedef struct s_stack
{
	int				value;
	int				nb_op_a;
	int				nb_op_b;
	int				nb_op;
	int				index_pos;
	struct s_stack	*down;
}	t_stack;

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
void	ft_push_swap(t_stack **stack_a);

//prototypes operations
void	ft_swap(t_stack **stack, int which, int msg);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b, int msg);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b, int msg);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b, int msg);
void	ft_rotate(t_stack **stack, int which, int msg);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int msg);
void	ft_reverse_rotate(t_stack **stack, int which, int msg);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int msg);

//prototypes stack order
void	ft_stack_order(t_stack **stack_a, int which, int max);
int		ft_get_max(t_stack *stack, int max);
int		ft_is_sorted(t_stack *stack, int order, int rotate);
int		ft_abs(int nb);
int		ft_top_value(t_stack *stack);

//prototype stack hundred
void	ft_stack_hundred(t_stack **stack_a, t_stack **stack_b);

//prototype calculate nb op
void	ft_calculate_op(t_stack *stack_a, t_stack *stack_b, \
		int *min, int len_b);

//prototype rotation both stack knowing min operations to do
void	ft_choose_rotation_min_op(t_stack **stack_a, t_stack **stack_b, \
		t_stack *current);

//prototype tab index
int		ft_index_pos(t_stack **stack_a);

//prototypes utils
void	ft_free_split(char **split);
t_stack	*ft_msg_error(t_stack **stack, int msg, char **split);

#endif
