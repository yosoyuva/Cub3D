#include "../include/cub3d.h"

/* recuperer la resolution depuis read (ligne du .cup renvoyer par get_next_line) */
void ft_resolution(t_get *get, char *read, int *i)
{
  /* d'abord checker si rx et ry n'ont pas recu de valeur sinon t_get error = 7 (la map a une resolution assigne plus d'une fois)*/
  if (get->rx == 0 && get->ry == 0)
  {
    (*i)++;
    get->rx = ft_atoi_cub(read, i);
    get->ry = ft_atoi_cub(read, i);
    if (get->rx == 0 || get->ry == 0 || !ft_rest_is_wspace(read, i))
      get->error = 7;
  }
  else
    get->error = 71;
}

int		create_rgb(int r, int g, int b)
{
	return(r << 24 | g << 16 | b << 8);
}

int ft_check_comma(char *str, int *i)
{
  int comma;
  int j;

  comma = 0;
  j = *i;
  while(str[j])
  {
    if (str[j] == ',')
      comma++;
    j++;
  }
  if (comma == 2)
    return (0);
  return (1);
}

int ft_check_color_range(char *str, int *i)
{
  int j;
  int n;

  j = *i;
  n = ft_atoi_cub(str, &j);
  if ((n > 255 || n < 0 ) && str[j] != ',')
    return (1);
  j++;
  n = ft_atoi_cub(str, &j);
  if ((n > 255 || n < 0 ) && str[j] != ',')
    return (1);
  j++;
  n = ft_atoi_cub(str, &j);
  if (n > 255 || n < 0)
    return (1);
  return (0);
}

int ft_atoi_cub_color(char *str, int *i)
{
  int res;

  res = 0;
  if (!str)
    return (-1);
  *i = ft_iswhite_space(i, str);
  if (ft_check_comma(str, i) && ft_check_color_range(str, i))
    return (-1);
  res = ft_create_rgb(ft_atoi_cub(str, i), ft_atoi_cub(str, i), ft_atoi_cub(str, i));
  return (res);
}

void ft_color_floor(t_get *get, char *read, int *i)
{
  if (get->f == -1)
  {
    (*i)++;
    get->f =
    if (get->f == -1 || !ft_rest_is_wspace(read, i))
      get->error = 8;
  }
  else
    get->error = 81;
}

void ft_color_ceiling(t_get *get, char *read, int *i)
{
  if (get->c == -1)
  {
    (*i)++;
    if (get->c == -1 || !ft_rest_is_wspace(read, i))
      get->error = 9;
  }
  else
    get->error = 91;
}
