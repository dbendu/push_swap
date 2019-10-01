#include "libft/includes/libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*tail;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

t_stack				*lstnew(int value);
void				lstadd(t_stack **list, t_stack *elem);
void				lstpurge(t_stack **list);
void				lstpop(t_stack **list);
int					lstpeek(t_stack *list);
void				lstpush(t_stack **stack, t_stack *new);

void				swap(t_stack **list);
void				push(t_stack **to, t_stack **from);
void				rotate(t_stack **list);
void				rev_rotate(t_stack **list);
size_t				lstsize(t_stack *stack);