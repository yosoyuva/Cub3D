/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:57 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 08:52:43 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_texture_no(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
	{
		get->error = 6;
	}
	*i = *i + 1;
	if (get->no == NULL)
	{
		(*i)++;
		get->no = ft_get_path(read, i, get);
		if (get->no == NULL)
			get->error = 6;
	}
	else
		get->error = 61;
}

void	ft_texture_so(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
	{
		get->error = 6;
	}
	(*i)++;
	if (get->so == NULL)
	{
		(*i)++;
		get->so = ft_get_path(read, i, get);
		if (get->so == NULL)
			get->error = 5;
	}
	else
		get->error = 51;
}

void	ft_texture_we(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
		get->error = 6;
	*i = *i + 1;
	if (get->we == NULL)
	{
		(*i)++;
		get->we = ft_get_path(read, i, get);
		if (get->we == NULL)
			get->error = 4;
	}
	else
		get->error = 41;
}

void	ft_texture_ea(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
		get->error = 6;
	*i = *i + 1;
	if (get->ea == NULL)
	{
		(*i)++;
		get->ea = ft_get_path(read, i, get);
		if (get->ea == NULL)
			get->error = 3;
	}
	else
		get->error = 31;
}

void	ft_texture_sprite(t_get *get, char *read, int *i)
{
	if (get->map_on == 1)
		get->error = 6;
	if (get->s == NULL)
	{
		(*i)++;
		get->s = ft_get_path(read, i, get);
		if (get->s == NULL)
			get->error = 10;
	}
	else
		get->error = 101;
}
