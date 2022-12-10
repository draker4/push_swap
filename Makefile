.PHONY:	all clean fclean re fclean_lib fclean_all

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	push_swap

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	srcs/

DIR_LIBFT	=	libft/

DIR_HEAD	=	head/

#DIR_HEAD	=	head/

# ---- Files ---- #

HEAD		=	push_swap.h

SRCS		=	main.c 					ft_get_stack.c			\
				ft_lst_stack.c			ft_push_swap.c			\
				ft_swap.c				ft_push.c				\
				ft_rotate.c				ft_reverse_rotate.c		\
				ft_stack_order.c		ft_stack_hundred.c		\
				ft_calculate_nb_op.c	ft_find_sequence.c		\
				ft_push_not_seq.c		ft_rot_both_min_op.c	\
				ft_stack_thousand.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
					make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #
					
fclean_lib		:	
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean all
