#include "push_swap.h"

static int	sort(t_stack **a, t_stack **b)
{
	int		is_cmd;
	char	*str;

	is_cmd = 0;
	while (get_next_line(0, &str) == 1)
	{
		is_cmd = 1;
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
	}
	return (is_cmd);
}

// static int	sort(t_stack **a, t_stack **b)
// {
// 	int		is_cmd;
// 	char	*str;

// 	is_cmd = 0;
// 	while (get_next_line(0, &str) == 1)
// 	{
// 		is_cmd = 1;
// 		if (!ft_strcmp(str, "ss"))
// 			swap_both(a, b, NULL);
// 		else if (*str == 's')
// 			str[1] == 'a' ? swap(a, NULL) : swap(b, NULL);
// 		else if (*str == 'p')
// 			str[1] == 'a' ? push(a, b, NULL) : push(b, a, NULL);
// 		else if (!ft_strcmp(str, "rrr"))
// 			rotate_both(a, b, NULL);
// 		else if (*str == 'r' && str[1] == 'r')
// 			str[2] == 'a' ? rev_rotate(a, NULL) : rev_rotate(b, NULL);
// 		else if (!ft_strcmp(str, "rr"))
// 			rev_rotate_both(a, b, NULL);
// 		else if (*str == 'r')
// 			str[1] == 'a' ? rotate(a, NULL) : rotate(b, NULL);





// 	}
// 	return (is_cmd);
// }



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

int			main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!argv[1] || !argc)
		return (0);
	if (!is_input_valid(argv) || !is_nums(argv))
		return (0);
	a = get_stack(argv);
	if (is_repeats(a))
	{
		lstpurge(&a);
		return (0);
	}
	b = NULL;
	if (sort(&a, &b))
		write(1, is_sorted(a, b) ? "OK\n" : "KO\n", 3);
	else if (!is_sorted(a, b))
		write(2, "Error\n", 6);
	lstpurge(&a);
	lstpurge(&b);
	return (0);
}
