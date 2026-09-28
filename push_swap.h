#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ============================== INCLUDES ============================== */
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

/* =============================== STRUCTS ============================== */
typedef struct s_stack
{
	int		*array;
	int		size;
	char	c;
}	t_stack;

/* ============================== PARSING =============================== */
int		*parse_input(int argc, char **argv, int *c);
int		*get_a(char **res, int count_numbre);
char	*str_join(char **str, int argc);
int		count_str(char **str);
int		has_empty_arg(int argc, char **argv);
void	error_exit(char **to_free);
int		is_sort(int *p, int size);
int		is_good(char *s);
int		is_duplicate(int *tab, int a, int index);
long	ft_atoi_long(char *str);

/* ============================== OPERATIONS ============================ */
void	swap(t_stack *h);
void	ss(t_stack *a, t_stack *b);
void	rotation(t_stack *head);
void	reserve_rotation(t_stack *h);
void	push_b(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	move_array(t_stack *a);
void	reverse_move_array(t_stack *h);

/* ====================== SILENT OPERATIONS (checker) =================== */
void	rotation_without(t_stack *h);
void	rotation_reserve_witou(t_stack *h);
void	swap_without(t_stack *h);
void	ss_without(t_stack *a, t_stack *b);
void	push_b_without(t_stack *a, t_stack *b);
void	push_a_without(t_stack *a, t_stack *b);
void	rr_without(t_stack *a, t_stack *b);
void	rrr_without(t_stack *a, t_stack *b);

/* =============================== SORTING ============================== */
void	sorting(t_stack *a, t_stack *b);
void	simple_sort(t_stack *a, t_stack *b, int size);
void	rotation_max(t_stack *h, int index);

/* ============================ INDEX / COST ============================ */
int		*get_index_array(t_stack *a);
int		ft_in_pos(int start, int end, t_stack *h);
int		get_index(int a, int *p, int size);

/* ============================== UTILITIES ============================= */
int		ft_min(int *p, int size);
int		ft_max(int *p, int size);
void	sort_tab(int *tab, int size);
int		*copy_tab(int *tab, int c);
void	ft_swap(int *a, int *b);

/* ========================== CREATE / FREE ============================= */
t_stack	*cree_stack_a(int *array, int size, char c);
t_stack	*cree_stack_b(int size, t_stack *a);
void	free_stack(t_stack *s);
void	free_split(char **str);

#endif
