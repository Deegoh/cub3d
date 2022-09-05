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
		player_movement.c\
		init.c\
		display_map.c\
		key_hook.c\
		test.c\
		parse.c\
		checker_map.c\
		map_utils.c\
		ray.c\
		ray_casting.c\
		display_minimap.c\
		math_utils.c\
		mouse_hook.c\

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

OBJ_DIR_BONUS = obj_bonus/
_OBJ_BONUS = $(SRC:.c=.o)
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(_OBJ_BONUS))

CFLAGS = -Werror -Wall -Wextra
CFLAGS += -g3 #-fsanitize=address

.PHONY: all clean fclean re leak norm run valgrind bonus

all: $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)🏗️ Generate cube3D objects %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@ -I inc/ -I $(LIBFT) -I $(MLX) -O3
	@printf "$(RESET)"

$(NAME): $(OBJ)
	@printf "\n$(RESET)"
	@$(MAKE) all -sC $(LIBFT)
	@$(MAKE) all -sC $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC_LIBFT) $(INC_MLX)
	@printf "$(GREEN)🏗️ Generate $(NAME)$(RESET)\n"

$(OBJ_BONUS): $(OBJ_DIR_BONUS)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@printf "$(GREEN)🏗️ Generate cube3D objects_bonus %-33.33s\r" $@
	@$(CC) $(CFLAGS) -D IS_MAP=\"01NSWEOD\" -c $< -o $@ -I inc/ -I $(LIBFT) -I $(MLX) -O3
	@printf "$(RESET)"

bonus: $(OBJ_BONUS)
	@printf "\n$(RESET)"
	@$(MAKE) all -sC $(LIBFT)
	@$(MAKE) all -sC $(MLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) $(INC_LIBFT) $(INC_MLX)
	@printf "$(GREEN)🏗️ Generate $(NAME)$(RESET)\n"

clean:
	@$(MAKE) clean -sC $(LIBFT)
	@$(MAKE) clean -sC $(MLX)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@printf "$(YELLOW)♻️ Clean cube3D objects$(RESET)\n"

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT)
	@$(RM) $(NAME)
	@printf "$(RED)🗑️ Remove $(NAME)$(WHITE)\n"

leak: all
	leaks -atExit -- ./$(NAME) map/map.cub

norm:
	norminette $(addprefix $(SRC_DIR), $(SRC)) $(LIBFT) inc/

run:
	./$(NAME) map/hole.cub

re: fclean all
