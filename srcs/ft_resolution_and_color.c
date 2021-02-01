#include "../include/cub3d.h"

int ft_rest_is_wspace(char *str, int *i)
{
  int j;

  j = *i;
  ft_iswhite_space(&j, str);
  if (str[j] != '\n' && str[j] != '\0')
    return (0);
  return (1);
}

/* recuperer la resolution depuis read (ligne du .cup renvoyer par get_next_line) */
void ft_resolution(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
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

int		ft_create_rgb(int a,int r, int g, int b)
{

	return(a << 24 | r << 16 | g << 8 | b);
}

int ft_check_comma(char *str, int *i)
{
  int j;
  int comma;

  comma = 0;
  j = *i;
  while(str[j])
  {
    if (str[j] == ',')
      comma = comma + 1;
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

int ft_atoi_cub_color(t_get *get, char *str, int *i)
{
  int res;
  int r1;
  int r2;
  int r3;

  res = 0;
  if (!str)
    return (-1);
  *i = ft_iswhite_space(i, str);
  if (ft_check_comma(str, i)/* && ft_check_color_range(str, i)*/)
    return (-1);
  //printf("str[i] = %c, str = %s, i = %d", str[*i], str, *i);
  r1 = ft_atoi_cub(str, i);
  if (str[*i] == ',')
    *i = *i + 1;
  else
    ft_error(get, "invalide color");
  r2 = ft_atoi_cub(str, i);
  if (str[*i] == ',')
    *i = *i + 1;
  else
    ft_error(get, "invalide color");
  r3 = ft_atoi_cub(str, i);
  if ((r1 > 255 || r1 < 0 || r2 > 255 || r2 < 0 || r3 > 255 || r3 < 0) && (str[*i] == '\0' || str[*i] == '\n'))
    ft_error(get, "invalide color");
//  printf("r1 = %d, r2 = %d, r3 = %d\n", r1, r2, r3);
  res = ft_create_rgb(0, r1, r2, r3);
//  printf("res = %d\n", res);
  return (res);
}

void ft_color_floor(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
  if (get->f == -1)
  {
    (*i)++;
    get->f = ft_atoi_cub_color(get, read, i);
    if (get->f == -1 || !ft_rest_is_wspace(read, i))
      get->error = 8;
  }
  else
    get->error = 81;
}

void ft_color_ceiling(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
  if (get->c == -1)
  {
    (*i)++;
    get->c = ft_atoi_cub_color(get, read, i);
    if (get->c == -1 || !ft_rest_is_wspace(read, i))
      get->error = 9;
  }
  else
    get->error = 91;
}
