NAME = replace_file

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft

LIBFT = libft/libft.a

SRC = \
	src/main.c \
	src/read_file.c \
	src/free_lines.c \
	src/print_lines.c \
	src/replace_substr.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re