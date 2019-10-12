CHK_SRCS =	checker.c					\
			get_input1.c				\
			get_input2.c				\
			stack_operations.c			\
			help_sort.c					\
			ps_operations.c				\
			advanced_ps_operations.c

PS_SRCS =	push_swap.c					\
			sort.c						\
			help_sort.c					\
			get_input1.c				\
			get_input2.c				\
			stack_operations.c			\
			ps_operations.c				\
			advanced_ps_operations.c

CHK_OBJS =	$(CHK_SRCS:.c=.o)
PS_OBJS =	$(PS_SRCS:.c=.o)

all:
	@clear
	@make -C libft
	@gcc -Wall -Werror -Wextra $(CHK_SRCS) -c
	@gcc -Wall -Werror -Wextra $(CHK_SRCS) -Llibft -lft
	@clear
	@gcc -Wall -Werror -Wextra $(PS_SRCS) -Llibft -lft
	@clear

clean:
	@clear
	@make clean -C libft
	rm -f $(CHK_OBJS)
	rm -f $(PS_OBJS)
	@clear

fclean: clean
	@clear
	@make fclean -C libft
	@rm -f push_swap
	@rm -f checker
	@clear

re: fclean all
