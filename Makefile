CC = cc
CFLAGS =  -fsanitize=address -g3
AR = ar rcs
RM = rm -f

LIBFT = _libft/libft.a
PRINTF = _printf/libftprintf.a

SRC_PATH = src
B_SRC_PATH = bonus/src

SRC = 	src/push_swap.c\
		src/parser.c\
		src/push.c\
		src/debug.c\
		src/swap.c\
		src/rotate.c\
		src/stack_utils.c\
		src/node_utils.c\
		src/sort.c\
		src/cost.c\
		src/index.c\
	
B_SRC = bonus/src/checker.c\
		bonus/src/parser.c\
		bonus/src/stack_utils.c\
		bonus/src/node_utils.c\
		bonus/src/push.c\
		bonus/src/swap.c\
		bonus/src/rotate.c\
		bonus/src/index.c\


OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

NAME= push_swap
B_NAME= checker

all: libft printf $(NAME)

bonus: libft printf $(B_NAME)

libft:
	make -C _libft/

printf:
	make -C _printf/

$(B_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(B_OBJ) -o $(B_NAME)

$(B_SRC_PATH)/%.o: %.c bonus/includes/checker.h
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(OBJ) -o $(NAME)

$(SRC_PATH)/%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $<


	
clean:
	make clean -C _libft
	make clean -C _printf
	$(RM) $(OBJ) $(B_OBJ)


fclean: clean
	$(RM) $(NAME) $(B_NAME) $(LIBFT) $(LIBFT)

re: fclean all