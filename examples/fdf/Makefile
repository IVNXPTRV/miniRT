# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:48:06 by ipetrov           #+#    #+#              #
#    Updated: 2024/12/08 10:10:23 by ipetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# make && ./fdf ../tests/subj/test_maps/42.fdf
# Compiler and flags
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -Wunreachable-code -Ofast -MMD -MF
# -Ofast
RM					=	rm -rf

# Name of the output library
NAME 				=	fdf

# Include directories
INCLUDE_DIRS		=	./include \
						./lib/elibft/include \
						./lib/MLX42/include/MLX42 \

# Source directories
VPATH				=	./src/:\
						./src/parsing:\
						./src/hooks:\

# Include flags
INCLUDE				=	$(addprefix -I , $(INCLUDE_DIRS))

# Libraries
LIB 				=	./lib/elibft/elibft.a \
						./lib/MLX42/build/libmlx42.a \
						-ldl \
						-lglfw \
						-pthread \
						-lm \
# -framework Cocoa \
# -framework OpenGL \
# -framework IOKit \
# -lglfw


LIBMLX	:= ./lib/MLX42

# Source files
SRC					=	\
						filename.c \
						height.c \
						init.c \
						width.c \
						boot.c \
						display.c \
						line.c \
						main.c \
						offset.c \
						projection.c \
						rotation.c \
						scale.c \
						keys.c \
						cross.c \
						ft_exit.c \
						flip.c \

# Object files
OBJ					=	$(SRC:%.c=obj/%.o)

# Dependency files
DEP					=	$(SRC:%.c=dep/%.d)

# Make flags
MFLAGS				=	 --no-print-directory -C

# Build all targets
all: lib $(NAME)


# Link mandatory object files
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $@
	@echo "$(NAME) has been built"

# Build libraries
lib: lib/MLX42
	@make $(MFLAGS) ./lib/elibft

lib/MLX42:
	@git clone https://github.com/codam-coding-college/MLX42.git ./lib/MLX42
	@cmake ./lib/MLX42 -B ./lib/MLX42/build && make -C ./lib/MLX42/build -j4

# Compile mandatory object files
obj/%.o: %.c | obj_dir dep_dir
	@$(CC) $(CFLAGS) dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@ && printf "Compiling: $(notdir $< \n)"

# Create mandatory object directories
obj_dir:
	@mkdir -p obj

# Create mandatory dependency directories
dep_dir:
	@mkdir -p dep

# Clean build files
clean:
	@$(RM) obj
	@$(RM) dep
	@make clean $(MFLAGS) ./lib/elibft
	@rm -rf ./lib/MLX42
	@echo "$(NAME) has been cleaned"

# Clean build files and executables
fclean: clean
	@make fclean $(MFLAGS) ./lib/elibft
	@$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re a lib
.DEFAULT_GOAL := all

# Include the dependency files
-include $(DEP)
