#include "push_swap.h"

void	rotation_without(t_stack *h)
{
	int	save;

	if (!h || h->size < 2)
		return ;
	save = h->array[0];
	move_array(h);
	h->array[h->size - 1] = save;
}

void	rotation_reserve_witou(t_stack *h)
{
	int	save;

	if (!h || h->size < 2)
		return ;
	save = h->array[h->size - 1];
	reverse_move_array(h);
	h->array[0] = save;
}

void	rotation(t_stack *head)
{
	if (!head || head->size < 2)
		return ;
	rotation_without(head);
	if (head->c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reserve_rotation(t_stack *h)
{
	if (!h || h->size < 2)
		return ;
	rotation_reserve_witou(h);
	if (h->c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
