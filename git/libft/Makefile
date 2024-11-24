# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 04:44:49 by armgonza          #+#    #+#              #
#    Updated: 2024/11/24 11:35:09 by armgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC				= inc/
SRC_DIR 		= src/
OBJ_DIR 		= obj/

RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC)
PRINTF = ./printf/libftprintf.a

SRCS = $(SRC_DIR)ft_isalpha.c \
	$(SRC_DIR)ft_isdigit.c \
	$(SRC_DIR)ft_isalnum.c \
	$(SRC_DIR)ft_isascii.c \
	$(SRC_DIR)ft_isprint.c \
	$(SRC_DIR)ft_strlen.c \
	$(SRC_DIR)ft_memset.c \
	$(SRC_DIR)ft_bzero.c \
	$(SRC_DIR)ft_memcpy.c \
	$(SRC_DIR)ft_memmove.c \
	$(SRC_DIR)ft_strlcpy.c \
	$(SRC_DIR)ft_strlcat.c \
	$(SRC_DIR)ft_toupper.c \
	$(SRC_DIR)ft_tolower.c \
	$(SRC_DIR)ft_strchr.c \
	$(SRC_DIR)ft_strrchr.c\
	$(SRC_DIR)ft_strncmp.c \
	$(SRC_DIR)ft_memchr.c \
	$(SRC_DIR)ft_memcmp.c \
	$(SRC_DIR)ft_strnstr.c \
	$(SRC_DIR)ft_atoi.c \
	$(SRC_DIR)ft_calloc.c \
	$(SRC_DIR)ft_strdup.c \
	$(SRC_DIR)ft_substr.c \
	$(SRC_DIR)ft_strjoin.c \
	$(SRC_DIR)ft_strtrim.c \
	$(SRC_DIR)ft_split.c \
	$(SRC_DIR)ft_itoa.c \
	$(SRC_DIR)ft_strmapi.c \
	$(SRC_DIR)ft_striteri.c \
	$(SRC_DIR)ft_putchar_fd.c \
	$(SRC_DIR)ft_putstr_fd.c \
	$(SRC_DIR)ft_putendl_fd.c \
	$(SRC_DIR)ft_putnbr_fd.c \
	$(SRC_DIR)ft_lstnew_bonus.c \
	$(SRC_DIR)ft_lstadd_front_bonus.c \
	$(SRC_DIR)ft_lstsize_bonus.c \
	$(SRC_DIR)ft_lstlast_bonus.c \
	$(SRC_DIR)ft_lstadd_back_bonus.c \
	$(SRC_DIR)ft_lstdelone_bonus.c \
	$(SRC_DIR)ft_lstclear_bonus.c \
	$(SRC_DIR)ft_lstiter_bonus.c \
	$(SRC_DIR)ft_lstmap_bonus.c \
	$(SRC_DIR)get_next_line.c


OBJS = $(SRCS:.c=.o)

all: m_printf $(NAME)

m_printf:
	
	@make -C ./printf
	
	@cp $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)


bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C printf clean
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make -C printf fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
