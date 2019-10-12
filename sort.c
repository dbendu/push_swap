/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:06:09 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:38:59 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pre_sorting(t_stack **a, t_stack **b)
{
	size_t	a_size;
	int		*arr;

	a_size = lstsize(*a);
	arr = get_arr(*a, a_size);
	sort_array(arr, a_size);
	*b = NULL;
	while (lstsize(*b) < a_size / 3)
	{
		if ((*a)->value < arr[a_size / 3])
			push(b, a, "pb\n");
		else
			rotate(a, "ra\n");
	}
	while (lstsize(*b) < a_size / 3 * 2)
	{
		if ((*a)->value < arr[a_size / 3 * 2])
			push(b, a, "pb\n");
		else
			rotate(a, "ra\n");
	}
	free(arr);
}

void		final_sort(t_stack **a)
{
	t_stack	*a_iter;
	int		a_size;
	int		gap_pos;

	if (!((*a)->next) || (*a)->value < (*a)->tail->value)
		return ;
	a_size = lstsize(*a);
	a_iter = *a;
	gap_pos = 1;
	while (a_iter->next && a_iter->value < a_iter->next->value)
	{
		++gap_pos;
		a_iter = a_iter->next;
	}
	gap_pos = gap_pos <= a_size / 2 ? gap_pos : gap_pos - a_size;
	while (gap_pos)
	{
		gap_pos > 0 ? rotate(a, "ra\n") : rev_rotate(a, "rra\n");
		gap_pos += gap_pos > 0 ? -1 : 1;
	}
}

static int	is_sorted(t_stack *a, t_stack *b)
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

void		primary_sort(t_stack **a, t_stack **b)
{
	int		v1;
	int		v2;
	int		v3;
	int		a_size;

	a_size = lstsize(*a);
	while (a_size > 3 && !is_sorted(*a, NULL))
	{
		push(b, a, "pb\n");
		--a_size;
	}
	if (a_size < 3 || is_sorted(*a, NULL))
		return ;
	v1 = (*a)->value;
	v2 = (*a)->next->value;
	v3 = (*a)->next->next->value;
	if ((v1 < v2 && v1 < v3 && v2 > v3) ||
		(v1 > v2 && v1 < v3 && v2 < v3) ||
		(v1 > v2 && v1 > v3 && v2 > v3))
		swap(a, "sa\n");
	return ;
}

void		main_sort(t_stack **a, t_stack **b)
{
	int spin_a;
	int spin_b;

	while (!is_sorted(*a, *b))
	{
		find_best_spins(*a, *b, &spin_a, &spin_b);
		while ((spin_a > 0 && spin_b > 0) || (spin_a < 0 && spin_b < 0))
		{
			spin_a > 0 ? rotate_both(a, b, "rr\n") :
						rev_rotate_both(a, b, "rrr\n");
			spin_a += spin_a > 0 ? -1 : 1;
			spin_b += spin_b > 0 ? -1 : 1;
		}
		while (spin_a)
		{
			spin_a > 0 ? rotate(a, "ra\n") : rev_rotate(a, "rra\n");
			spin_a += spin_a > 0 ? -1 : 1;
		}
		while (spin_b)
		{
			spin_b > 0 ? rotate(b, "rb\n") : rev_rotate(b, "rrb\n");
			spin_b += spin_b > 0 ? -1 : 1;
		}
		push(a, b, "pa\n");
	}
}
