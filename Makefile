CC = gcc

# CFLAGS = 
CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lXext -lX11 -lm -lz

LIBMLX = libmlx/libmlx_Linux.a

HEADER = fractol.h

NAME = fractol

RM = rm -f

SRCS := $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -fsanitize=address $(LIBMLX) $(LFLAGS) -o $(NAME)

# $(NAME): $(OBJS)
# 	$(CC)  $^ -o $@
#  -fsanitize=address
%.o: %.c $(HEADER)
	$(CC) -c -g $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

all:	$(NAME)

.PHONY:	all clean fclean re