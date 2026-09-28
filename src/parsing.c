#include "push_swap.h"

int	*get_a(char **res, int count_numbre)
{
	int		i;
	int		*p;
	long	n;

	i = 0;
	p = malloc(sizeof(int) * count_numbre);
	if (!p)
		return (NULL);
	while (res[i] != NULL)
	{
		if (!is_good(res[i]))
			return (free(p), NULL);
		n = ft_atoi_long(res[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free(p), NULL);
		p[i] = (int)n;
		if (is_duplicate(p, p[i], i) == 0)
			return (free(p), NULL);
		i++;
	}
	return (p);
}

long	ft_atoi_long(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > (long)INT_MAX + 1)
			return (res * sign);
		i++;
	}
	return (res * sign);
}

int	is_duplicate(int *tab, int a, int index)
{
	index--;
	while (index >= 0)
	{
		if (a == tab[index])
			return (0);
		index--;
	}
	return (1);
}

int	is_good(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	*parse_input(int argc, char **argv, int *c)
{
	char	*all_str;
	char	**res;
	int		*tab_a;

	if (has_empty_arg(argc, argv))
		error_exit(NULL);
	all_str = str_join(argv, argc);
	if (!all_str)
		error_exit(NULL);
	res = ft_split(all_str, ' ');
	free(all_str);
	if (!res)
		error_exit(NULL);
	*c = count_str(res);
	if (*c == 0)
		error_exit(res);
	tab_a = get_a(res, *c);
	if (!tab_a)
		error_exit(res);
	free_split(res);
	return (tab_a);
}
