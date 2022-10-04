/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fencing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:05 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 12:19:14 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_fencing_case1(t_get *get)
{
	if (ft_check_high_and_low_fence(get->map[0], get->map[1]))
		return (1);
	return (0);
}

int	ft_check_fencing_case2(t_get *get)
{
	int	i;

	i = 0;
	if (!ft_check_high_and_low_fence(get->map[0], get->map[2]))
		return (0);
	while (get->map[1][i])
	{
		if (get->map[1][i] != ' ' && get->map[1][i] != '1' && \
			get->map[1][i] != '\n')
		{
			if (get->map[0][i] != '1' && get->map[2][i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_fencing_case3(t_get *get)
{
	int	j;

	j = -1;
	if (!ft_check_high_and_low_fence(get->map[0], get->map[3]))
		return (0);
	while (get->map[1][++j])
	{
		if (get->map[1][j] != ' ' && get->map[1][j] != '1' && \
		get->map[1][j] != '\n')
		{
			if (get->map[0][j] == ' ' || !get->map[0][j])
				return (0);
			if (get->map[2][j] == ' ' || !get->map[2][j])
				return (0);
		}
	}
	j = -1;
	while (get->map[2][++j])
	{
		if (get->map[2][j] != ' ' && get->map[2][j] != '1' && \
			get->map[2][j] != '\n')
			if (get->map[3][j] == ' ' || !get->map[3][j])
				return (0);
	}
	return (1);
}

int	ft_condition2(t_get *get, int *j)
{
	if (get->map[get->nblines - 2][*j] != ' ' && \
		get->map[get->nblines - 2][*j] != '1' && \
		get->map[get->nblines - 2][*j] != '\n')
	{
		if (get->map[get->nblines - 3][*j] == ' ' || !get->map[get->nblines \
			- 3][*j] || get->map[get->nblines - 1][*j] == ' ' || \
			!get->map[get->nblines - 1][*j])
			return (1);
	}
	return (0);
}

int	ft_check_fencing_case4(t_get *get)
{
	int	i;
	int	j;

	j = -1;
	i = 1;
	if (!ft_check_high_and_low_fence(get->map[0], get->map[get->nblines - 1]))
		return (0);
	while (get->map[1][++j])
		if (ft_condition1(get, &j))
			return (0);
	j = -1;
	while (get->map[get->nblines - 2][++j])
		if (ft_condition2(get, &j))
			return (0);
	while (++i < get->nblines - 2)
	{
		j = -1;
		while (get->map[i][++j])
			if (get->map[i][j] != ' ' && get->map[i][j] != '1' && \
				get->map[i][j] != '\n')
				if (get->map[i - 1][j] == '\0' || get->map[i + 1][j] == '\0' \
					|| get->map[i - 1][j] == ' ' || get->map[i + 1][j] == ' ')
					return (0);
	}
	return (1);
}
