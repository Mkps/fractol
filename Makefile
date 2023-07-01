# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2023/07/01 16:13:26 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCDIR = src
INCDIR = includes
OBJ_DIR = build

SRC = $(SRCDIR)/main.c $(SRCDIR)/window.c $(SRCDIR)/draw.c $(SRCDIR)/utils.c \
		$(SRCDIR)/mandelbrot.c  $(SRCDIR)/julia.c  $(SRCDIR)/nova.c $(SRCDIR)/newton.c \
		$(SRCDIR)/complex.c $(SRCDIR)/menu.c $(SRCDIR)/render.c $(SRCDIR)/hooks.c $(SRCDIR)/atof.c \
		$(SRCDIR)/complex_math.c $(SRCDIR)/complex_ops.c $(SRCDIR)/window_init.c  $(SRCDIR)/color.c \
		$(SRCDIR)/color2.c $(SRCDIR)/color_utils.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)
LIB = -lft -lmlx -lXext -lX11 -lm
CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	make -C libft
	make -C mlx_linux
	$(CC) -o $(NAME) -L libft -L mlx_linux $(OBJ) $(LIB) 

$(OBJ_DIR)/%.o:	$(SRCDIR)/%.c
	mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft
	make clean -C mlx_linux

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C mlx_linux

re: fclean all

.PHONY: all clean fclean re
