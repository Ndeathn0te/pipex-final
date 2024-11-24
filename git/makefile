NAME = pipex
NAME_BONUS = pipex_bonus

# Directorio de libft
LIBFT_DIR = libft

# Archivos fuente
SRCS = pipex.c utils_pipex.c process.c
SRCS_BONUS = pipex_bonus.c utils_bonus.c process_bonus.c last_command_bonus.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regla principal (compilar libft y pipex)
all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) fclean && make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Regla para el bonus (compilar libft y pipex_bonus)
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT_DIR) fclean && make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

# Compilación de archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla de limpieza (elimina ejecutables y objetos)
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

# Regla para limpieza completa (elimina todo, incluidos los ejecutables)
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

# Regla de recompilado completo
re: fclean all bonus

.PHONY: all bonus clean fclean re