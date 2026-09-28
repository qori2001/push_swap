#include "push_swap.h"

void	move_array(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
}

void	reverse_move_array(t_stack *h)
{
	int	i;

	i = h->size - 1;
	while (i > 0)
	{
		h->array[i] = h->array[i - 1];
		i--;
	}
}

void	swap_without(t_stack *h)
{
	int	tmp;

	if (!h || h->size < 2)
		return ;
	tmp = h->array[0];
	h->array[0] = h->array[1];
	h->array[1] = tmp;
}

void	swap(t_stack *h)
{
	if (!h || h->size < 2)
		return ;
	swap_without(h);
	if (h->c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	ss_without(a, b);
	write(1, "ss\n", 3);
}
