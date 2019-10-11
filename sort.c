#include "push_swap.h"

void	pre_sorting(t_stack **a, t_stack **b)
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
}

void	final_sort(t_stack **a)
{
	t_stack	*a_iter;
	size_t	a_size;
	int		gap_pos;

	if ((*a)->value < (*a)->tail->value)
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

void	primary_sort(t_stack **a, t_stack **b)
{
	int		v1;
	int		v2;
	int		v3;
	int		a_size;

	a_size = lstsize(*a);
	while (a_size > 3 && !ps_is_sorted(*a, NULL))
	{
		push(b, a, "pb\n");
		--a_size;
	}
	if (a_size < 3 || ps_is_sorted(*a, NULL))
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