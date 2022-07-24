#color
GREEN = \e[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \e[33m
HIDDEN = \e[8m
RESET = \e[0m

NAME = cub3D

SRC_DIR = src/
SRC = main.c\

LIBFT_DIR = ft
LIBFT = $(SRC_DIR)$(LIBFT_DIR)
INC_LIBFT = -I $(LIBFT) -L $(LIBFT) -lft

ifeq ($(shell uname), Linux)
	MLX_DIR = mlx_linux
else
	MLX_DIR = mlx_mms_20200219
endif
MLX = $(SRC_DIR)$(MLX_DIR)
MLX_LIB= $(SRC_DIR)$(MLX_DIR)
MLX_INC= $(SRC_DIR)$(MLX_DIR)
ifeq ($(shell uname), Linux)
	INC_MLX= -I $(MLX_INC) -L $(MLX_LIB) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else
	INC_MLX= -I $(MLX_INC) -L $(MLX_LIB) -lmlx -lm -framework OpenGL -framework AppKit
endif

OBJ_DIR = obj/
_OBJ = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(_OBJ))

CFLAGS = -Werror -Wall -Wextra
CFLAGS += -g -fsanitize=address

.PHONY: all clean fclean re leak norm

all: $(NAME)

$(OBJ): $(OBJ_DIR)%.o:  $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)🚀 Creating $(OBJ_DIR)$(RESET)\n"
	$(CC) $(CFLAGS) -c $< -o $@ -I inc/ $(INC_LIBFT) $(INC_MLX) -O3

$(NAME): $(OBJ)
	@$(MAKE) all -sC $(LIBFT)
	@$(MAKE) all -ksC $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC_LIBFT) $(INC_MLX)
	@printf "$(GREEN)🚀 Creating $(NAME)$(RESET)\n"
	@sleep 0.2

clean:
	@$(MAKE) clean -sC $(LIBFT)
	@$(RM) -r $(OBJ_DIR)
	@printf "$(YELLOW)♻️ Clean $(OBJ_DIR)$(RESET)\n"
	@sleep 0.2

fclean: clean
	$(RM) $(NAME)

leak: all
	leaks -atExit -- ./$(NAME)
norm:
	norminette $(SRC_DIR)$(SRC) $(LIBFT)

re: fclean all
