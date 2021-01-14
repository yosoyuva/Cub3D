#include "../include/cub3d.h"

int		ft_iswhite_space(int *i, const char *str)
{
	while (str[*i] == ' ' || str[*i] == '\f' ||
			str[*i] == '\n' || str[*i] == '\r' ||
			str[*i] == '\t' || str[*i] == '\v')
		(*i)++;
	return (*i);
}

int		ft_issign(int *i, const char *str, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	return (*i);
}

int		ft_atoi_cub(const char *str, int *i)
{
	//int	i;
	//int	sign;
	int	res;

	//sign = 1;
	//i = 0;
	res = 0;
	*i = ft_iswhite_space(i, str);
	if (ft_issign(i, str, &sign);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && str[*i] - 48 > 7))
		{
			if (sign == 1)
				return (INT_MAX);
			else if (res * sign == INT_MIN / 10 && str[*i] - 48 > 7)
				return (INT_MIN);
			else
				return (0);
		}
		res = res * 10 + (str[*i] - 48);
		i++;
	}
	return (res);
}
