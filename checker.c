#include "push_swap.h"

static int	is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack		*get_stack(const char **argv)
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

int			sort(t_stack **a, t_stack **b)
{
	char	*str;
	int		opers;

	opers = 0;
	while (get_next_line(0, &str) == 1)
	{
		if (!ft_strcmp(str, "sa"))
			swap(a, NULL);
		else if (!ft_strcmp(str, "sb"))
			swap(b, NULL);
		else if (!ft_strcmp(str, "ss"))
			swap_both(a, b);
		else if (!ft_strcmp(str, "pa"))
			push(a, b, NULL);
		else if (!ft_strcmp(str, "pb"))
			push(b, a, NULL);
		else if (!ft_strcmp(str, "ra"))
			rotate(a, NULL);
		else if (!ft_strcmp(str, "rb"))
			rotate(b, NULL);
		else if (!ft_strcmp(str, "rr"))
			rotate_both(a, b);
		else if (!ft_strcmp(str, "rra"))
			rev_rotate(a, NULL);
		else if (!ft_strcmp(str, "rrb"))
			rev_rotate(b, NULL);
		else if (!ft_strcmp(str, "rrr"))
			rev_rotate_both(a, b);
		++opers;
	}
	return (opers);
}

int			main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		opers;

	if (!argv[1] || !argc)
		return (0);
	a = get_stack(argv);
	b = NULL;
	opers = sort(&a, &b);
	printf("%d\n", opers);
	if (is_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lstpurge(&a);
	lstpurge(&b);
	return (0);
}
