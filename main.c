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

int  esc_hook(int keycode, t_mlx_id *mlx_id)
{
  if (keycode == 65307)
  {
    mlx_destroy_window(mlx_id->mlx_ptr, mlx_id->mlx_win);
  }
}

int hello_mouse(t_mlx_id *mlx)
{
  printf("%s\n", "hello");
}

int bye_mouse(t_mlx_id *mlx)
{
  printf("%s\n", "bye");
}

void hello_bye_mouse(t_mlx_id *mlx)
{
  mlx_hook(mlx->mlx_win, 7, 1L<<4, hello_mouse, mlx);
  mlx_hook(mlx->mlx_win, 8, 1L<<5, bye_mouse, mlx);
}

int render_next_frame(t_data *img)
{
  while (img->i > 0)
  {
    img->i = 1;
    while (img->i < 500)
    {
      img->i++;
      printf("%d\n", img->i);
      img->img = mlx_new_image(img->ptr, 500, 500);
      img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                    &img->endian);
      print_square(img, 5, 5, create_trgb(0, 0, 255, 255), img->i);
      mlx_put_image_to_window(img->ptr, img->win, img->img, 0, 0);
    }
  }
  return (0);
}

/*int main(void)
{
  t_mlx_id mlx_id;
  t_data img;
  //t_mystruct mystruct;

  img.i = 1;
  mlx_id.mlx_ptr = mlx_init();// Connecting to the minilibx and save the ID connection to mlx_ptr
  mlx_id.mlx_win = mlx_new_window(mlx_id.mlx_ptr, 500, 500, "Hello world!");// Creating a new window and saving the ID of the window to mlx_window
  img.img = mlx_new_image(mlx_id.mlx_ptr, 500, 500);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
  print_square(&img, img.i, 5, create_trgb(0, 0, 255, 255), 25);
  mlx_put_image_to_window(mlx_id.mlx_ptr, mlx_id.mlx_win, img.img, 0, 0);
  //mlx_key_hook(mlx_id.mlx_win, esc_hook, &mlx_id);
  //mlx_hook(mlx_id.mlx_win, 5, 1<<, function, param dont a potentielment besoin functiojn)
  hello_bye_mouse(&mlx_id);
  img.ptr = mlx_id.mlx_ptr;
  img.win = mlx_id.mlx_win;
  mlx_loop_hook(mlx_id.mlx_ptr, render_next_frame, &img);
  mlx_loop(mlx_id.mlx_ptr);// A loop to keep the connection up
}*/

int ft_get_info_check_errors(char *file, t_get *get)
{
	int fd;
	int ret;
	char *read

	ret = 1;
	if ((fd = open(file, O_DIRECTORY)) != -1)
		ft_error(get, "Invalid : is a directory\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(get, "Invalid .cub file\n");
	while (read != 0)
	{
		ret = get_next_line(fd, &read, get);
		if (error en parsing)
			ft_error(get, "error while parsing");
		/* check les differentes information dans la map (resolution, color, texture, map ...) */
		free(read);
	}
	close(fd);
	//if()
	/* check si la map n'est pas vide */
	ft_parsing(file, get);
}

int cub3d(char *str, t_get *get)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(get, "Map's name invalid\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_get_info_check_errors(str, get);
	else
		ft_error(get, "Map's name invalid\n"); // fonction qui renvoi un message d'erreur et free ce qui a ete allouer par ft_init
	return (0);
}

void ft_init(t_get *get)
{
	/* on initialise les variables*/
	get->save == 0;
}

int main(int ac, char** av)
{
  t_get get;

	ft_init(&get);
	if (ac == 2 || (ac == 3 && ft_check_save(av[2]) == 1))
	{
		if (argc == 3)
			get.save = 1;
		ft_cub3d(av[1], &get);
	}
	else
		write(1, "Invalid args\n", 12);
}
