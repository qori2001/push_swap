#include "push_swap.h"

int	*copy_tab(int *tab, int c)
{
	int	i;
	int	*tab_copy;

	i = 0;
	tab_copy = malloc(c * sizeof(int));
	if (!tab_copy)
		return (NULL);
	while (i < c)
	{
		tab_copy[i] = tab[i];
		i++;
	}
	return (tab_copy);
}

static void	fill_index(t_stack *a, int *sorted, int *array_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[j] == sorted[i])
				array_index[j] = i;
			j++;
		}
		i++;
	}
}

/* replaces each value by its rank: [42, -7, 100] -> [1, 0, 2] */
int	*get_index_array(t_stack *a)
{
	int	*copy_sort;
	int	*array_index;

	copy_sort = copy_tab(a->array, a->size);
	if (!copy_sort)
		return (NULL);
	sort_tab(copy_sort, a->size);
	array_index = malloc(a->size * sizeof(int));
	if (!array_index)
		return (free(copy_sort), NULL);
	fill_index(a, copy_sort, array_index);
	free(copy_sort);
	return (array_index);
}

int	get_index(int a, int *p, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (p[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_in_pos(int start, int end, t_stack *h)
{
	int	i;
	int	j;

	i = 0;
	j = h->size - 1;
	while (j >= i)
	{
		if (h->array[i] >= start && h->array[i] <= end)
			return (i);
		if (h->array[j] >= start && h->array[j] <= end)
			return (j);
		i++;
		j--;
	}
	return (-1);
}
