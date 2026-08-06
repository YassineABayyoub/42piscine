SRC     = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

PRE     = ./srcs/
HEAD    = ./includes/

SRCS    = $(addprefix $(PRE),$(SRC))
OBJS    = $(SRCS:.c=.o)

NAME    = libft.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

AR      = ar rc
RANLIB  = ranlib
RM      = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
