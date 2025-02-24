CC = cc
CFLAGS =  -fsanitize=address -g3
AR = ar rcs
RM = rm -f

LIBFT = _libft/libft.a
PRINTF = _printf/libftprintf.a

SRC_PATH = src

SRC = 	src/push_swap.c\
		src/parser.c\
		src/push.c\
		src/debug.c\
		src/swap.c\
		src/rotate.c\
		src/node_utils.c\
		src/stack_utils.c\
		src/sort.c\
		src/cost.c\
		src/index.c\


OBJ = $(SRC:.c=.o)

NAME= push_swap

all: libft printf $(NAME)

libft:
	make -C _libft/

printf:
	make -C _printf/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(OBJ) -o $(NAME)

$(SRC_PATH)/%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $<

	
clean:
	make clean -C _libft
	make clean -C _printf
	$(RM) $(OBJ)

re: fclean all

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBFT)
