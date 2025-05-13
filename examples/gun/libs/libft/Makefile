# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 13:18:31 by nteechar          #+#    #+#              #
#    Updated: 2025/03/26 09:56:20 by nteechar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

# colors
RED := \033[31m
GREEN := \033[32m
RESET := \033[0m

# commands
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf
AR := ar rcs

# files
HEADERS := libft.h \
	conversion/conversion.h \
	ft_printf/ft_printf.h \
	ft_string/ft_string.h \
	get_next_line/get_next_line.h \
	list/list.h list/t_list.h \
	memory/memory.h \
	putting/putting.h \
	type_check/type_check.h \

SRCS := \
	conversion/ft_atoi.c conversion/ft_tolower.c \
	conversion/ft_itoa.c conversion/ft_toupper.c conversion/ft_atof.c \
	conversion/ft_strtod.c conversion/ft_strtol.c \
	\
	ft_printf/ft_printf.c \
	ft_printf/put_address.c ft_printf/put_char.c ft_printf/put_hex.c \
	ft_printf/put_int.c ft_printf/put_str.c ft_printf/put_unsigned_int.c \
	ft_printf/put_double.c \
	\
	ft_string/ft_split.c ft_string/ft_strchr.c ft_string/ft_strcmp.c \
	ft_string/ft_strdup.c ft_string/ft_striteri.c ft_string/ft_strjoin_all.c \
	ft_string/ft_strjoin.c ft_string/ft_strlcat.c ft_string/ft_strlcpy.c \
	ft_string/ft_strlen.c ft_string/ft_strmapi.c ft_string/ft_strncmp.c \
	ft_string/ft_strnstr.c ft_string/ft_strrchr.c ft_string/ft_strtok.c \
	ft_string/ft_strtrim.c ft_string/ft_substr.c ft_string/ft_free_str_arr.c \
	\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	\
	list/ft_lstadd_back.c list/ft_lstadd_front.c list/ft_lstclear.c \
	list/ft_lstdelone.c list/ft_lstfirst.c list/ft_lstiter.c \
	list/ft_lstlast.c list/ft_lstmap.c list/ft_lstnew_add_back.c \
	list/ft_lstnew_add_front.c list/ft_lstnew.c list/ft_lstsize.c \
	list/ft_lstdel_front.c \
	\
	memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c \
	memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c \
	memory/ft_memset.c \
	\
	putting/ft_putchar_fd.c putting/ft_putendl_fd.c \
	putting/ft_putnbr_fd.c putting/ft_putstr_fd.c \
	\
	type_check/ft_isalnum.c type_check/ft_isalpha.c type_check/ft_isascii.c \
	type_check/ft_isdigit.c type_check/ft_isinset.c type_check/ft_islower.c \
	type_check/ft_isprint.c type_check/ft_isspace.c type_check/ft_isupper.c

OBJS := $(SRCS:%.c=%.o)

# phony rules
.PHONY: all clean fclean re

all: $(NAME)

clean:
	@echo "$(RED)> delete libft's .o files$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)> delete libft.a$(RESET)"
	@$(RM) $(NAME)

re: fclean all

# rules
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
