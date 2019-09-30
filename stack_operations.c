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

int		lstpeek(t_stack *list)
{
	if (!list)
		return (0);
	return (list->value);
}

size_t lstsize(t_stack *stack)
{
	size_t size;

	size = 0;
	while (stack)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}
