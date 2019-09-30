#include "push_swap.h"

# define DO_N(a, n)	\
	({						\
		int n_cp = n;		\
		while (n_cp--)		\
			(a);			\
	})

void	print_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
			printf("%3d ", a->value);
		else
			printf("    ");
		if (b)
			printf("%3d\n", b->value);
		else
			printf("   \n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("--- ---\n a   b \n");
}

t_stack *find_min(t_stack *stack, size_t n, size_t *pos)
{
	t_stack	*min;
	size_t	cur_pos;

	cur_pos = 0;
	*pos = 0;
	min = stack;
	while (n--)
	{
		if (stack->value < min->value)
		{
			min = stack;
			*pos = cur_pos;
		}
		++cur_pos;
		stack = stack->next;
	}
	return (min);
}

int is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->next && stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

size_t sort(t_stack **a, t_stack **b)
{
	static int iter = 0;
	++iter;
	t_stack *min;
	t_stack *cur_min;
	size_t	a_size;
	size_t	pos;
	size_t	see;

	size_t operations = 0;

	a_size = lstsize(*a);
	see = a_size;
	min = (*a)->tail;
	while (!is_sorted(*a))
	{
		cur_min = find_min(*a, see, &pos);
		if (pos << 1 > a_size)
			DO_N(rev_rotate(a), a_size - pos);
		else
			DO_N(rotate(a), pos);
		operations += (pos << 1 > a_size ? a_size - pos : pos);
		push(b, a);
		++operations;
		if (pos << 1 > a_size)
			DO_N(rotate(a), a_size - pos);
		else
			DO_N(rev_rotate(a), pos);
		operations += (pos << 1 > a_size ? a_size - pos : pos);
		push(a, b);
		rotate(a);
		operations += 2;
		--see;
		// print_stacks(*a, *b);
	}
	return (operations);
}

int	main(void)
{
	t_stack *a;
	t_stack *b;
	
	a = NULL;
	lstadd(&a, lstnew(8));
	lstadd(&a, lstnew(5));
	lstadd(&a, lstnew(6));
	lstadd(&a, lstnew(2));
	lstadd(&a, lstnew(1));
	lstadd(&a, lstnew(3));

	b = NULL;

	print_stacks(a, b);

	size_t res = sort(&a, &b);

	write(1, "\n", 1);
	print_stacks(a, b);

	printf("\n\nres: %zu\n", res);
	
	return (0);
}