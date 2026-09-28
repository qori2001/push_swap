#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*tab_a;
	t_stack		*head_a;
	t_stack		*head_b;
	int			c;

	c = 0;
	if (argc < 2)
		return (0);
	tab_a = parse_input(argc, argv, &c);
	if (is_sort(tab_a, c))
		return (free(tab_a), 0);
	head_a = cree_stack_a(tab_a, c, 'a');
	if (!head_a)
		error_exit(NULL);
	head_b = cree_stack_b(c, head_a);
	if (!head_b)
		error_exit(NULL);
	if (c <= 5)
		simple_sort(head_a, head_b, c);
	else
		sorting(head_a, head_b);
	free_stack(head_a);
	free_stack(head_b);
	return (0);
}
