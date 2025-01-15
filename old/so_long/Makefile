RED = "\033[0;31m"
YELLOW = "\033[0;33m"
BLACK = "\033[0m"
MAGENTA= "\033[1;35m"
CYAN = "\033[36m"
GREEN0= "\033[32m"
GREEN1 = "\033[38;5;121m"

SRC = 	validation.c	\
		error.c			\
		mlx.c			\
		main.c			\
		read_map.c \
		dimention_counter.c\
		check_border.c \
		characters.c \
		flood_fill.c \
		mvt.c\
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		string.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = libft.a
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT)
	@echo  $(MAGENTA) $(NAME) is made, let\s Go to play 🎮
	@cc   $(OBJ) $(LIBFT) $(CFLAGS) $(LIBS) -o $(NAME)


$(LIBFT):
	@echo $(CYAN)Making libft .. 👾
	@make -C libft
	@mv libft/libft.a .


clean: 
	@echo  $(GREEN0)Cleaning 🧹
	@rm -rf  $(OBJ) 
	@make -C  libft clean 
	@rm -rf  $(LIBFT)

fclean: clean
	@echo $(GREEN0)Full cleaning 🧹🧼
	@rm -rf  $(NAME) 
	@echo  $(YELLOW)Done cleaning ✨ 

re: fclean all

.PHONY: re clean fclean
