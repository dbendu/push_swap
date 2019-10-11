#include "push_swap.h"




int		final_sort(t_stack **a)
{
	int opers = 0;
	t_stack *a_iter;
	size_t a_size;
	size_t gap_pos;

	if ((*a)->value < (*a)->tail->value)
		return (0);
	a_size = lstsize(*a);
	a_iter = *a;
	gap_pos = 1;
	while (a_iter->next && a_iter->value < a_iter->next->value)
	{
		++gap_pos;
		a_iter = a_iter->next;
	}
	if (gap_pos <= a_size / 2)
		while (gap_pos)
		{
			++opers;
			rotate(a, "ra\n");
			--gap_pos;
		}
	else
	{
		gap_pos = a_size - gap_pos;
		while (gap_pos)
		{
			++opers;
			rev_rotate(a, "rra\n");
			--gap_pos;
		}
	}
	return (opers);
}





void	primary_sort(t_stack **ast, t_stack **bst)
{
	int		a;
	int		b;
	int		c;
	int		a_size;

	a_size = lstsize(*ast);
	while (a_size > 3 && !ps_is_sorted(*ast, NULL))
	{
		push(bst, ast, "pb\n");
		--a_size;
	}
	if (a_size < 3 || ps_is_sorted(*ast, NULL))
		return ;
	a = (*ast)->value;
	b = (*ast)->next->value;
	c = (*ast)->next->next->value;
	if ((a < b && a < c && b > c) ||
		(a > b && a < c && b < c) ||
		(a > b && a > c && b > c))
		swap(ast, "sa\n");
	return ;
}

void find_best_spins(t_stack *a, t_stack *b, int *spins_a, int *spins_b)
{
	int a_size;
	int b_size;
	int b_pos;
	int a_pos;
	int b_cur;
	int a_cur;
	t_stack *a_iter;

	a_size = lstsize(a);
	b_size = lstsize(b);
	*spins_a = MAX_INT;
	b_pos = 0;
	while (b)
	{
		b_cur = b_pos <= b_size / 2 ? b_pos : -(b_size - b_pos);
		a_iter = a;
		if (a->tail->value > a->value && (b->value > a->tail->value || b->value < a->value))
			a_cur = 0;
		else if (a->tail->value < a->value && b->value < a->value && b->value > a->tail->value)
			a_cur = 0;
		else
		{
			a_pos = 1;
			while (a_iter->next)
			{
				if ((a_iter->value < b->value && (a_iter->next->value > b->value || a_iter->next->value < a_iter->value)) ||
					(a_iter->value > b->value && a_iter->next->value > b->value && a_iter->value > a_iter->next->value))
				{
					a_cur = a_pos <= a_size / 2 ? a_pos : -(a_size - a_pos);
					break;
				}
				a_iter = a_iter->next;
				++a_pos;
			}
		}
		if (*spins_a == MAX_INT || ft_abs(a_cur) + ft_abs(b_cur) < ft_abs(*spins_a) + ft_abs(*spins_b))
		{
			*spins_a = a_cur;
			*spins_b = b_cur;
		}
		b = b->next;
		++b_pos;
	}
}

void		main_sort(t_stack **a, t_stack **b)
{
	int spin_a;
	int spin_b;

	while (!ps_is_sorted(*a, *b))
	{
		find_best_spins(*a, *b, &spin_a, &spin_b);
		while (spin_a < 0 && spin_b < 0)
		{
			rev_rotate_both(a, b, "rrr\n");
			++spin_a;
			++spin_b;
		}
		while (spin_a > 0 && spin_b > 0)
		{
			rotate_both(a, b, "rr\n");
			--spin_a;
			--spin_b;
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
	return ;
}



void pre_sorting(t_stack **a, t_stack **b)
{
	size_t a_size;
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

void	sort(t_stack **a)
{
	t_stack *b;

	b = NULL;
	if (lstsize(*a) > 150)
		pre_sorting(a, &b);
	primary_sort(a, &b);
	main_sort(a, &b);
	final_sort(a);
}

int main(int argc, const char **argv)
{
	t_stack *a;

	if (argc == 1)
		return (0);
	if (is_input_valid(argv))
	{
		if (is_nums(argv))
		{
			a = get_stack(argv);
			if (is_repeats(a))
				error(2, "Error", 0);
			sort(&a);
		}
	}
	else
		error(2, "Error\n", 0);
	return (0);
}
