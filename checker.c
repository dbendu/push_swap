#include "push_swap.h"

int		is_sorted(t_stack *stack)
{
	t_stack	*line;
	int		less;

	less = (stack->tail->value > stack->value);
	while (stack)
	{
		if (stack->next && stack->value > stack->next->value)
		{
			if (less)
				return (0);
			else
				less = 1;
		}
		stack = stack->next;
	}
	return (1);
}

t_stack	*get_stack(const char **argv)
{
	t_stack		*stack;
	long int	elem;

	stack = NULL;
	++argv;
	while (*argv)
	{
		elem = ft_atoi(*argv);
		lstpush(&stack, lstnew(elem));
		++argv;
	}
	return (stack);
}

int main(int argc, const char **argv)
{
	t_stack *stack;

	if (!argv[1] || !argc)
		return (0);
	stack = get_stack(argv);
	if (!stack)
		error(2, "Error", BASE_ERROR);
	if (is_sorted(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	return (0);
}