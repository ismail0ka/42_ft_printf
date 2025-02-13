CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# Source files and object files
SRCS = ft_printf.c \
       ft_printf_utils/handle_format.c \
       ft_printf_utils/ft_put_unsigned_nbr.c \
       ft_printf_utils/ft_putptr.c \
       ft_printf_utils/ft_putstr.c \
       ft_printf_utils/ft_putchar.c \
       ft_printf_utils/ft_putnbr.c \
       ft_printf_utils/ft_strlen.c \
       ft_printf_utils/ft_puthex.c \
       ft_printf_utils/ft_strcpy.c 
OBJS = $(SRCS:.c=.o)

# Build the static library
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

# Generic rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the library
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re
