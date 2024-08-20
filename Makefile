# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albertini <albertini@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 12:52:36 by falberti          #+#    #+#              #
#    Updated: 2024/08/20 17:22:25 by albertini        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR = srcs
LIBRARIES_DIR = includes

HEADER = $(LIBRARIES_DIR)
# HEADER = $(LIBRARIES_DIR)/cub3d.h

FILES = $(SOURCES_DIR)/cub3d\
		$(SOURCES_DIR)/display\
		$(SOURCES_DIR)/init\


## Ajout de .c et .o aux fichiers dans FILES
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments MACOS
CC = gcc
CFLAGS = -Werror -Wextra -Wall -DGL_SILENCE_DEPRECATION -I $(HEADER) -Imlx -g
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

## Varguments Linux
# CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -I/usr/include -Imlx_linux -O3 -g
# LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

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
$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C includes/libft_xl clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C includes/libft_xl fclean
	rm -f $(NAME)

re: fclean all
