/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:17:17 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 15:17:26 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			*get_arr(const t_stack *stack, size_t stack_size)
{
	int		*arr;
	size_t	pos;

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

int			check_symbols(const char *str)
{
	const char	*str_begin;
	__int128_t	value;

	str_begin = str;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' &&
			!ft_isspace(*str) && *str != '+')
			return (0);
		if ((*str == '-' || *str == '+') &&
			(!ft_isdigit(str[1]) ||
			(str != str_begin && !ft_isspace(str[-1]))))
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
	return (1);
}

int			is_input_valid(const char **argv)
{
	const char	**iter;

	iter = argv + 1;
	while (*iter)
	{
		if (!check_symbols(*iter))
			return (0);
		++iter;
	}
	return (1);
}
