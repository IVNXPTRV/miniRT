# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:48:06 by ipetrov           #+#    #+#              #
#    Updated: 2025/05/21 12:56:42 by ipetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -Wunreachable-code -MMD -MF
RM					=	rm -rf

# Name of the output library
NAME 				=	miniRT

# Include directories
INCLUDE_DIRS		=	./include/ \
						./lib/elibft/include/ \
						./lib/MLX42/include/MLX42/ \

# Include flags
INCLUDE				=	$(addprefix -I , $(INCLUDE_DIRS))

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	LIB = ./lib/elibft/elibft.a \
		  ./lib/MLX42/build/libmlx42.a \
		  -framework Cocoa \
		  -framework OpenGL \
		  -framework IOKit \
		  -lglfw
else ifeq ($(UNAME), Linux)
	LIB = ./lib/elibft/elibft.a \
		  ./lib/MLX42/build/libmlx42.a \
		  -ldl \
		  -lglfw \
		  -pthread \
		  -lm
endif

LIBMLX	:= ./lib/MLX42

# Source files
SRC					=	\
						./src/main.c \
						\
						./src/error/error_printer.c \
						./src/error/error_wrappers.c \
						\
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
						./src/parsing/size.c \
						./src/parsing/sphere.c \
						./src/parsing/vector.c \

# Object files
OBJ					=	$(SRC:%.c=obj/%.o)
$(info OBJ: $(OBJ))

# Dependency files
DEP					=	$(SRC:/%.c=dep/%.d)

# Make flags
MFLAGS				=	 --no-print-directory -C

# Build all targets
all: lib $(NAME)

# Link mandatory object files
$(NAME): $(OBJ)
	@echo "Building $(NAME) ..."
	@$(CC) $(OBJ) $(LIB) -o $@
	@echo "$(NAME) has been built"

# Build libraries
lib: lib/MLX42
	@make $(MFLAGS) ./lib/elibft

lib/MLX42:
	@git clone https://github.com/codam-coding-college/MLX42.git ./lib/MLX42
	@cmake ./lib/MLX42 -B ./lib/MLX42/build && make -C ./lib/MLX42/build -j4

# Compile mandatory object files
obj/%.o: /%.c | obj_dir dep_dir
	$(CC) $(CFLAGS) dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

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
.PHONY: all clean fclean re lib
.DEFAULT_GOAL := all

# Include the dependency files
-include $(DEP)
