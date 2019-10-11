#include "push_swap.h"

int ps_is_sorted(t_stack *a, t_stack *b)
{
	t_stack	*a_iter;
	int		is_gap;

	if (b)
		return (0);
	is_gap = 0;
	a_iter = a;
	while (a_iter->next)
	{
		if (a_iter->value > a_iter->next->value)
		{
			if (is_gap)
				return (0);
			else
				is_gap = 1;
		}
		a_iter = a_iter->next;
	}
	if (is_gap && a->value < a_iter->value)
		return (0);
	return (1);
}

t_stack		*get_stack(const char **argv)
{
	t_stack		*stack;

	stack = NULL;
	++argv;
	while (*argv)
	{
		while (**argv && ft_isspace(**argv))
			++*argv;
		if (**argv)
		{
			lstpush(&stack, lstnew(ft_atoi(*argv)));
			while (ft_isdigit(**argv))
				++*argv;
		}
		if (!**argv)
			++argv;
	}
	return (stack);
}

int is_repeats(const t_stack *a)
{
	size_t	a_size;
	size_t	iter;
	int		*arr;
	
	a_size = lstsize(a);
	arr = get_arr(a, a_size);
	sort_array(arr, a_size);
	iter = 0;
	while (iter < a_size - 1)
	{
		if (arr[iter] == arr[iter + 1])
			return (1);
		++iter;
	}
	free(arr);
	return (0);
}

int is_input_valid(const char **argv)
{
	const char	**iter;
	const char	*str;
	__int128_t	value;

	iter = argv + 1;
	while (*iter)
	{
		str = *iter;
		while (*str)
		{
			if (!ft_isdigit(*str) && *str != '-' &&
				!ft_isspace(*str) && *str != '+')
				return (0);
			if ((*str == '-' || *str == '+') &&
				(!ft_isdigit(str[1]) || (str != *iter && !ft_isspace(str[-1]))))
				return (0);
			if (ft_isdigit(*str))
			{
				value = ft_atoi(str);
				if (value > MAX_INT || value < MIN_INT)
					return (0);
				while (ft_isdigit(str[1]))
					++str;
			}
			++str;
		}
		++iter;
	}
	return (1);
}


int is_nums(const char **argv)
{
	const char	*str;
	const char	**iter;

	iter = argv + 1;
	while (*iter)
	{
		str = *iter;
		while (*str)
		{
			if (ft_isdigit(*str))
				return (1);
			++str;
		}
		++iter;
	}
	return (0);
}

void sort_array(int *arr, size_t size)
{
	size_t	min;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			++j;
		}
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		++i;
	}
}

int *get_arr(const t_stack *stack, size_t stack_size)
{
	int *arr;
	size_t pos;

	arr = (int*)malloc(sizeof(int) * stack_size);
	pos = 0;
	while (stack)
	{
		arr[pos] = stack->value;
		stack = stack->next;
		++pos;
	}
	return (arr);
}

size_t lstsize(const t_stack *stack)
{
	size_t size;

	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}