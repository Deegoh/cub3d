#color
GREEN = \e[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \e[33m
HIDDEN = \e[8m
RESET = \e[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -Wno-deprecated-declarations

all: $(NOM)

%.o: %.c
	@printf "$(GREEN)🏗️ Generate mlx objects %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.m
	@printf "$(GREEN)🏗️ Generate mlx objects %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

$(NOM):	$(OBJ)
	@ar -rcs $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "$(GREEN)🏗️ Generate $(NAME)$(WHITE)\n"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@printf "$(YELLOW)♻️ Clean mlx objects$(WHITE)\n"

re: clean all
