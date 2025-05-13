MAKEFLAGS += -s

NAME = minirt

CC = cc
CFLAGS = -Wall -Werror -Wextra
DEPFLAGS = -MMD -MP

RM = rm -rf
MKDIR = mkdir -p

# Library Paths
LIBMLX = ./lib/MLX42
MLX_A = $(LIBMLX)/build/libmlx42.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include Directories
HEADERS = -I ./inc -I $(LIBMLX) -I $(LIBFT_DIR)/includes

# Libraries to Link
LIBS = -L$(LIBFT_DIR) -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Source Directories
MAIN_DIR = src
MATH_DIR = src/math
RAY_INTERSECT_DIR = src/ray_intersect
PARSE_DIR = src/parse

# Source Files
MAIN_FILES = main.c window.c
PARSE_FILES = error.c parse.c parse_objs.c validate_elements.c get_temp.c parse_objs2.c  parse_util.c \
				validate_elements2.c scale_color.c check_element.c check_utils.c cam_setup.c
MATH_FILES = math.c math2.c matrix.c
RAY_INTERSECT_FILES = render.c \
					intersect.c sphere.c plane.c cylinder.c \
					light.c color.c shadow.c

# Combine Source Files // can we do this??
MAIN = $(addprefix $(MAIN_DIR)/, $(MAIN_FILES))
PARSE = $(addprefix $(PARSE_DIR)/, $(PARSE_FILES))
MATH = $(addprefix $(MATH_DIR)/, $(MATH_FILES))
RAY_INTERSECT = $(addprefix $(RAY_INTERSECT_DIR)/, $(RAY_INTERSECT_FILES))

# All Source Files
SRCS = $(MAIN) $(MATH) $(RAY_INTERSECT) $(PARSE)
# SRCS = $(PARSE)

# Object Files Directory
OBJ_DIR = obj

# Object Files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Dependency Files
DEPS = $(OBJS:.o=.d)

# Default Target
all: $(NAME)

# Link Object Files and Libraries to Create Executable
$(NAME): $(OBJS) $(MLX_A) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build libft Library
$(MLX_A):
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -s -C $(LIBMLX)/build -j4 > /dev/null 2>&1

# Compile Source Files into Object Files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(HEADERS) -c $< -o $@

# Create Object Directory
$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

# Clean Object Files and Dependency Files
clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files, dependency files, and $(OBJ_DIR) removed!"

# Clean Everything (Object Files and Executable)
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed!"

# Rebuild Project
re: fclean all

# Include Dependency Files
-include $(DEPS)

# Phony Targets
.PHONY: all clean fclean re