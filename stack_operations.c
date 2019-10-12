/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:41:43 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 16:00:07 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int value)
{
	t_stack *elem;

	elem = (t_stack*)malloc(sizeof(t_stack));
	if (!elem)
		error(2, "The error occured while memory allocated", MALLOC_ERROR);
	elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;
	elem->tail = NULL;
	return (elem);
}

void	lstadd(t_stack **list, t_stack *elem)
{
	if (!list || !elem)
		return ;
	elem->prev = NULL;
	if (!*list)
	{
		elem->next = NULL;
		elem->tail = elem;
		*list = elem;
	}
	else
	{
		elem->next = *list;
		(*list)->prev = elem;
		elem->tail = (*list)->tail;
		*list = elem;
	}
}

void	lstpurge(t_stack **list)
{
	t_stack	*iter;
	t_stack	*temp;

	if (!list || !*list)
		return ;
	iter = *list;
	while (iter)
	{
		temp = iter->next;
		free(iter);
		iter = temp;
	}
	*list = NULL;
}

void	lstpop(t_stack **list)
{
	t_stack	*temp;

	if (!list || !*list)
		return ;
	if (!(*list)->next)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		(*list)->next->prev = NULL;
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}

void	lstpush(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else if (!(*stack)->tail)
	{
		(*stack)->tail = new;
		(*stack)->next = new;
		new->prev = (*stack);
	}
	else
	{
		(*stack)->tail->next = new;
		new->prev = (*stack)->tail;
		(*stack)->tail = new;
	}
}
