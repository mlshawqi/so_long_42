NAME = window_program

# Source files
SRCS = window.c \
       git_next_line/get_next_line.c \
       git_next_line/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iget_next_line

# Libraries
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# Build the program
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild the program
re: fclean $(NAME)
