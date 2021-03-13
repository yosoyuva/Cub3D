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
  get->ray.posx = (double)get->dx + 0.5; // pour etre en plein milieu de la case
  get->ray.posy = (double)get->dy + 0.5;
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

void ft_init_raycasting2(t_get *get)
{
  get->ray.camerax = 2 * (double)get->ray.x / (double)get->rx - 1;
  get->ray.raydirx = get->ray.dirx + get->ray.planx * get->ray.camerax;
  get->ray.raydiry = get->ray.diry + get->ray.plany * get->ray.camerax;
  get->ray.mapx = (int)get->ray.posx;
  get->ray.mapy = (int)get->ray.posy;
  get->ray.hit = 0;
  ft_init_deltas(get);
  ft_sidedist_step(get);
}

void ft_init_deltas(t_get *get)
{
  if (get->ray.raydirx != 0)
    get->ray.deltadistx = sqrt(1 + (get->ray.raydiry * get->ray.raydiry) / \
    (get->ray.raydirx * get->ray.raydirx));
  else
    get->ray.deltadistx = 1;
  if (get->ray>raydiry != 0)
    get->ray.deltadisty = sqrt(1 + (get->ray.raydirx * get->ray.raydirx) / \
    (get->ray.raydiry * get->ray.raydiry));
  else
    get->ray.deltadisty = 1;
}

void ft_sidedist_step(t_get *get)
{
  if (get->ray.raydirx < 0)
  {
    get->ray.stepx = -1;
    get->ray.sidedistx = (get->ray.posx - get->ray.mapx) * get->ray.deltadistx;
  }
  else
  {
    get->ray.stepx = 1;
    get->ray.sidedistx = (get->ray.mapx + 1.0 - get->ray.posx) * get->ray.deltadistx;
  }
  if (get->ray.raydiry < 0)
  {
    get->ray.stepy = -1;
    get->ray.sidedisty = (get->ray.posy - get->ray.mapy) * get->ray.deltadisty;
  }
  else
  {
    get->ray.stepy = 1;
    get->ray.sidedisty = (get->ray.mapy + 1.0 - get->ray.posy) * get->ray.deltadisty;
  }
}
