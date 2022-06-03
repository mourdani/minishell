## Executables name
NAME		= minishell

## Sources
SRC	= 	src/main.c \
		src/signals.c \
		src/parsing/history.c \
		src/parsing/ft_cut_exit.c \
		src/parsing/ft_clear_token.c \
		src/parsing/ft_cut_cd.c \
		src/parsing/ft_cut_env.c \
		src/parsing/ft_cut_pwd.c \
		src/parsing/ft_cut_input.c \
		src/parsing/ft_cut_export.c \
		src/parsing/ft_cut_echo.c \
		src/parsing/ft_cut_unset.c \
		src/parsing/ft_cut_bin.c \
		src/parsing/quote.c \
		src/parsing/cut_str.c \
		src/parsing/ft_cut_redirects.c \
		src/parsing/ft_pre_parsing.c \
		src/parsing/ft_quote.c \
		src/init/ft_init_token.c \
		src/init/ft_init_data.c \
		src/init/ft_init_var.c \
		src/builtin/ft_read_token_list.c \
		src/builtin/ft_echo.c \
		src/builtin/ft_pwd.c \
		src/builtin/ft_env.c \
		src/builtin/ft_unset.c \
		src/builtin/ft_export.c \
		src/builtin/ft_cd.c \
		src/utils/ft_write.c \
		src/utils/ft_str.c \
		src/utils/ft_parse_arg.c \
		src/var/ft_var.c \
		src/var/ft_var_sort.c \
		src/bin/ft_bin.c \
		src/redir/ft_pipe.c \
		src/redir/ft_in_file.c \
		src/redir/ft_here_doc.c \



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
	@$(CC)  $(CFLAGS) $(OBJ) $(LIB_FLAGS) -lreadline -o $(NAME)
	$(DONE)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

obj:
	@mkdir -p obj
	@mkdir -p obj/parsing
	@mkdir -p obj/init
	@mkdir -p obj/builtin
	@mkdir -p obj/utils
	@mkdir -p obj/var
	@mkdir -p obj/bin
	@mkdir -p obj/redir

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

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
