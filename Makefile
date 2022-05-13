SRCS = ./mandatory/pipex.c  ./mandatory/ft_split.c ./mandatory/join_dup_error.c ./mandatory/check_search_pre.c \

SRCS_BONUS = ./bonus/pipex_bonus.c ./bonus/ft_split.c ./bonus/check_search.c\
			./bonus/forking.c ./bonus/forking2.c ./bonus/join_dup_cmp.c \
			./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \

NAME = pipex

NAME_BONUS = pipex_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

${NAME} :
		${CC} ${FLAGS} ${SRCS} -o ${NAME}

${NAME_BONUS} :
		${CC} ${FLAGS} ${SRCS_BONUS} -o ${NAME_BONUS}

all : mandatory bonus

mandatory : ${NAME}

bonus : ${NAME_BONUS}

clean :
		rm -f ${NAME}

bclean :
		rm -f ${NAME_BONUS}

fclean :	clean bclean

re : clean mandatory

bre : bclean bonus

re_all : fclean all 
