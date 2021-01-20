#include "../include/cub3d.h"

void ft_texture_no(t_get *get, char *read, int *i)
{
  if (get->no == NULL)
  {
    (*i)++;
    get->no = ft_atoi_cub_color(read, i);
    if (get->no == -1 || !ft_rest_is_wspace(read, i))
      get->error = 6;
  }
  else
    get->error = 61;
}

void ft_texture_so(t_get *get, char *read, int *i)
{
  if (get->so == NULL)
  {
    (*i)++;
    get->so = ft_atoi_cub_color(read, i);
    if (get->so == -1 || !ft_rest_is_wspace(read, i))
      get->error = 5;
  }
  else
    get->error = 51;
}

void ft_texture_we(t_get *get, char *read, int *i)
{
  if (get->we == NULL)
  {
    (*i)++;
    get->we = ft_atoi_cub_color(read, i);
    if (get->we == -1 || !ft_rest_is_wspace(read, i))
      get->error = 4;
  }
  else
    get->error = 41;
}

void ft_texture_ea(t_get *get, char *read, int *i)
{
  if (get->ea == NULL)
  {
    (*i)++;
    get->ea = ft_atoi_cub_color(read, i);
    if (get->ea == -1 || !ft_rest_is_wspace(read, i))
      get->error = 3;
  }
  else
    get->error = 31;
}

void ft_texture_sprite(t_get *get, char *read, int *i)
{

}
