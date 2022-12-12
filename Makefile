.PHONY:	all clean fclean re fclean_lib fclean_all bonus

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	push_swap

NAME_BONUS	=	checker

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	srcs/

DIR_LIBFT	=	libft/

DIR_HEAD	=	head/

#DIR_HEAD	=	head/

# ---- Files ---- #

HEAD		=	push_swap.h

HEAD_BONUS	=	push_swap_bonus.h

COMMON_SRCS	=	ft_lst_stack.c			ft_swap.c				\
				ft_rotate.c				ft_reverse_rotate.c		\
				ft_stack_order.c		ft_get_stack.c			\
				ft_push.c				ft_utils.c				\

SRCS		=	main.c 					ft_tab_index.c			\
				ft_push_swap.c			ft_stack_hundred.c		\
				ft_calculate_nb_op.c	ft_rot_both_min_op.c	\

SRCS_BONUS	=	ft_checker_bonus.c		ft_lst_op_bonus.c		\
				ft_utils_bonus.c

COMMON_OBJS	=	${COMMON_SRCS:%.c=${DIR_OBJS}%.o}

OBJS		=	${COMMON_OBJS} ${SRCS:%.c=${DIR_OBJS}%.o}

OBJS_BONUS	=	${COMMON_OBJS} ${SRCS_BONUS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all				:	${NAME}

bonus			:	${NAME_BONUS}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft

${NAME_BONUS}	:	${OBJS_BONUS} Makefile ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_HEAD}, ${HEAD_BONUS}} ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} -L${DIR_LIBFT} -lft

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
					make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${OBJS}			:	${addprefix ${DIR_HEAD}, ${HEAD}} | ${DIR_OBJS}

${OBJS_BONUS}	:	${addprefix ${DIR_HEAD}, ${HEAD_BONUS}} | ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile
					${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #
					
fclean_lib		:	
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME} ${NAME_BONUS}

fclean_all		:	fclean fclean_lib

re				:	fclean all
