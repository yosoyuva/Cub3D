#include "../include/cub3d.h"

int		ft_iswhite_space(int *i, const char *str)
{
	while (str[*i] == ' ' || str[*i] == '\f' ||
			str[*i] == '\n' || str[*i] == '\r' ||
			str[*i] == '\t' || str[*i] == '\v')
		(*i)++;
	return (*i);
}

int		ft_iswhite_space_n_out(int *i, const char *str)
{
	while (str[*i] == ' ' || str[*i] == '\f' ||
			str[*i] == '\r' ||
			str[*i] == '\t' || str[*i] == '\v')
		(*i)++;
	return (*i);
}

int		ft_issign(int *i, const char *str)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		return (1);
	}
	return (0);
}

int		ft_atoi_cub(const char *str, int *i)
{
	int	res;

	res = 0;
	if (!str)
    return (-1);
	printf("***10***\n");
	*i = ft_iswhite_space_n_out(i, str);
	printf("***110***\n");
//	if (ft_issign(i, str))
//		return (-1);
	printf("***11***\n");
	if (str[*i] < '0' || str[*i] > '9')
		return (-1);
	printf("***12***\n");
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && str[*i] - 48 > 7))
		{
			return (INT_MAX);
		}
		res = res * 10 + (str[*i] - 48);
		(*i)++;
	}
	*i = ft_iswhite_space_n_out(i, str);
	printf("***13***\n");
	return (res);
}
