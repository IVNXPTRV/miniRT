NAME := miniRT

CC := cc
CFLAGS := -Wall -Wextra -Werror -Wuninitialized -W -O2 -g3
RM := rm -rf

LIBFT := ./libs/libft
LIBMLX := ./libs/MLX42

# Linux
LIBS := $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# Mac
# LIBS := $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -L/opt/homebrew/lib -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

HEADERS := \
	includes/camera.h \
	includes/color.h \
	includes/constants.h \
	includes/data.h \
	includes/hit_record.h \
	includes/mini_rt.h \
	includes/object.h \
	includes/parser.h \
	includes/ray.h \
	includes/vector3.h \
	includes/world.h \

SRCS := \
	srcs/color/color_create.c \
	srcs/color/color_get.c \
	srcs/color/color_operation.c \
	\
	srcs/display/closing.c \
	srcs/display/init_display.c \
	srcs/display/modify_camera.c \
	\
	srcs/parser/objects/parse_ambient.c \
	srcs/parser/objects/parse_camera.c \
	srcs/parser/objects/parse_light.c \
	srcs/parser/objects/parse_cylinder.c \
	srcs/parser/objects/parse_plane.c \
	srcs/parser/objects/parse_sphere.c \
    srcs/parser/objects/parse_utils.c \
	srcs/parser/utils/array_utils.c \
	srcs/parser/utils/identify_scene_type.c \
	srcs/parser/utils/print_error.c \
	srcs/parser/validation/is_in_range.c \
	srcs/parser/validation/parse_vector3.c \
	srcs/parser/validation/validate_number.c \
	srcs/parser/validation/validate_triplet.c \
	srcs/parser/load_file_into_memory.c \
	srcs/parser/parse_scene.c \
	srcs/parser/read_file_to_world.c \
	srcs/parser/validate_scene.c \
	\
	srcs/renderer/objects/hit_cylinder.c \
	srcs/renderer/objects/hit_plane.c \
	srcs/renderer/objects/hit_sphere.c \
	srcs/renderer/configure_camera.c \
	srcs/renderer/is_ray_hit.c \
	srcs/renderer/ray_color.c \
	srcs/renderer/ray_at.c \
	srcs/renderer/render_image.c \
	srcs/renderer/hit_record.c \
	\
	srcs/vector3/vector3_create.c srcs/vector3/vector3_put.c \
	srcs/vector3/vector3_add.c srcs/vector3/vector3_mul.c \
	srcs/vector3/vector3_dot.c srcs/vector3/vector3_dist.c \
	srcs/vector3/vector3_norm.c srcs/vector3/vector3_normalize.c \
	srcs/vector3/vector3_cross.c srcs/vector3/vector3_proj.c \
	srcs/vector3/vector3_rotate.c \
	\
	srcs/main.c

OBJS := $(SRCS:%.c=%.o)


all: libft libmlx $(NAME)

libft: $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	$(RM) $(LIBMLX)/build
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft, libmlx
