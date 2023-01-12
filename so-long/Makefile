SRC = test.c

SRCS = ${addprefix srcs/, ${SRC}}

OBJ = ${addprefix binaries/, ${SRC}}

OBJS = ${OBJ:%.c=%.o}

HEADERS = includes/so_long.h

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

MAKEFLAGS += --no-print-directory 

binaries/%.o : srcs/%.c ${HEADERS} build_lib | build_bin
	${CC} ${CFLAGS} -I./mlx -I./includes -I./Libft/includes/libc -c $< -o $@ 

${NAME} : ${OBJS}
	${CC} ${OBJS} -LLibft -lft -Lmlx -lmlx -lX11 -lXext -o ${NAME}

all : ${NAME}

build_bin :
	@mkdir -p binaries/

build_lib :
	@make -s -C mlx
	@make -C Libft

clean :
	${RM} -r binaries/
	@make clean -C mlx
	@make clean -C Libft

fclean : clean
	${RM} ${NAME}
	@make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
