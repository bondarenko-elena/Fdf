# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olbondar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 17:02:12 by olbondar          #+#    #+#              #
#    Updated: 2018/02/24 17:02:13 by olbondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
SRC := main.c \
		brezenhem.c \
		put_line.c \
		init_map.c \
		drawer.c \
		handle_key.c \
		mlx.c \
		alloc_lines.c \
		init_check_chars.c \
		parser.c \
		convert_matrix.c \
		table_del.c \
		zoom.c \
		move.c \

SRC:= $(addprefix src/,$(SRC))
OBJ := $(SRC:.c=.o)
HEADLIB := libft/
HEADMLX := /usr/local/include
CFLAGS := -Wall -Wextra -Werror
LIBMLX := /usr/local/lib
FRAMEWS := -lmlx -framework OpenGL -framework AppKit

all: create_lib $(NAME)

create_lib:
	@make -C libft

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) libft/libft.a -L $(LIBMLX) $(FRAMEWS)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADLIB) -I $(HEADMLX) -I includes

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
