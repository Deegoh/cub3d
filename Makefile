#color
GREEN = \e[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \e[33m
HIDDEN = \e[8m
RESET = \e[0m

NAME = cub3D

SRC_DIR = src/
SRC =	main.c\
		error.c\
		free.c\
		draw.c\
		player.c\
		init.c\
		display_map.c\
		key_hook.c\
		test.c\
		parse.c\
		checker_map.c\
		map_utils.c\
		ray.c\
		ray_casting.c\

LIBFT_DIR = ft
LIBFT = $(SRC_DIR)$(LIBFT_DIR)
INC_LIBFT = -I $(LIBFT) -L $(LIBFT) -lft

ifeq ($(shell uname), Linux)
	MLX_DIR = mlx_linux
else
	MLX_DIR = mlx_macos
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

.PHONY: all clean fclean re leak norm run valgrind

all: $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)🏗️ Generate cube3D objects %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@ -I inc/ -I $(LIBFT) -I $(MLX) -O3
	@printf "$(RESET)"

$(NAME): $(OBJ)
	@printf "\n$(RESET)"
#	@$(MAKE) all -sC $(LIBFT)
#	@$(MAKE) all -skC $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC_LIBFT) $(INC_MLX)
	@printf "$(GREEN)🏗️ Generate $(NAME)$(RESET)\n"

clean:
#	@$(MAKE) clean -sC $(LIBFT)
#	@$(MAKE) clean -sC $(MLX)
	@$(RM) -r $(OBJ_DIR)
	@printf "$(YELLOW)♻️ Clean cube3D objects$(RESET)\n"

fclean: clean
	@#$(MAKE) fclean -sC $(LIBFT)
	@$(RM) $(NAME)
	@printf "$(RED)🗑️ Remove $(NAME)$(WHITE)\n"

leak: all
	leaks -atExit -- ./$(NAME) map/map.cub

valgrind: all
		colour-valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	./$(NAME) map/map.cub

norm:
	norminette $(addprefix $(SRC_DIR), $(SRC)) $(LIBFT)

run: all
	./$(NAME) map/hole.cub

re: fclean all
