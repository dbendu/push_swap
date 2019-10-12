/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_ps_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:16:45 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 15:16:47 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, char *msg)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (msg)
		write(1, msg, 3);
}

void	rev_rotate_both(t_stack **a, t_stack **b, char *msg)
{
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	if (msg)
		write(1, msg, 4);
}

void	swap_both(t_stack **a, t_stack **b, char *msg)
{
	swap(a, NULL);
	swap(b, NULL);
	if (msg)
		write(1, msg, 3);
}
