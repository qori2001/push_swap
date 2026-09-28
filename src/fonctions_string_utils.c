#include "push_swap.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (free(s1), NULL);
	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	*str_join(char **str, int argc)
{
	char	*res;
	int		i;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		res = ft_strjoin_free(res, str[i]);
		if (!res)
			return (NULL);
		if (i < argc - 1)
		{
			res = ft_strjoin_free(res, " ");
			if (!res)
				return (NULL);
		}
		i++;
	}
	return (res);
}

int	count_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

/* returns 1 if one argument is empty or contains only spaces: "" or "   " */
int	has_empty_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	error_exit(char **to_free)
{
	if (to_free)
		free_split(to_free);
	write(2, "Error\n", 6);
	exit(1);
}
