#include "../include/cub3d.h"

void ft_get_cub_info(t_get *get, char *read)
{
  int i;

  i = 0;
  if (read[i])
  {
    ft_iswhite_space(&i, read);
    if (read[i] == 'R')
      ft_resolution(get, read, &i);
    else if (read[i] == 'N' && read[i + 1] == 'O')
      ft_texture_no(get, read, &i);
    else if (read[i] == 'S' && read[i + 1] == 'O')
      ft_texture_so(get, read, &i);
    else if (read[i] == 'W' && read[i + 1] == 'E')
      ft_texture_we(get, read, &i);
    else if (read[i] == 'E' && read[i + 1] == 'A')
      ft_texture_ea(get, read, &i);
    else if (read[i] == 'S' && read[i + 1] != 'O')
      ft_texture_sprite(get, read, &i);
    else if (read[i] == 'F')
      ft_color_floor(get, read, &i);
    else if (read[i] == 'C')
      ft_color_ceiling(get, read, &i);
    else if (read[i] == '1')
      ft_map(get, read, &i);
    else if (read[i] == '\n' && (get->linesize > 0 || get->nblines > 0))
      ft_error(get, "line feed on map desciption");
    else
      ft_error(get, "false map");
    printf("read = %s\n", read);
    ft_iswhite_space(&i, read);
    printf("read = %s apres iswhitespace\n", read);
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

/*
** check si de description de map est conforme (sinon get-error = 2)
**et recupere le nombre de ligne et la taille de la plus grande
*/
int ft_map(t_get *get, char *str, int *i)
{
  get->map_on = 1;
  if (str[*i] != '1')
  {
    get->error = 2;
    return (0);
  }
  if (ft_is_char_map(str, i))
  {
    if (ft_check_line_fencing(&str[*i]) == 0)
      ft_error(get, "non closed line in map");
  }
  else
    ft_error(get, "non valid char inside line in map");
  if ((int)ft_strlen(str) > get->linesize)
    get->linesize = ft_strlen(str) + 1;
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
  if (!(get->map = malloc(sizeof(char *) * (get->nblines + 1))))
		return (0);
  ft_bzero(get->map, sizeof(char *) * (get->nblines + 1));
  while (i < get->nblines)
  {
    if (!(get->map[i] = malloc(sizeof(char) * (get->linesize + 1))))
  		return (0);
    ft_bzero(get->map[i], sizeof(char) * (get->linesize + 1));
    i++;
  }
  i = 0;
  while (ret != 0)
	{
		ret = get_next_line(fd, &read, get);
    if (ft_is_map(read))
    {
      ft_copy_map_aux(read, get->map[i]);
      i++;
    }
	}
	close(fd);
  ft_verify(get);
  return (1);
}

void ft_copy_map_aux(char *str, char *map)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] == ' ')
      map[i] = '1';
    else
      map[i] = str[i];
    i++;
  }
  map[i] = '\0';
}

int ft_is_map(char *str)
{
  int i;

  i = 0;
  ft_iswhite_space(&i, str);
  if (str[i] == '1')
    return (1);
  return (0);
}

void ft_get_depart(t_get *get)
{
  int i;
  int j;

  i = 0;
  while (get->map[i])
  {
    j = 0;
    while (get->map[i][j])
    {
      if (get->map[i][j] == 'N' || get->map[i][j] == 'S' \
      || get->map[i][j] == 'E' || get->map[i][j] == 'W')
      {
         get->dx = i;
         get->dy = j;
         get->depart = get->map[i][j];
         get->map[i][j] = '0';
      }
      j++;
    }
    i++;
  }
}
