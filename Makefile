NAME = so_long

SRCS = main.c check_map.c check2_map.c error.c\
	load_images.c animation.c event.c ft_map.c\
	libft/ft_strcmp.c libft/ft_itoa.c\
	libft/ft_strlen.c \
	libft/ft_calloc.c \
	libft/ft_split.c  libft/ft_bzero.c \
       gnl/get_next_line.c \
       gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBS= -lmlx -lX11 -lXext 

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.SECONDARY:$(OBJS)
.PHONY : all clean fclean re