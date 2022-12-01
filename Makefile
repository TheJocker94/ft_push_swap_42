CC = gcc

NAME = libpushswap.a

SRC := $(wildcard *.c */*.c)

OBJ_S = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ_S)
	@ar -rcs $@ $^
	@echo Libreria compilata!

%.o:%.c
	@$(CC) -c -g $(CFLAG) -I. $< -o $@

clean: 
	@/bin/rm -f *.o */*.o

fclean: clean
	@/bin/rm -f $(NAME)
	@echo File .o e libreria rimossi!

re: fclean all

run: all
	@gcc $(CFLAG) ft_push_swap.c $(NAME)
	./a.out $(ARGS)
debug: re 
	gcc -g ft_push_swap.c $(NAME)
	gdb --args ./a.out $(ARGS)
	
.PHONY: all clean fclean re run
