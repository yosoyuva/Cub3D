#include "../include/cub3d.h"

void ft_forward_back(t_get *get)
{
  if (get->data.forward == 1)
	{
		if (get->map[(int)(get->ray.posx + (ray->ray.dirx * get->
						ray.movespeed * 2))][(int)get->ray.posy] == '0')
			get->ray.posx += get->ray.dirx * get->ray.movespeed;
		if (get->map[(int)(get->ray.posx)][(int)(get->ray.posy +
					(get->ray.diry * get->ray.movespeed * 2))] == '0')
			get->ray.posy += get->ray.diry * get->ray.movespeed;
	}
	if (get->data.back == 1)
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
  if (get->data.right == 1)
	{
		if (get->map[(int)(get->ray.posx + get->ray.diry *
					(get->ray.movespeed * 2))][(int)get->ray.posy] == '0')
			get->ray.posx += get->ray.diry * get->ray.movespeed;
		if (get->map[(int)get->ray.posx][(int)(get->ray.posy -
					get->ray.dirx *
					(get->ray.movespeed * 2))] == '0')
			get->ray.posy -= get->ray.dirx * get->ray.movespeed;
	}
	if (get->data.left == 1)
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
	if (get->data.rotate_right == 1)
	{
		get->ray.dirx = get->ray.dirx * cos(-get->ray.rotspeed / 2) -
			get->ray.diry * sin(-get->ray.rotspeed / 2);
		get->ray.diry = olddirx * sin(-get->ray.rotspeed / 2) +
			get->ray.diry * cos(-get->ray.rotspeed / 2);
		get->ray.planx = get->ray.planx * cos(-get->ray.rotspeed / 2)
			- get->ray.plany * sin(-get->ray.rotspeed / 2);
		get->ray.plany = oldplanx * sin(-get->ray.rotspeed / 2) +
			get->ray.plany * cos(-get->ray.rotspeed / 2);
	}
	ft_rotate_left(get, olddirx);
}
