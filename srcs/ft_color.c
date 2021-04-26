/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:06:27 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/26 09:07:24 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_color_floor(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
		get->error = 6;
	if (get->f == -1)
	{
		(*i)++;
		get->f = ft_atoi_cub_color(get, read, i);
		if (get->f == -1 || !ft_rest_is_wspace(read, i))
			get->error = 8;
	}
	else
		get->error = 81;
}

void	ft_color_ceiling(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
		get->error = 6;
	if (get->c == -1)
	{
		(*i)++;
		get->c = ft_atoi_cub_color(get, read, i);
		if (get->c == -1 || !ft_rest_is_wspace(read, i))
			get->error = 9;
	}
	else
		get->error = 91;
}
