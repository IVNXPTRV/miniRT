# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:48:06 by ipetrov           #+#    #+#              #
#    Updated: 2025/05/18 13:05:40 by ipetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -Wunreachable-code -MMD -MF
# -Ofast
RM					=	rm -rf

# Name of the output library
NAME 				=	fdf

# Include directories
INCLUDE_DIRS		=	./include \
						./lib/MLX42/include/MLX42 \

# Source directories
VPATH				=	./src/:\

# Include flags
INCLUDE				=	$(addprefix -I , $(INCLUDE_DIRS))

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	LIB = ./lib/MLX42/build/libmlx42.a \
		  -framework Cocoa \
		  -framework OpenGL \
		  -framework IOKit \
		  -lglfw
else ifeq ($(UNAME), Linux)
	LIB = ./lib/MLX42/build/libmlx42.a \
		  -ldl \
		  -lglfw \
		  -pthread \
		  -lm
endif

# $(info LIB is: $(LIB))

LIBMLX	:= ./lib/MLX42

# Source files
SRC					=	\
						main.c \

# Object files
OBJ					=	$(SRC:%.c=obj/%.o)

# Dependency files
DEP					=	$(SRC:%.c=dep/%.d)

# Make flags
MFLAGS				=	 --no-print-directory -C

# Build all targets
all: lib/MLX42 $(NAME)

# Link mandatory object files
$(NAME): $(OBJ)
	@echo "Building $(NAME) ..."
	@$(CC) $(OBJ) $(LIB) -o $@
	@echo "$(NAME) has been built"


lib/MLX42:
	@git clone https://github.com/codam-coding-college/MLX42.git ./lib/MLX42
	@cmake ./lib/MLX42 -B ./lib/MLX42/build && make -C ./lib/MLX42/build -j4

# Compile mandatory object files
obj/%.o: %.c | obj_dir dep_dir
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
	@rm -rf ./lib/MLX42
	@echo "$(NAME) has been cleaned"

# Clean build files and executables
fclean: clean
	@$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re lib
.DEFAULT_GOAL := all

# Include the dependency files
-include $(DEP)
