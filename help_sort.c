/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:14:49 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 15:15:01 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_middle(t_stack *a_iter, int a_size, int b_value)
{
	int a_pos;
	int a_cur;

	a_pos = 1;
	a_cur = 0;
	while (a_iter->next)
	{
		if ((a_iter->value < b_value &&
			(a_iter->next->value > b_value ||
			a_iter->next->value < a_iter->value)) ||
			(a_iter->value > b_value &&
			a_iter->next->value > b_value &&
			a_iter->value > a_iter->next->value))
		{
			a_cur = a_pos <= a_size / 2 ? a_pos : -(a_size - a_pos);
			break ;
		}
		a_iter = a_iter->next;
		++a_pos;
	}
	return (a_cur);
}

static int	find_a_spins(t_stack *a, int b_value)
{
	if (a->tail->value > a->value &&
		(b_value > a->tail->value || b_value < a->value))
		return (0);
	else if (a->tail->value < a->value &&
			b_value < a->value && b_value > a->tail->value)
		return (0);
	return (check_middle(a, lstsize(a), b_value));
}

size_t		lstsize(const t_stack *stack)
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

void		find_best_spins(t_stack *a, t_stack *b, int *spins_a, int *spins_b)
{
	t_stack		*a_iter;
	int			b_size;
	int			b_pos;
	int			b_cur;
	int			a_cur;

	b_size = lstsize(b);
	*spins_a = MAX_INT;
	b_pos = -1;
	while (b)
	{
		b_cur = (++b_pos) <= b_size / 2 ? b_pos : -(b_size - b_pos);
		a_iter = a;
		a_cur = find_a_spins(a, b->value);
		if (*spins_a == MAX_INT ||
			ft_abs(a_cur) + ft_abs(b_cur) <
			ft_abs(*spins_a) + ft_abs(*spins_b))
		{
			*spins_a = a_cur;
			*spins_b = b_cur;
		}
		b = b->next;
	}
}
