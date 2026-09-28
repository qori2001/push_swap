#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	if (s->array)
		free(s->array);
	s->array = NULL;
	s->size = 0;
	free(s);
}

t_stack	*cree_stack_a(int *array, int size, char c)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (free(array), NULL);
	a->array = array;
	a->size = size;
	a->c = c;
	return (a);
}

t_stack	*cree_stack_b(int size, t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (free_stack(a), NULL);
	b->array = malloc(size * sizeof(int));
	if (!b->array)
	{
		free(b);
		free_stack(a);
		return (NULL);
	}
	b->size = 0;
	b->c = 'b';
	return (b);
}

int	is_sort(int *p, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!p || size <= 1)
		return (1);
	while (i < size && j < size)
	{
		if (p[i] < p[j])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	return (1);
}
