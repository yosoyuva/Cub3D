/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:47:07 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 10:48:05 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error_aux_exit(t_get *get)
{
	if (get->map)
		free(get->map);
	if (get->sprite.order)
		free(get->sprite.order);
	if (get->sprite.dist)
		free(get->sprite.dist);
	if (get->sxy)
		free(get->sxy);
	if (get->sprite.zbuffer)
		free(get->sprite.zbuffer);
}

void	ft_error_exit(t_get *get)
{
	int	i;

	i = 0;
	if (get->no)
		free(get->no);
	if (get->so)
		free(get->so);
	if (get->we)
		free(get->we);
	if (get->ea)
		free(get->ea);
	if (get->s)
		free(get->s);
	if (get->map)
	{
		while (i < get->nblines)
		{
			free(get->map[i]);
			i++;
		}
	}
	ft_error_aux_exit(get);
}

int		ft_exit_raycasting(t_get *get)
{
	ft_error_exit(get);
	if (get->mlx.img)
		mlx_destroy_image(get->mlx.ptr, get->mlx.img);
	if (get->textures[0].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[0].img);
	if (get->textures[1].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[1].img);
	if (get->textures[2].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[2].img);
	if (get->textures[3].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[3].img);
	if (get->textures[4].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[4].img);
	if (get->mlx.win)
		mlx_destroy_window(get->mlx.ptr, get->mlx.win);
	exit(0);
}
