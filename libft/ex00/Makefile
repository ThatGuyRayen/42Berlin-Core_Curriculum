NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = srcs/
SRC_NAMES = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_iswhitespace.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_nbdigits.c \
			ft_nbdigits_base.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAMES))
OBJ_DIR = objs/
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

HDR_NAMES = libft.h
HDR_DIR = includes/
HDRS = $(addprefix $(HDR_DIR),$(HDR_NAMES))

HDR_INC = $(addprefix -I./, $(HDR_DIR))

all: $(NAME) $(HDRS)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDRS)
	@ar rc $@ $(OBJS)
	@ranlib $@

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDRS)
	@$(CC) $(CFLAGS) $(HDR_INC) -c $< -o $@

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re project
