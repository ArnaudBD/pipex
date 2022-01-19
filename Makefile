NAME =	pipex


SRCS = 		main.c\
			gnl_utils.c\
			gnl.c\
			parsing-pipex.c\
			split-utils.c\
			utils.c
				

OBJS =	$(SRCS:.c=.o)

CC =	gcc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

RM = 	rm -f

INCS	=	includes/

HEADERS	=	-I $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all


.PHONY :
		all clean fclean re
