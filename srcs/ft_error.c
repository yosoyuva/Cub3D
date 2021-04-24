#include "../include/cub3d.h"

/*int ft_walls(t_get *get)
{
}
*/

int ft_n_player(t_get *get)
{
  int i;
  int j;
  int pos;
  //int a;

  i = 0;
  j = 0;
  pos = 0;
  printf("***9***\n");
  //a = 0;
  //printf("linezsize = %d, nbline = %d, map = %s, map[14][0] = %c\n", get->linesize, get->nblines, get->map[14], get->map[14][0]);
  /*while (get->map[a])
  {
    printf("%s      a = %d\n", get->map[a], a);
    a++;
  }*/
  while (get->map[i])
  {
    j = 0;
    printf("***91***\n");
    while (get->map[i][j])
    {
      printf("***92***\n");
      if ((get->map[i][j] == 'N')  || (get->map[i][j] == 'S') || (get->map[i][j] == 'W') || (get->map[i][j] == 'E'))
        pos++;
      printf("***93***\n");
      j++;
    }
    i++;
  }
  printf("***10***\n");
  return (pos);
}

void ft_verify(t_get *get)
{
/* deja fait lors du parsing*/
  //if (ft_walls(get))
  //  ft_error(get, "map is not close");
  printf("***8***\n");
  if (ft_n_player(get) != 1)
    ft_error(get, "more or less than one player");
  printf("***11***\n");
  if (ft_check_fencing(get) == 0)
    ft_error(get, "map not closed");
}

int ft_check_fencing(t_get *get)
{
  int i;

  i = 0;
  // Premier char non espace dans chaque ligne est '1'
  // Deja fait lors de la map_copy
  /*while (get->map[i])
  {
    j = 0;
    while (get->map[i][j])
    {
      while (get->map[i][j] == ' ')
        j++;
      if (get->map[i][j] != '1')
        return (0);
      break ;
    }
    i++;
  }
  i = 0;*/
  // Dernier char non espace dans chaque ligne est '1'
  // Deja fait lors de la map_copy
  /*while (get->map[i])
  {
    j = get->linesize;
    while (get->map[i][j])
    {
      while (get->map[i][j] == ' ')
        j--;
      if (get->map[i][j] != '1')
        return (0);
      break ;
    }
    i++;
  }*/
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
  // Premier char non espace dans la ligne est '1'
  while (str[i])
  {
    while (str[i] == ' ')
      i++;
    if (str[i] != '1')
    {
      printf("str = %s\n", str);
      return (0);
    }
    break ;
  }
  i = size - 1;
  // Dernier char non espace dans la ligne est '1'
  while (i >= 0)
  {
    while (str[i] == ' ' || str[i] == '\n')
      i--;
    if (str[i] != '1')
    {
      //printf("s = %s, str[i] = %c, i = %d, size = %d\n", str, str[i], i, size);
      return (0);
    }
    break ;
  }
//  printf("line = %s, str[i] = %c, i = %d\n", str, str[i], i);
  return (1);
}


void ft_initprintf(t_get *get)
{
	/* on initialise les variables*/
	printf("\nget->error = %d, get->rx = %d get->ry = %d, get->no = %s, get->so = %s, get->we = %s,get->ea = %s;  get->s = %s;get->f = %d;get->c = %d;get->nblines = %d, get->linesize = %d; get->screen_rx = %d; get->screen_ry = %d\n", get->error, get->rx, get->ry, get->no, get->so, get->we, get->ea, get->s, get->f, get->c, get->nblines, get->linesize, get->screen_rx, get->screen_ry);
}

void ft_error(t_get *get, char *str)
{
	/* fonction qui renvoi un message d'erreur et free ce qui a ete allouer par ft_init */

  // get->error == 7 ==> error au niveau de la resolution
  // get->error == 71 ==> essayer d'assigner une resolution plus d'une fois
  // get->error == 6 ==> NO
  // get->error == 61 ==> NO plus d'une fois
  // get->error == 5 ==>SO
  // get->error == 51 ==> SO plus d'une fois
  // get->error == 4 ==> WE
  // get->error == 41 ==> WE plus d'une fois
  // get->error == 3 ==> EA
  // get->error == 31 ==> EA plus d'une fois
  // get->error == 8 ==> color floor
  // get->error == 81 ==> color floor plus d'une fois
  // get->error == 9 ==> color cieling
  // get->error == 91 ==> color ceiling plus d'une fois
  // get->error == 10 ==> sprite
  // get->error == 101 ==> sprite plus d'une fois
  // get->error == 2 ==>
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
	{
		while (++i < get->nblines)
			free(get->map[i]);
	}
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
