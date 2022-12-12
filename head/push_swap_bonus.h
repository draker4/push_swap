/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:10:34 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/12 15:23:02 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

typedef struct s_operation
{
	char				*op;
	int					error;
	int					newline;
	struct s_operation	*next;
}	t_operation;

// prototypes lst operation
t_operation	*ft_new_op(char	*str);
int			ft_op_back(t_operation **begin, t_operation *el);
void		ft_op_clear(t_operation **op);

//prototypes checker utils
t_operation	*ft_return_free(t_operation **op, int msg);
int			ft_is_not_op(char *str);

#endif
