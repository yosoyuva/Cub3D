/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fencing_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:08:13 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 12:20:32 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_fencing(t_get *get)
{
	int	i;

	i = 0;
	while (get->map[i])
		i++;
	if (i < 2)
		return (0);
	else if (i == 2 && !ft_check_fencing_case1(get))
		return (0);
	else if (i == 3)
	{
		if (!ft_check_fencing_case2(get))
			return (0);
	}
	else if (i == 4)
	{
		if (!ft_check_fencing_case3(get))
			return (0);
	}
	else
	{
		if (!ft_check_fencing_case4(get))
			return (0);
	}
	return (1);
}

int		ft_check_line_for_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1')
			return (0);
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] && str[i - 1] != '1')
			return (0);
	}
	return (1);
}

int		ft_check_line_fencing(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1')
			return (0);
		break ;
	}
	i = size - 1;
	while (i >= 0)
	{
		while (str[i] == ' ' || str[i] == '\n')
			i--;
		if (str[i] != '1')
			return (0);
		break ;
	}
	return (ft_check_line_for_space(str));
}

int		ft_check_high_and_low_fence(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1)
		return (0);
	while (str1[i])
	{
		if (str1[i] != '\n' && str1[i] != ' ' && str1[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	if (!str2)
		return (0);
	while (str2[i])
	{
		if (str2[i] != '\n' && str2[i] != ' ' && str2[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int		ft_condition1(t_get *get, int *j)
{
	if (get->map[1][*j] != ' ' && get->map[1][*j] != '1' && \
		get->map[1][*j] != '\n')
	{
		if ((get->map[0][*j] == ' ' || !get->map[0][*j]) || \
			(get->map[2][*j] == ' ' || !get->map[2][*j]))
			return (1);
	}
	return (0);
}
