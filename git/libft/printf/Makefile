# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 22:44:33 by armgonza          #+#    #+#              #
#    Updated: 2024/11/24 11:54:02 by armgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

# Lista de archivos fuente
SRCS    = ft_printf.c \
          Utils.c \

# Generación de los nombres de los archivos objeto
OBJS    = $(SRCS:%.c=%.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
HEADER  = ft_printf.h

# Regla principal
all:    $(NAME)

# Construcción de la biblioteca
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Compilación de los archivos objeto con dependencia del header
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto y biblioteca
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

# Rehacer todo
re:     fclean all

.PHONY: all clean fclean re
