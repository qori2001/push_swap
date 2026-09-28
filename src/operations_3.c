#include "push_swap.h"

void	rr_without(t_stack *a, t_stack *b)
{
	rotation_without(a);
	rotation_without(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rr_without(a, b);
	write(1, "rr\n", 3);
}

void	rrr_without(t_stack *a, t_stack *b)
{
	rotation_reserve_witou(a);
	rotation_reserve_witou(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrr_without(a, b);
	write(1, "rrr\n", 4);
}

void	ss_without(t_stack *a, t_stack *b)
{
	swap_without(a);
	swap_without(b);
}
