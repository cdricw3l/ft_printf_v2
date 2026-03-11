CC=cc
AR= ar -rcs
NAME=libftprintf.a
GFLAGS=-Wall -Wextra -Werror
SRCS=	ft_printf.c \
		ft_printf_utils.c
SRCS_OBJS= ${SRCS:.c=.o}

%.o:%.c
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}: ${SRCS_OBJS}
	${AR} ${NAME} ${SRCS_OBJS}

clean:
	rm -rf ${SRCS_OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

COM=ft_printf_v2

git: fclean
	git add .
	git commit -m ${COM}