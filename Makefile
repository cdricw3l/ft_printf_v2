CC=cc
AR= ar -rcs
NAME=libftprintf.a
GFLAGS=-Wall -Wextra -Werror
SRCS=	ft_printf.c \
		ft_printf_utils.c
MAIN= main.c
SRCS_OBJS= ${SRCS:.c=.o}
MAIN_OBJS= ${MAIN:.c=.o}

%.o:%.c
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}: ${SRCS_OBJS}
	${AR} ${NAME} ${SRCS_OBJS}

clean:
	rm -rf ${SRCS_OBJS} ${TEST_OBJS}

fclean: clean
	rm -rf ${NAME} test

re: fclean ${NAME}

TEST_OBJS= ${SRCS_OBJS} ${MAIN_OBJS}

test: ${TEST_OBJS}
	${CC} ${GFLAGS} ${TEST_OBJS} -o test

COM=ft_printf_v2

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}