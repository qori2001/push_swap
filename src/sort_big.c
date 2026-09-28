#include "push_swap.h"

static int	cost(t_stack *b, int index)
{
	if (index <= b->size / 2)
		return (index);
	return (b->size - index);
}

/* push back to A: max each time, or (max - 1) first if it is cheaper,
   then a swap puts them in order */
static void	return_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	index;
	int	index1;

	while (b->size > 0)
	{
		max = ft_max(b->array, b->size);
		index = get_index(max, b->array, b->size);
		index1 = get_index(max - 1, b->array, b->size);
		if (index1 != -1 && cost(b, index1) < cost(b, index))
			index = index1;
		rotation_max(b, index);
		push_a(a, b);
		if (a->size > 1 && a->array[0] > a->array[1])
			swap(a);
	}
}

static int	get_chunks(int size_stack)
{
	if (size_stack <= 10)
		return (size_stack / 2);
	if (size_stack <= 100)
		return (22);
	if (size_stack <= 500)
		return (65);
	return (size_stack / 10);
}

static int	send_min(t_stack *a, t_stack *b, int start, int end)
{
	int	pos;
	int	mid;

	pos = ft_in_pos(start, end, a);
	if (pos == -1)
		return (0);
	mid = (start + end) / 2;
	rotation_max(a, pos);
	push_b(a, b);
	if (b->size > 1 && b->array[0] <= mid)
	{
		pos = ft_in_pos(start, end, a);
		if (pos > 0 && pos <= a->size / 2)
			rr(a, b);
		else
			rotation(b);
	}
	return (1);
}

void	sorting(t_stack *a, t_stack *b)
{
	int	chunk;
	int	start;
	int	end;
	int	*tab_index;

	tab_index = get_index_array(a);
	if (!tab_index)
		return ;
	free(a->array);
	a->array = tab_index;
	chunk = get_chunks(a->size);
	start = 0;
	end = chunk - 1;
	while (a->size > 0)
	{
		while (send_min(a, b, start, end))
			;
		start = end + 1;
		end = end + chunk;
	}
	return_to_a(a, b);
}
