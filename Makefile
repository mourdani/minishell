## Executables name
NAME		= minishell

## Sources
SRC	= src/main.c

## Objects (patsubst = path substitute)
OBJ	= ${patsubst src/%, obj/%, $(SRC:.c=.o)}

## LIBFT config
LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= ./src/libft/
LIB_FLAGS	= -L $(LIBFT_DIR) -lft
INC		= -I ./inc/ -I $(LIBFT_DIR)

## Compiling config
CC		= gcc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra

## Output messages
DONE = @echo "libft compiled successfully!"
CLEAN_O = @echo "Object files removed!"
CLEAN_A = @echo "Executables removed!"
DONE = @echo "MINISHELL ready to use!"

all:	obj $(NAME)


$(NAME): $(OBJ) $(LIBFT)
	@$(CC)  $(CFLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	$(DONE)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -sC $(LIBFT_DIR)
	@${RM} obj ${OBJ}
	$(CLEAN_O)

fclean:	clean
	@make fclean -sC $(LIBFT_DIR)
	@${RM} ${NAME}
	$(CLEAN_A)

re: fclean all

.PHONY:	all clean fclean re obj
