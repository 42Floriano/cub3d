# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 12:52:36 by falberti          #+#    #+#              #
#    Updated: 2024/09/17 13:29:31 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR = srcs
LIBRARIES_DIR = includes
OBJ_DIR = obj

HEADER = $(LIBRARIES_DIR)
# HEADER = $(LIBRARIES_DIR)/cub3d.h

FILES = $(SOURCES_DIR)/cub3d\
		$(SOURCES_DIR)/display\
		$(SOURCES_DIR)/display_utils\
		$(SOURCES_DIR)/init\
		$(SOURCES_DIR)/clean_exit\
		$(SOURCES_DIR)/read_map\
		$(SOURCES_DIR)/commands\
		$(SOURCES_DIR)/commands_moves\
		$(SOURCES_DIR)/fps_display\
		$(SOURCES_DIR)/textures\
		$(SOURCES_DIR)/display_textures\


## Ajout de .c et .o aux fichiers dans FILES
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(patsubst $(SOURCES_DIR)/%.c, $(OBJ_DIR)/%.o, $(CFILES))

####################################################################
UNAME := $(shell uname)
CC = gcc
NAME = cub3d


ifeq ($(UNAME), Darwin)
# macOS-specific settings
CFLAGS = -Werror -Wextra -Wall -DGL_SILENCE_DEPRECATION -I $(HEADER) -Imlx -g
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
else ifeq ($(UNAME), Linux)
# Linux-specific settings
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -I/usr/include -Imlx_linux -O3 -g
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif
#####################################################################
## Rules

LIBFTXL = includes/libft_xl/libftxl.a

all: $(NAME)

$(LIBFTXL):
	$(MAKE) -C includes/libft_xl

## -fsanitize=address
$(NAME): $(OFILES) $(LIBFTXL)
	$(CC) $(OFILES) $(LIBFTXL) $(LDFLAGS) -o $(NAME)

### For each .o file it needs the .c file | $< is automatic var that takes the param and $@ the target
$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C includes/libft_xl clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C includes/libft_xl fclean
	rm -f $(NAME)

re: fclean all