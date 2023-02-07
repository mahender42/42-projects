# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 13:56:26 by angalsty          #+#    #+#              #
#    Updated: 2022/11/07 20:15:47 by angalsty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_utils.c ft_print_unsigned.c ft_print_hex.c \
		  ft_print_ptr.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I.

INCLUDES = libftprintf.h

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
			make -C libft/ all
			cp libft/libft.a $(NAME)
			ar -rc $(NAME) $(OBJS) 

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		make -C libft/ fclean

re:	fclean all

.PHONY: all clean fclean re