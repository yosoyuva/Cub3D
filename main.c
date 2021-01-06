#include "include/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    // QUESTION : pourquoi a marche a partir du momemnt ou on ne recupere pas dst et que la fonction renvoie un void
    // Je pense que ca a voir avec le fait qu'on donne "l'adresse" de l'image maisd'un autre cote on lui ajoute un valeur
}

void           print_square(t_data *data, int x, int y, int color, int area)
{
  int i;
  int j;

  i = x;
  j = y;
  while (y < j + area)
  {
    x = i + 1;
    while (x < i + area)
    {
      my_mlx_pixel_put(data, x++, y, color);
    }
    my_mlx_pixel_put(data, x, y++, color);
  }
}

int main(void)
{
  t_mlx_id mlx_id;
  t_data img;

  mlx_id.mlx_ptr = mlx_init();// Connecting to the minilibx and save the ID connection to mlx_ptr
  mlx_id.mlx_win = mlx_new_window(mlx_id.mlx_ptr, 500, 500, "Hello world!");// Creating a new window and saving the ID of the window to mlx_window
  img.img = mlx_new_image(mlx_id.mlx_ptr, 500, 500);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
  print_square(&img, 5, 5, create_trgb(0, 0, 255, 255), 25);
  mlx_put_image_to_window(mlx_id.mlx_ptr, mlx_id.mlx_win, img.img, 0, 0);
  mlx_loop(mlx_id.mlx_ptr);// A loop to keep the connection up
}
