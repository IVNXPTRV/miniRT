# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:48:06 by ipetrov           #+#    #+#              #
#    Updated: 2025/05/21 14:10:00 by assistant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -Wunreachable-code -g -MMD -MF
RM					:=	rm -rf

NAME				:=	miniRT

INCLUDE_DIRS 		:=	./include/ \
						./lib/elibft/include/ \
						./lib/MLX42/include/MLX42/

INCLUDE				:=	$(addprefix -I,$(INCLUDE_DIRS))

UNAME				:=	$(shell uname)

ifeq ($(UNAME), Darwin)
LIB					:=	./lib/elibft/elibft.a \
						./lib/MLX42/build/libmlx42.a \
						-framework Cocoa \
						-framework OpenGL \
						-framework IOKit \
						-lglfw
else ifeq ($(UNAME), Linux)
LIB					:=	./lib/elibft/elibft.a \
						./lib/MLX42/build/libmlx42.a \
						-ldl \
						-lglfw \
						-pthread \
						-lm
endif

SRC 				:=	\
						./src/error/error_printer.c \
						./src/error/error_wrappers.c \
						\
						./src/execution/ambient.c \
						./src/execution/cylinder.c \
						./src/execution/diffuse.c \
						./src/execution/disk.c \
						./src/execution/display.c \
						./src/execution/execution.c \
						./src/execution/graphlib.c \
						./src/execution/hit.c \
						./src/execution/image.c \
						./src/execution/light.c \
						./src/execution/normal.c \
						./src/execution/pixel.c \
						./src/execution/plane.c \
						./src/execution/shadow_ray.c \
						./src/execution/sphere.c \
						./src/execution/view_ray.c \
						\
						./src/math/one_vector.c \
						./src/math/two_vectors.c \
						\
						./src/parsing/ambient.c \
						./src/parsing/brightness.c \
						./src/parsing/camera.c \
						./src/parsing/color.c \
						./src/parsing/cylinder.c \
						./src/parsing/element.c \
						./src/parsing/file.c \
						./src/parsing/light.c \
						./src/parsing/number.c \
						./src/parsing/parsing.c \
						./src/parsing/plane.c \
						./src/parsing/point.c \
						./src/parsing/scene.c \
						./src/parsing/size.c \
						./src/parsing/sphere.c \
						./src/parsing/vector.c \
						\
						./src/main.c \

# Convert src paths to obj paths preserving directory structure
OBJ					:=	$(patsubst ./src/%.c,./obj/%.o,$(SRC))
DEP					:=	$(patsubst ./src/%.c,./dep/%.d,$(SRC))

MFLAGS				:=	--no-print-directory -C


all: lib $(NAME)

# Link object files into executable
$(NAME): $(OBJ) ./lib/elibft/elibft.a ./lib/MLX42/build/libmlx42.a Makefile
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJ) $(LIB) -o $@
	@echo "$(NAME) built successfully."

# Build libraries
lib: lib/MLX42/
	@make $(MFLAGS) ./lib/elibft/

lib/MLX42/:
	@git clone https://github.com/codam-coding-college/MLX42.git ./lib/MLX42/
	@cmake ./lib/MLX42/ -B ./lib/MLX42/build/ && make -C ./lib/MLX42/build/ -j4

# Compile rule for each object, create obj subdirs as needed
./obj/%.o: ./src/%.c | obj_dir dep_dir
	@mkdir -p $(dir $@) ./dep/$(dir $(@:obj/%.o=%))
	$(CC) $(CFLAGS) ./dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

# Create root obj directory (subdirs made automatically)
obj_dir:
	@mkdir -p obj

# Create root dep directory (subdirs made automatically)
dep_dir:
	@mkdir -p dep

clean:
	@$(RM) obj
	@$(RM) dep
	@make clean $(MFLAGS) ./lib/elibft
	@rm -rf ./lib/MLX42
	@echo "Cleaned build files."

fclean: clean
	@make fclean $(MFLAGS) ./lib/elibft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re lib obj_dir dep_dir

# Include dependency files if they exist
-include $(DEP)
