/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:21 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/26 22:24:39 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_aux(t_get *get)
{
	get->f = -1;
	get->c = -1;
	get->map = NULL;
	get->comma = 0;
	get->nblines = 0;
	get->linesize = 0;
	get->screen_rx = 0;
	get->screen_ry = 0;
	get->dx = 0;
	get->dy = 0;
	get->mlx.img = NULL;
	get->textures[0].img = NULL;
	get->textures[1].img = NULL;
	get->textures[2].img = NULL;
	get->textures[3].img = NULL;
	get->textures[4].img = NULL;
	get->sprite.order = NULL;
	get->sprite.dist = NULL;
	get->sprite.zbuffer = NULL;
	get->sxy = NULL;
}

void	ft_init(t_get *get)
{
	get->mlx.win = NULL;
	get->save = 0;
	get->map_on = 0;
	get->error = 0;
	get->rx = 0;
	get->ry = 0;
	get->no = NULL;
	get->so = NULL;
	get->we = NULL;
	get->ea = NULL;
	get->s = NULL;
	ft_init_aux(get);
}

void	ft_init_raycasting(t_get *get)
{
	get->ray.posx = (double)get->dx + 0.5;
	get->ray.posy = (double)get->dy + 0.5;
	get->ray.dirx = 0;
	get->ray.diry = 0;
	get->ray.planx = 0;
	get->ray.plany = 0;
	get->mlx.forward = 0;
	get->mlx.back = 0;
	get->mlx.left = 0;
	get->mlx.right = 0;
	get->mlx.rotate_right = 0;
	get->mlx.rotate_left = 0;
	if (!(get->sprite.zbuffer = (double *)malloc(sizeof(double) * get->rx)))
		ft_error(get, "malloc zbuffer");
	ft_init_dir(get);
}

void	ft_init_dir(t_get *get)
{
	if (get->depart == 'N')
		get->ray.dirx = -1;
	if (get->depart == 'S')
		get->ray.dirx = 1;
	if (get->depart == 'E')
		get->ray.diry = 1;
	if (get->depart == 'W')
		get->ray.diry = -1;
	if (get->depart == 'N')
		get->ray.plany = 0.66;
	if (get->depart == 'S')
		get->ray.plany = -0.66;
	if (get->depart == 'E')
		get->ray.planx = 0.66;
	if (get->depart == 'W')
		get->ray.planx = -0.66;
}

void	ft_init_raycasting2(t_get *get)
{
	get->ray.camerax = 2 * (double)get->ray.x / (double)get->rx - 1;
	get->ray.raydirx = get->ray.dirx + get->ray.planx * get->ray.camerax;
	get->ray.raydiry = get->ray.diry + get->ray.plany * get->ray.camerax;
	get->ray.mapx = (int)get->ray.posx;
	get->ray.mapy = (int)get->ray.posy;
	get->ray.hit = 0;
	get->ray.movespeed = 0.1;
	get->ray.rotspeed = 0.1;
	ft_init_deltas(get);
	ft_sidedist_step(get);
}
