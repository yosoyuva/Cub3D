/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:39 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/26 19:32:33 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_raycasting(t_get *get)
{
	get->ray.x = 0;
	while (get->ray.x < get->rx)
	{
		ft_init_raycasting2(get);
		ft_dda(get);
		ft_draw_color(get);
		get->sprite.zbuffer[get->ray.x] = get->ray.perpwalldist;
		(get->ray.x)++;
	}
	ft_sprite(get);
	if (get->save == 1)
		ft_create_bmp(get);
	//if (get->mlx.win == NULL)
	//	get->mlx.win = mlx_new_window(get->mlx.ptr, get->rx, get->ry, "Cub3D");
	mlx_put_image_to_window(get->mlx.ptr, get->mlx.win, get->mlx.img, 0, 0);
	ft_forward_back(get);
	ft_left_right(get);
	ft_rotate_right_left(get);
	return (1);
}

void	ft_draw_color(t_get *get)
{
	int	y;

	y = 0;
	get->ray.drawend = get->ry - get->ray.drawstart;
	while (y < get->ray.drawstart)
	{
		get->mlx.addr[y * get->rx + get->ray.x] = get->c;
		y++;
	}
	if (y <= get->ray.drawend)
		ft_draw(get, y);
	y = get->ray.drawend + 1;
	while (y < get->ry)
	{
		get->mlx.addr[y * get->rx + get->ray.x] = get->f;
		y++;
	}
}

void	ft_draw(t_get *get, int y)
{
	y = get->ray.drawstart;
	ft_init_texture(get);
	get->text.texx = (int)(get->text.wallx * (double)get->textures
			[get->text.texface].width);
	if (get->ray.side == 0 && get->ray.raydirx > 0)
		get->text.texx = get->textures[get->text.texface].width -
			get->text.texx - 1;
	if (get->ray.side == 1 && get->ray.raydiry < 0)
		get->text.texx = get->textures[get->text.texface].width -
			get->text.texx - 1;
	get->text.step = 1.0 * get->textures[0].height / get->ray.lineheight;
	get->text.texpos = (get->ray.drawstart - get->ry / 2 + \
		get->ray.lineheight / 2) * get->text.step;
	while (y <= get->ray.drawend)
	{
		get->text.texy = (int)get->text.texpos &
			(get->textures[get->text.texface].height - 1);
		get->text.texpos += get->text.step;
		if (y < get->ry && get->ray.x < get->rx)
			get->mlx.addr[y * get->rx + get->ray.x] =
			get->textures[get->text.texface].addr[get->text.texy *
			get->textures[get->text.texface].line_length / 4 + get->text.texx];
		y++;
	}
}

void	ft_dda(t_get *get)
{
	while (get->ray.hit == 0)
	{
		if (get->ray.sidedistx < get->ray.sidedisty)
		{
			get->ray.sidedistx = get->ray.sidedistx + get->ray.deltadistx;
			get->ray.mapx = get->ray.mapx + get->ray.stepx;
			get->ray.side = 0;
		}
		else
		{
			get->ray.sidedisty = get->ray.sidedisty + get->ray.deltadisty;
			get->ray.mapy = get->ray.mapy + get->ray.stepy;
			get->ray.side = 1;
		}
		if (get->map[get->ray.mapx][get->ray.mapy] == '1')
			get->ray.hit = 1;
	}
	ft_dist(get);
}

void	ft_dist(t_get *get)
{
	if (get->ray.side == 0)
		get->ray.perpwalldist = (get->ray.mapx - get->ray.posx + \
			(1 - get->ray.stepx) / 2) / get->ray.raydirx;
	else
		get->ray.perpwalldist = (get->ray.mapy - get->ray.posy + \
			(1 - get->ray.stepy) / 2) / get->ray.raydiry;
	get->ray.lineheight = (int)(get->ry / get->ray.perpwalldist);
	get->ray.drawstart = get->ry / 2 - get->ray.lineheight / 2;
	if (get->ray.drawstart < 0)
		get->ray.drawstart = 0;
	get->ray.drawend = get->ry / 2 + get->ray.lineheight / 2;
	if (get->ray.drawend >= get->ry || get->ray.drawend < 0)
		get->ray.drawend = get->ry - 1;
}
