#include "../include/cub3d.h"

/* recuperer la resolution depuis read (ligne du .cup renvoyer par get_next_line) */
void resolution(t_get *get, char *read, int *i)
{
  /* d'abord checker si rx et ry n'ont pas recu de valeur sinon t_get error = 7 (la map a une resolution assigne plus d'une fois)*/
  if (get->rx == 0 && get->ry == 0)
  {
    while (read[*i] == ' ')
      (*i)++;
    if ()
  }
  else
    get->error == 71;
}

void ft_get_cub_info(char *file, t_get *get, char *read)
{
  int i;

  i = 0;
  while (read[i])
  {
    if (read[i] == '\n')
     break ;
    while (read[i] == ' ')
      i++;
    if (read[i] == 'R')
      ft_resolution(get, read, &i);
  }
}
