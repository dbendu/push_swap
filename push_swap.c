#include "push_swap.h"





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
