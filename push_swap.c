/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:40:40 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 15:10:27 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		main(int argc, const char **argv)
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
