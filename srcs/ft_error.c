/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:02:55 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 10:50:10 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_n_player(t_get *get)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	pos = 0;
	while (get->map[i])
	{
		j = 0;
		while (get->map[i][j])
		{
			if ((get->map[i][j] == 'N') || (get->map[i][j] == 'S') || \
				(get->map[i][j] == 'W') || (get->map[i][j] == 'E'))
				pos++;
			j++;
		}
		i++;
	}
	return (pos);
}

void	ft_verify(t_get *get)
{
	if (ft_n_player(get) != 1)
		ft_error(get, "more or less than one player");
	if (ft_check_fencing(get) == 0)
		ft_error(get, "map not closed");
}

void	ft_error_aux(t_get *get)
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
	ft_exit(get);
}

void	ft_error(t_get *get, char *str)
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
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
	ft_error_aux(get);
}

int		ft_exit(t_get *get)
{
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
