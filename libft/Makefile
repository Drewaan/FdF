NAME := libft.a
CC := gcc
FLAGS := -Wall -Wextra -Werror

SRCS := ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memmove.c \
        ft_memset.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_striteri.c \
        ft_strlcat.c \
        ft_strlcpy.c \
        ft_strlen.c \
        ft_strncmp.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_atoi.c \
        ft_bzero.c \
        ft_calloc.c \
        ft_putchar_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_putstr_fd.c \
        ft_memcpy.c \
        ft_strjoin.c \
        ft_strdup.c \
        ft_substr.c \
        ft_strmapi.c \
        ft_itoa.c \
        ft_strtrim.c \
        ft_strnstr.c \
        ft_itoa.c \
        ft_split.c \
        ft_lstnew_bonus.c \
        ft_lstadd_front_bonus.c \
        ft_lstsize_bonus.c \
        ft_lstlast_bonus.c \
        ft_lstadd_back_bonus.c \
        ft_lstdelone_bonus.c\
        ft_lstclear_bonus.c \
        ft_lstiter_bonus.c \
        ft_print_pointer.c \
        ft_printf.c \
        ft_atoi_base.c\
        ft_strcmp.c \
        print_utils.c \
        get_next_line.c \
        get_next_line_utils.c \

OBJS := $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

CLR_RMV := \033[0m
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m
CYAN := \033[1;36m
RM := rm -f

$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	$(AR) rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created$(CLR_RMV) ✔️"

all: $(NAME)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re
