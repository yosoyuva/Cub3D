#include "../include/cub3d.h"

void ft_init(t_get *get)
{
	/* on initialise les variables*/
	get->save = 0;
  get->error = 0;
  get->rx = 0;
  get->ry = 0;
  get->no = NULL;
  get->so = NULL;
  get->we = NULL;
  get->ea = NULL;
  get->s = NULL;
  get->f = -1;
  get->c = -1;
  get->comma = 0;
  get->nblines = 0;
  get->linesize = 0;
  get->screen_rx = 0;
  get->screen_ry = 0;
  get->dx = 0;
  get->dy = 0;
}

void ft_init_raycasting(t_get *get)
{
  get->ray.posx = get->dx;
  get->ray.posy = get->dy;
  get->ray.dirx = 0;
  get->ray.diry = 0;
  get->ray.planx = 0;
  get->ray.plany = 0;
  ft_init_dir(get);
}

void	ft_init_dir(t_recup *get)
{
  /* fov = (2 * atan(0.66/1.0)) = 66 degres */
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
