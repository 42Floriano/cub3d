FILES = ft_atoi\
            ft_bzero\
            ft_calloc\
            ft_isalnum\
            ft_isalpha\
            ft_isascii\
            ft_isdigit\
            ft_isprint\
            ft_itoa\
            ft_memchr\
            ft_memcmp\
            ft_memcpy\
            ft_memmove\
            ft_memset\
            ft_putchar_fd\
            ft_putendl_fd\
            ft_putnbr_fd\
            ft_putstr_fd\
            ft_split\
            ft_strchr\
            ft_strdup\
            ft_striteri\
            ft_strjoin\
            ft_strlcat\
            ft_strlcpy\
            ft_strlen\
            ft_strmapi\
            ft_strncmp\
            ft_strnstr\
            ft_strrchr\
            ft_strtrim\
            ft_substr\
            ft_tolower\
            ft_toupper\
            get_next_line\
            get_next_line_utils\
			ft_print_int\
			ft_printf_classic\
			ft_printf\
			ft_print_ptr\
			ft_print_hexa\
			ft_print_unsigned\
			ft_lstadd_back\
			ft_lstadd_front\
			ft_lstclear\
			ft_lstdelone\
			ft_lstlast\
			ft_lstnew\
			ft_lstsize\

			
CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Target library
NAME = libftxl.a

# Build rule for the library
all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $@ $(OFILES)

# Build rule for object files
$(FILES).o: $(FILES).c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	@rm -f $(OFILES)

# Full clean rule to remove object files and the library
fclean: clean
	@rm -f $(NAME)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re bonus