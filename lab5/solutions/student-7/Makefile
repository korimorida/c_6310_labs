NAME = matrix

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft

SRC = src/main.c \
      src/create_matrix.c \
      src/remove_matrix.c \
      src/print_matrix.c \
      src/mult_matrix.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re