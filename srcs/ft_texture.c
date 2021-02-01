#include "../include/cub3d.h"

void ft_texture_no(t_get *get, char *read, int *i)
{
/*if (data de map no NULL)
    get->error = 6;*/
  *i = *i + 1;
  printf("***7***\n");
  if (get->no == NULL)
  {
    (*i)++;
    get->no = ft_get_path(read, i, get);
    printf("***fin get path no***\n");
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
  *i = *i + 1;
  if (get->so == NULL)
  {
    *i = *i +2;
    get->so = ft_get_path(read, i, get);
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
  *i = *i + 1;
  if (get->we == NULL)
  {
    *i = *i +2;
    get->we = ft_get_path(read, i, get);
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
  *i = *i + 1;
  if (get->ea == NULL)
  {
    *i = *i +2;
    get->ea = ft_get_path(read, i, get);
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
    get->s = ft_get_path(read, i, get);
    if (get->s == NULL)
      get->error = 10;
  }
  else
    get->error = 101;
}

char *ft_get_path(char *str, int *i, t_get *get)
{
  char *path;
  int j;

  j = 0;
  *i = ft_iswhite_space(i, str);
  printf("***8***\n");
  printf("str[*i] = %c, *i = %d\n", str[*i], *i);
  if (str[*i] == '.' && str[*i + 1] == '/')
  {
    if (!(path = malloc(sizeof(char) * (ft_strlen2(str) + 1))))
		{
      get->error = 2;
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
