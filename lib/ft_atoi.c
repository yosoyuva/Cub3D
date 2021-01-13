/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:00:07 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/17 04:32:50 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

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

int		ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	i = ft_iswhite_space(&i, str);
	ft_issign(&i, str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && str[i] - 48 > 7))
		{
			if (sign == 1)
				return (-1);
			else if (res * sign == INT_MIN / 10 && str[i] - 48 > 7)
				return (INT_MIN);
			else
				return (0);
		}
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
