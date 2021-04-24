#include "../include/cub3d.h"

int ft_n_player(t_get *get)
{
  int i;
  int j;
  int pos;

  i = 0;
  j = 0;
  pos = 0;
  while (get->map[i])
  {
    j = 0;
    while (get->map[i][j])
    {
      if ((get->map[i][j] == 'N')  || (get->map[i][j] == 'S') || \
      (get->map[i][j] == 'W') || (get->map[i][j] == 'E'))
        pos++;
      j++;
    }
    i++;
  }
  return (pos);
}

void ft_verify(t_get *get)
{
  if (ft_n_player(get) != 1)
    ft_error(get, "more or less than one player");
  if (ft_check_fencing(get) == 0)
    ft_error(get, "map not closed");
}

int ft_check_fencing(t_get *get)
{
  int i;

  i = 0;
  while (get->map[i])
    i++;
  if (i < 2)
    return (0);
  else if (i == 2)
  {
      if (!ft_check_fencing_case1(get))
        return (0);
  }
  else if (i == 3)
  {
      if (!ft_check_fencing_case2(get))
        return (0);
  }
  else if (i == 4)
  {
      if (!ft_check_fencing_case3(get))
        return (0);
  }
  else
  {
      if (!ft_check_fencing_case4(get))
        return (0);
  }
  return (1);
}

int ft_check_line_fencing(char *str)
{
  int i;
  int size;

  i = 0;
  size = ft_strlen(str);
  while (str[i])
  {
    while (str[i] == ' ')
      i++;
    if (str[i] != '1')
      return (0);
    break ;
  }
  i = size - 1;
  while (i >= 0)
  {
    while (str[i] == ' ' || str[i] == '\n')
      i--;
    if (str[i] != '1')
      return (0);
    break ;
  }
  return (1);
}


void ft_initprintf(t_get *get)
{
	printf("\nget->error = %d, get->rx = %d get->ry = %d, get->no = %s, get->so = %s, get->we = %s,get->ea = %s;  get->s = %s;get->f = %d;get->c = %d;get->nblines = %d, get->linesize = %d; get->screen_rx = %d; get->screen_ry = %d\n", get->error, get->rx, get->ry, get->no, get->so, get->we, get->ea, get->s, get->f, get->c, get->nblines, get->linesize, get->screen_rx, get->screen_ry);
}

void ft_error(t_get *get, char *str)
{
  int i;

  i = 0;
  write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
  ft_initprintf(get);
  if (get->no)
		free(get->no);
	if (get->so)
		free(get->so);
	if (get->we)
		free(get->we);
	if (get->ea)
		free(get->ea);
	if (get->s)
		free(get->s);
	if (get->map)
		while (++i < get->nblines)
			free(get->map[i]);
  if (get->map)
		free(get->map);
  exit(0);
}

int		ft_exit(t_get *get)
{
  printf("dans error\n");
	if (get->mlx.img)
		mlx_destroy_image(get->mlx.ptr, get->mlx.img);
	if (get->textures[0].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[0].img);
	if (get->textures[1].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[1].img);
	if (get->textures[2].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[2].img);
	if (get->textures[3].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[3].img);
	if (get->textures[4].img)
		mlx_destroy_image(get->mlx.ptr, get->textures[4].img);
	if (get->mlx.win)
		mlx_destroy_window(get->mlx.ptr, get->mlx.win);
	exit(0);
}
