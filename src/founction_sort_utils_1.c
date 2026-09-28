#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	rotation_max(t_stack *h, int index)
{
	int	mov;

	if (!h || h->size < 2 || index < 0 || index >= h->size)
		return ;
	if (index <= h->size / 2)
	{
		while (index-- > 0)
			rotation(h);
	}
	else
	{
		mov = h->size - index;
		while (mov-- > 0)
			reserve_rotation(h);
	}
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	ft_max(int *p, int size)
{
	int	i;
	int	max;

	if (!p || size <= 0)
		return (0);
	i = 0;
	max = p[0];
	while (i < size)
	{
		if (p[i] > max)
			max = p[i];
		i++;
	}
	return (max);
}

int	ft_min(int *p, int size)
{
	int	i;
	int	min;

	if (!p || size <= 0)
		return (0);
	i = 0;
	min = p[0];
	while (i < size)
	{
		if (p[i] < min)
			min = p[i];
		i++;
	}
	return (min);
}
