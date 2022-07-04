HEAD = pipex.h
HEAD_B = pipex_bonus.h 
NAME = pipex
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRCS = main.c parsing.c processes.c
SRCS_B = main_bonus.c parsing_bonus.c processes_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) $(LIBFT)
		cc -o pipex $(OBJS) -L./libft -lft

$(LIBFT):
		$(MAKE) -C ./libft

bonus: ${OBJS_B} $(HEAD_B) $(LIBFT)
	cc -o pipex $(OBJS_B) -L./libft -lft

%.o:	%.c $(HEAD) $(HEAD_B)
			cc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	
re: fclean all

