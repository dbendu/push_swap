c:
	@clear
	@gcc -Wall -Werror -Wextra *.c libft/libft.a -Ilibft/includes
	@./a.out

g:
	@clear
	@gcc -g -Wall -Werror -Wextra *.c libft/libft.a -Ilibft/includes

wc:
	@clear
	@gcc *.c libft/libft.a -Ilibft/includes
	@./a.out

wg:
	@clear
	@gcc -g *.c libft/libft.a -Ilibft/includes