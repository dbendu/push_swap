/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:18:23 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 15:29:09 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*tail;
}					t_stack;

/*
**	stacks actions
*/

t_stack				*lstnew(int value);
void				lstpurge(t_stack **list);
void				lstpop(t_stack **list);
void				lstadd(t_stack **list, t_stack *elem);
void				lstpush(t_stack **stack, t_stack *new);
size_t				lstsize(const t_stack *stack);

/*
**	ps operations
*/

void				swap(t_stack **list, char *msg);
void				push(t_stack **to, t_stack **from, char *msg);
void				rotate(t_stack **list, char *msg);
void				rev_rotate(t_stack **list, char *msg);
void				rotate_both(t_stack **a, t_stack **b, char *msg);
void				rev_rotate_both(t_stack **a, t_stack **b, char *msg);
void				swap_both(t_stack **a, t_stack **b, char *msg);

/*
**	check input
*/

t_stack				*get_stack(const char **argv);
int					*get_arr(const t_stack *stack, size_t stack_size);
int					is_repeats(const t_stack *a);
int					is_input_valid(const char **argv);
int					is_nums(const char **argv);
void				sort_array(int *arr, size_t size);

/*
**	stack sorting
*/

void				pre_sorting(t_stack **a, t_stack **b);
void				final_sort(t_stack **a);
void				primary_sort(t_stack **a, t_stack **b);
void				main_sort(t_stack **a, t_stack **b);
void				find_best_spins(t_stack *a, t_stack *b,
									int *spins_a, int *spins_b);

#endif
