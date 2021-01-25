#include "../include/cub3d.h"

int ft_rest_is_wspace(char *str, int *i)
{
  ft_iswhite_space(i, str);
  if (str[*i])
    return (0);
  return (1);
}

void ft_get_cub_info(char *file, t_get *get, char *read)
{
  int i;

  i = 0;
  while (read[i])
  {
    if (read[i] == '\n')
     break ;
    ft_iswhite_space(&i, read);
    //while (read[i] == ' ')
    //  i++;
    if (read[i] == 'R')
      ft_resolution(get, read, &i);
    if (read[i] == 'N' && read[i + 1] == 'O')
      ft_texture_no(get, read, &i);
    if (read[i] == 'S' && read[i + 1] == 'O')
      ft_texture_so(get, read, &i);
    if (read[i] == 'W' && read[i + 1] == 'E')
      ft_texture_we(get, read, &i);
    if (read[i] == 'E' && read[i + 1] == 'A')
      ft_texture_ea(get, read, &i);
    if (read[i] == 'S' && read[i + 1] =! 'O')
      ft_texture_sprite(get, read, &i);
    if (read[i] == 'F')
      ft_color_floor(get, read, &i);
    if (read[i] == 'C')
      ft_color_ceiling(get, read, &i);
    /* recuperer les info de la map creer un tableau de tableau que je remplirai ligne par ligne en fonction de ce qui est lu par get_next_line */
    if (read[i] == '1')
      ft_map(get, read, &i);
    if (read[i] == '\n' && (get->linesize > 0 || get->nblines > 0))
      ft_error(get, "line feed on map desciption");
  }
}

int ft_is_char_map(char *str, int *i)
{
  if (str[*i] != ' ' && str[*i] != '0' && str[*i] != '1' \
      && str[*i] != '2' && str[*i] != 'N' && str[*i] != 'S' \
      && str[*i] != 'E' && str[*i] != 'W' && str[*i] != '\n'
      && str[*i] != '\t')
  {
    return (0);
  }
  return (1);
}

/* check si de dexiption de map est conforme (sinon get-error = 2) et recupere le nombre de ligne et la taille de la plus grande*/
int ft_map(t_get *get, char *str, int *i)
{
  if (str[*i] != '1')
  {
    get->error = 2;
    return (0);
  }
  while (ft_is_char_map(str, i))
  {
    if (str[*i] = ' ')
    {
      if (str[*i - 1] != '1')
        get->error = 2;
      while (str[*i] == ' ')
        (*i)++;
      if (str[*i] != '1' && str[*i] != '\n' && str[*i] != '\0')
        get->erro = 2;
    }
    (*i)++;
  }
  if (str[*i] != '\0')
  {
   get->error = 2;
    return (0);
  }
  if (ft_strlen(str) > get->linesize)
    get->linesize = ft_strlen(str);
  get->nblines = get->nblines + 1;
  return (1);
}

int ft_copy_map(char *file, char *read, t_get *get)
{
  int fd;
  int ret;
  int i;

  ret = 1;
  i = 0;
  fd = open(file, O_RDONLY);
  if (!(get->map = malloc(sizeof(char*) * get->nblines)))
		return (0);
  while (i <= get->nblines)
  {
    if (!(get->map[i] = malloc(sizeof(char*) * get->linesize)))
  		return (0);
  }
  get->map[i][0] = '\0';
  i = 0;
  while (ret != 0)
	{
		ret = get_next_line(fd, read, get);
    if (ft_is_map(read)/*condition : c'est une ligne de map */)
    {
      ft_copy_map_aux(read, &(get->map[i]);
      i++;
    }
	}
	close(fd);
  ft_verify(get);
}

void ft_copy_map_aux(char *str, char *map)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] = ' ')
      map[i] = '1';
    else
      map[i] = str[i];
    i++;
  }
  map[i] = '\0';
}
