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

  i = 0;
  j = 0;
  pos = 0;
  while (get->map[i])
  {
    j = 0;
    while (get->map[i][j])
    {
      if ((get->map[i][j] == 'N')  || (get->map[i][j] == 'S') || (get->map[i][j] == 'W') || (get->map[i][j] == 'E'))
        pos++;
      j++;
    }
  }
  return (pos);
}

void ft_verify(t_get *get)
{
/* deja fait lors du parsing*/
  //if (ft_walls(get))
  //  ft_error(get, "map is not close");
  if (ft_n_player(get) != 1)
    ft_error(get, "more or less than one player");
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
}
