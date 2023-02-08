# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 18:05:47 by angalsty          #+#    #+#              #
#    Updated: 2022/12/14 14:18:33 by angalsty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SERVER_B = server_bonus

CLIENT_B = client_bonus

SRCS = server.c \

OBJS = ${SRCS:.c=.o}

SRCS2 = client.c \

OBJS2 = ${SRCS2:.c=.o}

S_SRCS_B = server_bonus.c \

S_OBJS_B = ${S_SRCS_B:.c=.o}

C_SRCS_B = client_bonus.c \

C_OBJS_B = ${C_SRCS_B:.c=.o}

PRINTF = printf/libftprintf.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

all: ${SERVER} ${CLIENT}

bonus: ${SERVER_B} ${CLIENT_B}

${SERVER}: ${OBJS} ${PRINTF}
		@${CC} ${CFLAGS} ${OBJS} ${PRINTF} -o ${SERVER} 

${CLIENT}: ${OBJS2} ${PRINTF}
		@${CC} ${CFLAGS} ${OBJS2} ${PRINTF} -o ${CLIENT} 

${PRINTF}:
		@${MAKE} -C ./printf

${SERVER_B}: ${S_OBJS_B} ${PRINTF}
		@${CC} ${CFLAGS} ${S_OBJS_B} ${PRINTF} -o ${SERVER_B} 

${CLIENT_B}: ${C_OBJS_B} ${PRINTF}
		@${CC} ${CFLAGS} ${C_OBJS_B} ${PRINTF} -o ${CLIENT_B} 

clean:
		${RM} ${OBJS} ${OBJS2} ${S_OBJS_B} ${C_OBJS_B}
		@${MAKE} -C printf/ clean

fclean: clean
		${RM} ${SERVER} ${CLIENT} ${SERVER_B} ${CLIENT_B}
		@${MAKE} -C printf/ fclean

re: fclean all

.PHONY: all clean fclean re bonus
