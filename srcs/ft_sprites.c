/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:51 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/26 09:47:23 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_sprite(t_get *get, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < get->sprite.drawendy)
	{
		d = (y) * 256 - get->ry * 128 + get->sprite.spriteheight * 128;
		texy = ((d * get->textures[4].height) / get->sprite.spriteheight) / 256;
		if (get->textures[4].addr[texy * get->textures[4].line_length / 4 +
				texx] != 0)
		{
			get->mlx.addr[y * get->mlx.line_length / 4 + stripe] =
				get->textures[4].addr[texy * get->textures[4].line_length /
				4 + texx];
		}
		y++;
	}
}

void	ft_sprite(t_get *get)
{
	int		i;
	int		texx;
	int		y;
	int		stripe;

	ft_dist_order(get, &i);
	while (++i < get->sprite.numspr)
	{
		get->sprite.spritex = get->sxy[get->sprite.order[i]].x - get->ray.posx;
		get->sprite.spritey = get->sxy[get->sprite.order[i]].y - get->ray.posy;
		ft_sprite_aux(get);
		stripe = get->sprite.drawstartx;
		while (++stripe < get->sprite.drawendx)
		{
			texx = (int)(256 * (stripe - (-get->sprite.spritewidth / 2 +
					get->sprite.spritescreenx)) * get->textures[4].width
					/ get->sprite.spritewidth) / 256;
			if (get->sprite.transformy > 0 && stripe >= 0 && stripe < get->rx
					&& get->sprite.transformy < get->sprite.zbuffer[stripe])
			{
				y = get->sprite.drawstarty;
				ft_draw_sprite(get, y, texx, stripe);
			}
		}
	}
}

void	ft_sprite_aux(t_get *get)
{
	get->sprite.invdet = 1.0 / (get->ray.planx * get->ray.diry -
			get->ray.dirx * get->ray.plany);
	get->sprite.transformx = get->sprite.invdet * (get->ray.diry *
			get->sprite.spritex - get->ray.dirx * get->sprite.spritey);
	get->sprite.transformy = get->sprite.invdet * (-get->ray.plany *
			get->sprite.spritex + get->ray.planx * get->sprite.spritey);
	get->sprite.spritescreenx = (int)((get->rx / 2) * (1 + \
			get->sprite.transformx / get->sprite.transformy));
	get->sprite.spriteheight = abs((int)(get->ry / (get->sprite.transformy)));
	get->sprite.drawstarty = -get->sprite.spriteheight / 2 + get->ry / 2;
	if (get->sprite.drawstarty < 0)
		get->sprite.drawstarty = 0;
	get->sprite.drawendy = get->sprite.spriteheight / 2 + get->ry / 2;
	if (get->sprite.drawendy >= get->ry)
		get->sprite.drawendy = get->ry;
	get->sprite.spritewidth = abs((int)(get->ry / (get->sprite.transformy)));
	get->sprite.drawstartx = -get->sprite.spritewidth / 2 +
	get->sprite.spritescreenx;
	if (get->sprite.drawstartx < 0)
		get->sprite.drawstartx = 0;
	get->sprite.drawendx = get->sprite.spritewidth / 2 +
	get->sprite.spritescreenx;
	if (get->sprite.drawendx >= get->rx)
		get->sprite.drawendx = get->rx;
}

void	ft_dist_order(t_get *get, int *i_ft_sprite)
{
	int		i;

	i = 0;
	while (i < get->sprite.numspr)
	{
		get->sprite.order[i] = i;
		get->sprite.dist[i] = ((get->ray.posx - get->sxy[i].x) * \
			(get->ray.posx - get->sxy[i].x)) + ((get->ray.posy - \
				get->sxy[i].y) * (get->ray.posy - get->sxy[i].y));
		i++;
	}
	ft_order_sprites(get);
	*i_ft_sprite = -1;
}

void	ft_order_sprites(t_get *get)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < get->sprite.numspr)
	{
		j = 0;
		while (j < get->sprite.numspr - 1)
		{
			if (get->sprite.dist[j] < get->sprite.dist[j + 1])
			{
				tmp = get->sprite.dist[j];
				get->sprite.dist[j] = get->sprite.dist[j + 1];
				get->sprite.dist[j + 1] = tmp;
				tmp = get->sprite.order[j];
				get->sprite.order[j] = get->sprite.order[j + 1];
				get->sprite.order[j + 1] = (int)tmp;
			}
			j++;
		}
		i++;
	}
}
