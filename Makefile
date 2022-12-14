NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	push_swap.c utils.c\
 				action_a.c action_b.c action_ab.c\
				check_args.c create_list.c extra.c group.c grouponize.c\
				list.c max_min.c min.c max.c sort_big.c sort_little.c\

SRC_BONUS	=	checker.c action_a.c action_b.c action_ab.c\
				check_args.c create_list.c list.c\

LIBFT		=	src/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	gcc -g

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./src
			@echo Libreria compilata!
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C src
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C src
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)
			@echo File .o e libreria rimossi!

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re
