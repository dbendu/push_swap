#include "push_swap.h"

int	ps_atoi(const char **str)
{
	long long int	res;
	short int		sign;

	while (**str && ft_isspace(**str))
		++*str;
	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		++*str;
	}
	else if (**str == '+')
		++*str;
	res = 0;
	while (**str && ft_isdigit(**str))
	{
		res = res * 10 + **str - '0';
		++*str;
	}
	return (res * sign);
}


t_stack		*get_stack(const char **argv)
{
	t_stack		*stack;
	long int	elem;

	stack = NULL;
	++argv;
	while (*argv)
	{
		elem = ps_atoi(argv);
		lstpush(&stack, lstnew(elem));
		if (!**argv)
			++argv;
	}
	return (stack);
}

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

int			sort(t_stack **a, t_stack **b)
{
	int		opers;
	char	*str;

	opers = 0;
	while (get_next_line(0, &str) == 1)
	{
		if (!ft_strcmp(str, "sa"))
			swap(a, NULL);
		else if (!ft_strcmp(str, "sb"))
			swap(b, NULL);
		else if (!ft_strcmp(str, "ss"))
			swap_both(a, b, "ss\n");
		else if (!ft_strcmp(str, "pa"))
			push(a, b, NULL);
		else if (!ft_strcmp(str, "pb"))
			push(b, a, NULL);
		else if (!ft_strcmp(str, "ra"))
			rotate(a, NULL);
		else if (!ft_strcmp(str, "rb"))
			rotate(b, NULL);
		else if (!ft_strcmp(str, "rr"))
			rotate_both(a, b, NULL);
		else if (!ft_strcmp(str, "rra"))
			rev_rotate(a, NULL);
		else if (!ft_strcmp(str, "rrb"))
			rev_rotate(b, NULL);
		else if (!ft_strcmp(str, "rrr"))
			rev_rotate_both(a, b, NULL);
		++opers;
	}
	return (opers);
}

int			main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!argv[1] || !argc)
		return (0);
	a = get_stack(argv);
	b = NULL;
	printf("%d\n", sort(&a, &b));
	t_stack * iter = a;
	while (iter)
	{
		printf("%3d ", iter->value);
		iter = iter->next;
	}
	if (is_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lstpurge(&a);
	lstpurge(&b);
	return (0);
}
