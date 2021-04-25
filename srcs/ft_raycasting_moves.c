/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:31 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/25 22:03:32 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_forward_back(t_get *get)
{
  if (get->mlx.forward == 1)
	{
    //printf("posy = %f, map[x][y] = %c, posx = %f, dirx = %f, movespeed = %f, X = %d\n", get->ray.posy, get->map[(int)(get->ray.posx + (get->ray.dirx * get->ray.movespeed * 2))][(int)get->ray.posy], get->ray.posx, get->ray.dirx, get->ray.movespeed, (int)(get->ray.posx + (get->ray.dirx * get->ray.movespeed * 2)));
		if (get->map[(int)(get->ray.posx + (get->ray.dirx * get->
						ray.movespeed * 2))][(int)get->ray.posy] == '0')
    {
			get->ray.posx += get->ray.dirx * get->ray.movespeed;
      //printf("chnage in posx\n");
    }
		if (get->map[(int)(get->ray.posx)][(int)(get->ray.posy +
					(get->ray.diry * get->ray.movespeed * 2))] == '0')
		{
      get->ray.posy += get->ray.diry * get->ray.movespeed;
      //printf("chnage in posx\n");
    }
	}
	if (get->mlx.back == 1)
	{
		if (get->map[(int)(get->ray.posx - (get->ray.dirx * get->
						ray.movespeed * 2))][(int)(get->ray.posy)] == '0')
			get->ray.posx -= get->ray.dirx * get->ray.movespeed;
		if (get->map[(int)(get->ray.posx)][(int)(get->ray.posy -
					(get->ray.diry * get->ray.movespeed * 2))] == '0')
			get->ray.posy -= get->ray.diry * get->ray.movespeed;
	}
}

void ft_left_right(t_get *get)
{
  if (get->mlx.right == 1)
	{
		if (get->map[(int)(get->ray.posx + get->ray.diry *
					(get->ray.movespeed * 2))][(int)get->ray.posy] == '0')
			get->ray.posx += get->ray.diry * get->ray.movespeed;
		if (get->map[(int)get->ray.posx][(int)(get->ray.posy -
					get->ray.dirx *
					(get->ray.movespeed * 2))] == '0')
			get->ray.posy -= get->ray.dirx * get->ray.movespeed;
	}
	if (get->mlx.left == 1)
	{
		if (get->map[(int)(get->ray.posx - get->ray.diry *
					(get->ray.movespeed * 2))][(int)get->ray.posy] == '0')
			get->ray.posx -= get->ray.diry * get->ray.movespeed;
		if (get->map[(int)get->ray.posx][(int)(get->ray.posy +
					get->ray.dirx *
					(get->ray.movespeed * 2))] == '0')
			get->ray.posy += get->ray.dirx * get->ray.movespeed;
	}
}

void	ft_rotate_right_left(t_get *get)
{
	double oldplanx;
	double olddirx;

	oldplanx = get->ray.planx;
	olddirx = get->ray.dirx;
  /* on multiplie les vecteurs par la matrice de rotation */
	if (get->mlx.rotate_right == 1)
	{
		get->ray.dirx = get->ray.dirx * cos(-get->ray.rotspeed) -
			get->ray.diry * sin(-get->ray.rotspeed);
		get->ray.diry = olddirx * sin(-get->ray.rotspeed) +
			get->ray.diry * cos(-get->ray.rotspeed);
		get->ray.planx = get->ray.planx * cos(-get->ray.rotspeed)
			- get->ray.plany * sin(-get->ray.rotspeed);
		get->ray.plany = oldplanx * sin(-get->ray.rotspeed) +
			get->ray.plany * cos(-get->ray.rotspeed);
	}
	ft_rotate_left(get, olddirx, oldplanx);
}

void	ft_rotate_left(t_get *get, double olddirx, double oldplanx)
{
	if (get->mlx.rotate_left == 1)
	{
		olddirx = get->ray.dirx;
		oldplanx = get->ray.planx;
		get->ray.dirx = get->ray.dirx * cos(get->ray.rotspeed) -
			get->ray.diry * sin(get->ray.rotspeed);
		get->ray.diry = olddirx * sin(get->ray.rotspeed) + get->
			ray.diry * cos(get->ray.rotspeed);
		get->ray.planx = get->ray.planx * cos(get->ray.rotspeed) -
			get->ray.plany * sin(get->ray.rotspeed);
		get->ray.plany = oldplanx * sin(get->ray.rotspeed) +
			get->ray.plany * cos(get->ray.rotspeed);
	}
}
