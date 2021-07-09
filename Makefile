CC = gcc

CFLAGS = 

LFLAGS = -lXext -lX11 -lm -lz

LIBMLX = libmlx/libmlx_Linux.a

HEADER = philosophers.h

NAME = fractol

RM = rm -f

SRCS := $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBMLX) $(LFLAGS) -o $(NAME)

# $(NAME): $(OBJS)
# 	$(CC)  $^ -o $@
#  -fsanitize=address
%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

all:	$(NAME)

.PHONY:	all clean fclean re