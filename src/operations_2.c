#include "push_swap.h"

void	push_a_without(t_stack *a, t_stack *b)
{
	if (!a || !b || b->size == 0)
		return ;
	a->size++;
	reverse_move_array(a);
	a->array[0] = b->array[0];
	move_array(b);
	b->size--;
}

void	push_a(t_stack *a, t_stack *b)
{
	if (!a || !b || b->size == 0)
		return ;
	push_a_without(a, b);
	write(1, "pa\n", 3);
}

void	push_b_without(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0)
		return ;
	b->size++;
	reverse_move_array(b);
	b->array[0] = a->array[0];
	move_array(a);
	a->size--;
}

void	push_b(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0)
		return ;
	push_b_without(a, b);
	write(1, "pb\n", 3);
}
