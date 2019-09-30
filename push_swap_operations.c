#include "push_swap.h"

void swap(t_stack **list)
{
	int	temp;

	if (!list || !*list || !(*list)->next)
		return ;
	temp = (*list)->value;
	(*list)->value = (*list)->next->value;
	(*list)->next->value = temp;
}

void push(t_stack **to, t_stack **from)
{
	if (!to || !from || !*from)
		return ;
	if ((*from)->next)
		(*from)->next->tail = (*from)->tail;
	lstadd(to, lstnew(lstpeek(*from)));
	lstpop(from);
}

void rotate(t_stack **list)
{
	if (!list || !*list || !(*list)->next)
		return ;
	(*list)->next->tail = *list;
	(*list)->next->prev = NULL;
	(*list)->tail->next = *list;
	(*list)->prev = (*list)->tail;
	(*list) = (*list)->next;
	(*list)->tail->next = NULL;
}

void rev_rotate(t_stack **list)
{
	if (!list || !*list || !(*list)->next)
		return ;
	(*list)->tail->tail = (*list)->tail->prev;
	(*list)->prev = (*list)->tail;
	(*list)->tail->prev->next = NULL;
	(*list)->tail->prev = NULL;
	(*list)->tail->next = (*list);
	*list = (*list)->tail;
}