#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int applique_movemt(char *mv, t_stack *a, t_stack *b)
{
    if (ft_strcmp(mv, "sa\n") == 0)
        swap_without(a);
    else if (ft_strcmp(mv, "ra\n") == 0)
        rotation_without(a);
    else if (ft_strcmp(mv, "pa\n") == 0)
        push_a_without(a, b);
    else if (ft_strcmp(mv, "pb\n") == 0)
        push_b_without(a, b);
    else if (ft_strcmp(mv, "rr\n") == 0)
        rr_without(a, b);
    else if (ft_strcmp(mv, "rrr\n") == 0)
        rrr_without(a, b);
    else if (ft_strcmp(mv, "rb\n"))
        rotation_without(b);
    else if (ft_strcmp(mv, "sb\n") == 0)
        swap_without(b);
    else if (ft_strcmp(mv, "rra\n") == 0)
        rotation_reserve_witou(a);
    else if (ft_strcmp(mv, "rrb\n") == 0)
        rotation_reserve_witou(b);
    else
        return 0;
    return 1;
}

void push_swap_bonus(t_stack *a, t_stack *b)
{
    char *movemt;

    while (1)
    {
        movemt = get_next_line(0);
        if (!movemt)
            break;

        if (applique_movemt(movemt, a, b) == 1)
            free(movemt);
        else
        {
            free(movemt);
            write(2, "Error\n", 6);
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    int *tab_a;
    t_stack *head_a;
    t_stack *head_b;
    int c;

    if (argc < 2)
        return (0);
    tab_a = parse_input(argc, argv, &c);
    if (!tab_a || is_sort(tab_a, c))
        return (free(tab_a), 0);
    head_a = cree_stack_a(tab_a, c, 'a');
    if (!head_a)
        return (0);
    head_b = cree_stack_b(c, head_a);
    if (!head_b)
        return (0);
    push_swap_bonus(head_a, head_b);
    if (is_sort(head_a->array, head_a->size))
        printf("OK\n");
    else
        printf("KO\n");
    free_stack(head_a);
    free_stack(head_b);
    return 0;
}
