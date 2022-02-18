HEAD = pipex.h 
NAME = pipex
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRCS = main.c parsing.c processes.c
OBJS = $(SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) $(LIBFT)
		gcc -o pipex $(OBJS) -L./libft -lft

$(LIBFT):
		$(MAKE) -C ./libft
		

%.o:	%.c $(HEAD)
			gcc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	
re: fclean all

