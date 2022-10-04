/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:44 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 10:37:57 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_resolution(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
		get->error = 6;
	if (get->rx == 0 && get->ry == 0)
	{
		(*i)++;
		get->rx = ft_atoi_cub(read, i);
		get->ry = ft_atoi_cub(read, i);
		if (get->rx <= 0 || get->ry <= 0 || !ft_rest_is_wspace(read, i))
			get->error = 7;
	}
	else
		get->error = 71;
}

int		ft_check_comma(char *str, int *i)
{
	int	j;
	int	comma;

	comma = 0;
	j = *i;
	while (str[j])
	{
		if (str[j] == ',')
			comma = comma + 1;
		j++;
	}
	if (comma == 2)
		return (0);
	return (1);
}

int		ft_check_color_range(char *str, int *i)
{
	int	j;
	int	n;

	j = *i;
	n = ft_atoi_cub(str, &j);
	if ((n > 255 || n < 0) && str[j] != ',')
		return (1);
	j++;
	n = ft_atoi_cub(str, &j);
	if ((n > 255 || n < 0) && str[j] != ',')
		return (1);
	j++;
	n = ft_atoi_cub(str, &j);
	if (n > 255 || n < 0)
		return (1);
	return (0);
}

int		ft_atoi_cub_color(t_get *get, char *str, int *i)
{
	get->res = 0;
	if (!str)
		return (-1);
	*i = ft_iswhite_space(i, str);
	if (ft_check_comma(str, i))
		return (-1);
	get->r1 = ft_atoi_cub(str, i);
	if (str[*i] == ',')
		*i = *i + 1;
	else
		return (-1);
	get->r2 = ft_atoi_cub(str, i);
	if (str[*i] == ',')
		*i = *i + 1;
	else
		return (-1);
	get->r3 = ft_atoi_cub(str, i);
	if ((get->r1 > 255 || get->r1 < 0 || get->r2 > 255 || get->r2 < 0 || \
		get->r3 > 255 || get->r3 < 0) && (str[*i] == '\0' || str[*i] == '\n'))
		return (-1);
	get->res = ft_create_rgb(0, get->r1, get->r2, get->r3);
	return (get->res);
}
