SRC = 	main.c get_map.c parsing.c check_path.c \
		set_data.c build_map.c hooks.c directions.c \
		delete.c put_steps.c kill.c error.c

SRCS = ${addprefix srcs/, ${SRC}}

OBJ = ${addprefix binaries/, ${SRC}}

OBJS = ${OBJ:%.c=%.o}

INCLUDES = -I./Libft/includes/libc -I./Libft/includes/ptf \
			-I./Libft/includes/gnl

HEADERS = includes/so_long.h

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

MAKEFLAGS += --no-print-directory 

binaries/%.o : srcs/%.c ${HEADERS} mlx/libmlx.a Libft/libft.a | binaries
	${CC} ${CFLAGS} -I./mlx -I./includes ${INCLUDES} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${OBJS} -LLibft -lft -Lmlx -lmlx -lX11 -lXext -lm -o ${NAME}

all : ${NAME}

binaries :
	@mkdir -p binaries/

Libft/libft.a :
	@make -C Libft

mlx/libmlx.a :
	@make -C mlx

clean :
	${RM} -r binaries/
	@make clean -C mlx
	@make clean -C Libft

fclean : clean
	${RM} ${NAME}
	@make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
