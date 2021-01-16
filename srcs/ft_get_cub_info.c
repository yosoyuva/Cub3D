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
  }
}
