NAME		=	push_swap
LIBFT		=	$(LIBFT_PATH)/libft.a

SRC_PATH	=	./src
LIBFT_PATH	=	./libft
OBJ_PATH	=	./obj

SRC			=	stack_init.c \
				movements.c \
				sort.c \
				push_swap.c

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra
IFLAGS		=	-I ./libft
LFLAGS		=	-L ./libft -lft
RM			=	rm -rf

OBJS		=	$(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

$(LIBFT): 
	@make -C $(LIBFT_PATH) all bonus

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all
