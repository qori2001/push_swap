#include "push_swap.h"

static void	sort_2(t_stack *a)
{
	if (a->array[0] > a->array[1])
		swap(a);
}

static void	sort_3(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
		rotation(a);
	else if (a->array[1] > a->array[0] && a->array[1] > a->array[2])
		reserve_rotation(a);
	if (a->array[0] > a->array[1])
		swap(a);
}

static void	sort_4(t_stack *a, t_stack *b)
{
	int	min;
	int	index;

	min = ft_min(a->array, a->size);
	index = get_index(min, a->array, a->size);
	rotation_max(a, index);
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
}

static void	sort_5(t_stack *a, t_stack *b)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	while (i < 2)
	{
		min = ft_min(a->array, a->size);
		index = get_index(min, a->array, a->size);
		rotation_max(a, index);
		push_b(a, b);
		i++;
	}
	sort_3(a);
	push_a(a, b);
	push_a(a, b);
}

void	simple_sort(t_stack *a, t_stack *b, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
