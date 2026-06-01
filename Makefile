MAKEFLAGS += -s --no-print-directory

NAME			:= fdf
LIBFT			:= libft.a
MINILIBX		:= libmlx_Linux.a

SRC_DIR 		:= src
OBJ_DIR 		:= obj
INC_DIR 		:= includes
LIB_DIR			:= lib

HEADERS			:= $(INC_DIR)/fdf.h
CC				:= clang
CFLAGS			:= -Wall -Werror -Wextra
MLXFLAGS		:= -lXext -lX11 -lm

SRCS			:= \
					main \
					core/pipeline \
					core/draw_line \
					core/render \
					core/color \
					core/clip \
					core/points \
					helpers/raw_elements \
					helpers/disp \
					helpers/show_selector \
					helpers/show_infos_obj \
					helpers/show_infos_bottom \
					helpers/show_infos_top \
					hooks/hooks_effects \
					hooks/hooks_keybd \
					hooks/hooks_modes \
					hooks/hooks_rotation \
					hooks/hooks_scale \
					hooks/hooks_translation \
					hooks/main_hooks_1 \
					hooks/main_hooks_2 \
					map_management/map_parse \
					map_management/mab_build \
					map_management/map_check \
					math/autoview \
					math/center \
					math/create_pipe_mat4 \
					math/create_base_mat4 \
					math/mat4_ops \
					math/mat4_inv \
					math/quat \
					math/quat_ops \
					math/vect \
					memory/constructors \
					memory/destructors \
					memory/exit \
					memory/init \
					memory/mlx_elements \
					projections/isometric \
					projections/init \
					projections/conic


SRCS_FULL 		:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRCS)))

ALL_SRCS		:= $(SRCS_FULL)
ALL_OBJS	  	:= $(ALL_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS			:= libft/$(LIBFT) minilibx-linux/$(MINILIBX)


all: $(NAME) bonus

$(LIBFT):
	@if [ -n "$$(make -C libft/ --dry-run)" ]; then \
		echo "Recompilation de libft.a en cours..."; \
		$(MAKE) -C libft/; \
	else \
		echo "libft.a déjà à jour."; \
	fi

$(MINILIBX):
	@$(MAKE) -s -C minilibx-linux/
	# @$(MAKE) -s -C minilibx-linux/ >/dev/null 2>&1

$(NAME): $(LIBFT) $(MINILIBX) $(ALL_OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	echo "Compilation de $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx-linux/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf libft/libft.a
	@rm -rf minilibx-linux/libmlx_Linux.a

re: fclean all

bonus:

test: all
	./fdf test_maps/42.fdf

.PHONY: all clean fclean re bonus small big
