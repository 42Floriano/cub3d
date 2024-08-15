# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albertini <albertini@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 12:52:36 by falberti          #+#    #+#              #
#    Updated: 2024/08/15 13:41:22 by albertini        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR = srcs
LIBRARIES_DIR = includes

HEADER = $(LIBRARIES_DIR)/cub3d.h

FILES = $(SOURCES_DIR)/cub3d\

## Ajout de .c et .o aux fichiers dans FILES
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -Imlx -g
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

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
