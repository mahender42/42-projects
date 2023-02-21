#MANDATORY DEFINITIONS#
#Name ejecutables#
NAME_SERVER = server
NAME_CLIENT = client

#Declear sources#
SRC_SERVER = server.c
SRC_CLIENT = client.c

#Compile with .o#
OBJS_SERVER = ${SRC_SERVER:.c=.o}
OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

#BONUS DEFINITIONS#
#Name ejecutables#
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

#Declear sources#
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

#Name .o#
OBJS_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}
OBJS_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}

#COMPILATION#
LIBRARY = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#RULES#
.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: libft compile

libft: 
	@echo " ---> Compiling LIBFT <--- \n"
	@${MAKE} -C ./libft

compile: ${NAME_SERVER} ${NAME_CLIENT}

$(NAME_SERVER): ${OBJS_SERVER}
	@echo " ---> Compiling Server <---\n"
	@${CC} ${OBJS_SERVER} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT): ${OBJS_CLIENT}
	@echo " ---> Compiling Client <--- \n"
	@${CC} ${OBJS_CLIENT} ${LIBRARY} -o ${NAME_CLIENT}

#BONUS RULES#
bonus: libft compile_bonus

compile_bonus: ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

$(NAME_SERVER_BONUS): ${OBJS_SERVER_BONUS}
	@echo " ---> Compiling Server Bonus <--- \n"
	@${CC} ${OBJS_SERVER_BONUS} ${LIBRARY} -o ${NAME_SERVER_BONUS}

$(NAME_CLIENT_BONUS): ${OBJS_CLIENT_BONUS}
	@echo " ---> Compiling Client Bonus <--- \n"
	@${CC} ${OBJS_CLIENT_BONUS} ${LIBRARY} -o ${NAME_CLIENT_BONUS}

#CLEAN RULES#
clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 
	@${RM} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re libft compile
