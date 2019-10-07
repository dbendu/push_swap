#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(0, "rr\n", 3);
}

void	rev_rotate_both(t_stack **a, t_stack **b)
{
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	write(0, "rrr\n", 4);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
	write(0, "ss\n", 3);
}
