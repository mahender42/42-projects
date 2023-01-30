# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 19:40:42 by mahender          #+#    #+#              #
#    Updated: 2022/10/15 19:40:44 by mahender         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC_PATH = ./source/
SRC = $(addprefix $(SRC_PATH)/, \
main.c check_arg.c create_map.c initializations.c check_map.c \
exiting.c draw_map.c moves.c \
)
OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
//GLFW_FLAGS = -lglfw -L /Users/mahender/.brew/opt/glfw/lib/ -L ./source
GLFW_FLAGS = -lglfw -L /Users/mariavalentinahenderson/.brew/opt/glfw/lib/ -L ./source
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
MLX42_PATH = ./MLX42
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C $(PRINTF_PATH)
	make -C $(MLX42_PATH)
	$(CC) $(OBJ) $(LIBFT_PATH)/libft.a $(PRINTF_PATH)/libftprintf.a \
	$(MLX42_PATH)/libmlx42.a $(GLFW_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	make -C $(MLX42_PATH) clean
	$(RM) $(OBJ)

fclean:
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	make -C $(MLX42_PATH) fclean
	$(RM) $(OBJ) $(NAME)

re: fclean all
