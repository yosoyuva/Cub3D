/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:01:00 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/26 00:02:10 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_deltas(t_get *get)
{
	if (get->ray.raydiry == 0)
		get->ray.deltadistx = 0;
	else if (get->ray.raydirx != 0)
		get->ray.deltadistx = sqrt(1 + (get->ray.raydiry * get->ray.raydiry) / \
			(get->ray.raydirx * get->ray.raydirx));
	else
		get->ray.deltadistx = 1;
	if (get->ray.raydirx == 0)
		get->ray.deltadisty = 0;
	else if (get->ray.raydiry != 0)
		get->ray.deltadisty = sqrt(1 + (get->ray.raydirx * get->ray.raydirx) / \
			(get->ray.raydiry * get->ray.raydiry));
	else
		get->ray.deltadisty = 1;
}

void	ft_sidedist_step(t_get *get)
{
	if (get->ray.raydirx < 0)
	{
		get->ray.stepx = -1;
		get->ray.sidedistx = (get->ray.posx - get->ray.mapx) * \
			get->ray.deltadistx;
	}
	else
	{
		get->ray.stepx = 1;
		get->ray.sidedistx = (get->ray.mapx + 1.0 - get->ray.posx) * \
			get->ray.deltadistx;
	}
	if (get->ray.raydiry < 0)
	{
		get->ray.stepy = -1;
		get->ray.sidedisty = (get->ray.posy - get->ray.mapy) * \
			get->ray.deltadisty;
	}
	else
	{
		get->ray.stepy = 1;
		get->ray.sidedisty = (get->ray.mapy + 1.0 - get->ray.posy) * \
			get->ray.deltadisty;
	}
}

void	ft_init_texture(t_get *get)
{
	if (get->ray.side == 0 && get->ray.raydirx < 0)
		get->text.texface = 0;
	if (get->ray.side == 0 && get->ray.raydirx >= 0)
		get->text.texface = 1;
	if (get->ray.side == 1 && get->ray.raydiry < 0)
		get->text.texface = 2;
	if (get->ray.side == 1 && get->ray.raydiry >= 0)
		get->text.texface = 3;
	if (get->ray.side == 0)
		get->text.wallx = get->ray.posy + get->ray.perpwalldist * \
			get->ray.raydiry;
	else
		get->text.wallx = get->ray.posx + get->ray.perpwalldist * \
			get->ray.raydirx;
	get->text.wallx -= floor((get->text.wallx));
}

void	ft_init_sprites(t_get *get)
{
	int	i;
	int	j;

	i = 0;
	get->sprite.numspr = 0;
	while (i < get->nblines)
	{
		j = 0;
		while (j < get->linesize)
		{
			if (get->map[i][j] == '2')
				get->sprite.numspr += 1;
			j++;
		}
		i++;
	}
	if (!(get->sxy = (t_sxy *)malloc(sizeof(t_sxy) * get->sprite.numspr)))
		ft_error(get, "Malloc sxy*");
	if (!(get->sprite.order = (int *)malloc(sizeof(int) * get->sprite.numspr)))
		ft_error(get, "Malloc sprite.order*");
	if (!(get->sprite.dist = (double *)malloc(sizeof(double) * \
		get->sprite.numspr)))
		ft_error(get, "Malloc sprite.dist*");
	ft_init_sprite2(get, 0, 0, 0);
}

void	ft_init_sprite2(t_get *get, int i, int j, int s)
{
	while (i < get->nblines)
	{
		j = 0;
		while (j < get->linesize)
		{
			if (get->map[i][j] == '2')
			{
				get->sxy[s].x = (double)i + 0.5;
				get->sxy[s].y = (double)j + 0.5;
				s++;
			}
			j++;
		}
		i++;
	}
}
