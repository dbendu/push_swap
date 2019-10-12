/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:41:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 14:41:22 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list, char *msg)
{
	int	temp;

	if (!list || !*list || !(*list)->next)
		return ;
	temp = (*list)->value;
	(*list)->value = (*list)->next->value;
	(*list)->next->value = temp;
	if (msg)
		write(1, msg, 3);
}

void	push(t_stack **to, t_stack **from, char *msg)
{
	if (!to || !from || !*from)
		return ;
	if ((*from)->next)
		(*from)->next->tail = (*from)->tail;
	lstadd(to, lstnew((*from)->value));
	lstpop(from);
	if (msg)
		write(1, msg, 3);
}

void	rotate(t_stack **list, char *msg)
{
	if (!list || !*list || !(*list)->next)
		return ;
	(*list)->next->tail = *list;
	(*list)->next->prev = NULL;
	(*list)->tail->next = *list;
	(*list)->prev = (*list)->tail;
	(*list) = (*list)->next;
	(*list)->tail->next = NULL;
	if (msg)
		write(1, msg, 3);
}

void	rev_rotate(t_stack **list, char *msg)
{
	if (!list || !*list || !(*list)->next)
		return ;
	(*list)->tail->tail = (*list)->tail->prev;
	(*list)->prev = (*list)->tail;
	(*list)->tail->prev->next = NULL;
	(*list)->tail->prev = NULL;
	(*list)->tail->next = (*list);
	*list = (*list)->tail;
	if (msg)
		write(1, msg, 4);
}
