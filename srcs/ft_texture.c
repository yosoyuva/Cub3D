#include "../include/cub3d.h"

void ft_texture_no(t_get *get, char *read, int *i)
{
/*if (data de map no NULL)
    get->error = 6;*/
  if (get->no == NULL)
  {
    (*i)++;
    get->no = ft_get_path(read, i);
    if (get->no == NULL)
      get->error = 6;
  }
  else
    get->error = 61;
}

void ft_texture_so(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
  if (get->so == NULL)
  {
    (*i)+2;
    get->so = ft_get_path(read, i);
    if (get->so == NULL)
      get->error = 5;
  }
  else
    get->error = 51;
}

void ft_texture_we(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
  if (get->we == NULL)
  {
    (*i)+2;
    get->we = ft_get_path(read, i);
    if (get->we == NULL)
      get->error = 4;
  }
  else
    get->error = 41;
}

void ft_texture_ea(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
  if (get->ea == NULL)
  {
    (*i)+2;
    get->ea = ft_get_path(read, i);
    if (get->ea == NULL)
      get->error = 3;
  }
  else
    get->error = 31;
}

void ft_texture_sprite(t_get *get, char *read, int *i)
{
  /*if (data de map no NULL)
      get->error = 6;*/
  if (get->s == NULL)
  {
    (*i)++;
    get->s = ft_get_path(read, i);
    if (get->s == NULL)
      get->error = 10;
  }
  else
    get->error = 101;
}

char *ft_get_path(char *str, int *i)
{
  char *path;
  int j;

  j = 0;
  *i = ft_iswhite_space(i, str);
  if (str[*i] == '.' && str[*i + 1] == '/')
  {
    if (!(path = malloc(sizeof(char) * (ft_strlen2(str) + 1))))
		{
      recup->erreur = 2;
      return (NULL);
    }
    while (str[*i] != '\0')
    {
      path[j] = str[*i];
      j++;
      (*i)++;
    }
    return (path);
  }
  else
    return (NULL);
}

int ft_strlen2(char *str)
{
  int i;
  int j;

  j = 0;
  i = 0;
  if (!str)
    return (-1);
  while (str[i] != '.')
  {
    i++;
  }
  while (str[i] != '\0')
  {
    j++;
    i++;
  }
  return (j);
}
