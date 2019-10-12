/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:48:14 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:59:30 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_another(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "rb"))
		rotate(b, NULL);
	else if (!ft_strcmp(str, "rr"))
		rotate_both(a, b, NULL);
	else if (!ft_strcmp(str, "rra"))
		rev_rotate(a, NULL);
	else if (!ft_strcmp(str, "rrb"))
		rev_rotate(b, NULL);
	else if (!ft_strcmp(str, "rrr"))
		rev_rotate_both(a, b, NULL);
	else
		return (INVALID_CMD);
	return (NORM);
}

static int	sort(t_stack **a, t_stack **b)
{
	int		cmd;
	char	*str;

	cmd = NO_CMDS;
	while (cmd != INVALID_CMD && get_next_line(0, &str) == 1)
	{
		cmd = NORM;
		if (!ft_strcmp(str, "sa"))
			swap(a, NULL);
		else if (!ft_strcmp(str, "sb"))
			swap(b, NULL);
		else if (!ft_strcmp(str, "ss"))
			swap_both(a, b, NULL);
		else if (!ft_strcmp(str, "pa"))
			push(a, b, NULL);
		else if (!ft_strcmp(str, "pb"))
			push(b, a, NULL);
		else if (!ft_strcmp(str, "ra"))
			rotate(a, NULL);
		else
			cmd = check_another(str, a, b);
		free(str);
	}
	return (cmd);
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

static void	print_res(int ret, t_stack *a, t_stack *b)
{
	if (ret == NO_CMDS)
	{
		if (is_sorted(a, b))
			write(1, "OK\n", 3);
		else
			write(2, "Error\n", 6);
	}
	else if (ret == NORM)
		write(1, is_sorted(a, b) ? "OK\n" : "KO\n", 3);
	else
		write(1, "Error\n", 6);
}

int			main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ret;

	if (!argv[1] || !argc)
		return (0);
	if (!is_input_valid(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!is_nums(argv))
		return (0);
	if (is_repeats((a = get_stack(argv))))
	{
		write(2, "Error\n", 6);
		lstpurge(&a);
		return (0);
	}
	b = NULL;
	ret = sort(&a, &b);
	print_res(ret, a, b);
	lstpurge(&a);
	lstpurge(&b);
	return (0);
}
