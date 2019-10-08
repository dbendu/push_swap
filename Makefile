CHK_SRCS =	checker.c					\
			ps_operations.c				\
			advanced_ps_operations.c	\
			stack_operations.c			\
			libft/libft.a				\
			-Ilibft/includes

PS_SRCS =	push_swap.c					\
			ps_operations.c				\
			advanced_ps_operations.c	\
			stack_operations.c			\
			libft/libft.a				\
			-Ilibft/includes

c:
	@clear
	@gcc -g -Wall -Werror -Wextra $(CHK_SRCS) -o checker
	@clear

p:
	@clear
	@gcc -g -Wall -Werror -Wextra $(PS_SRCS) -o push_swap
	@clear



wc:
	@clear
	@gcc -g $(CHK_SRCS) -o checker
	@clear

p:
	@clear
	@gcc -g $(PS_SRCS) -o push_swap
	@clear