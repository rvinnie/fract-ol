CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -O3

HEADER = fractol.h

NAME = fractol

RM = rm -f

SRCS =	./fractol.c \
		./drawer.c \
		./draw_set.c \
		./utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

all:	$(NAME)

.PHONY:	all clean fclean re
