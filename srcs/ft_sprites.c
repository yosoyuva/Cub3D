#include "../include/cub3d.h"

void ft_sprite(t_get *get)
{
  ft_dist_order(get);
}

void ft_dist_order(t_get *get)
{
  int i;

  i = 0;
  while (i < get->sprite.numspr)
  {
    order = i;
    dist[i] = ((get->ray.posx - get->sxy[i].x) * (get->ray.posx - \
      get->sxy[i].x)) + ((get->ray.posy - get->sxy[i].y) * \
      (get->ray.posy - get->sxy[i].y))
    i++;
  }
  ft_order_sprites(get);
}

void ft_order_sprites(t_get *get)
{
  int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < recup->s.numspr)
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
