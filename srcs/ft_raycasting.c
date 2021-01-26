#include "../include/cub3d.h"

int ft_mlx(t_get *get)
{
  //t_mlx_id mlx_id;
  t_data mlx;
  //t_mystruct mystruct;

  mlx.i = 1;
  if (!(mlx.ptr = mlx_init()))// Connecting to the minilibx and save the ID connection to mlx_ptr
    ft_error(recup, "Mlx initialization failed\n");
  ft_mlx_win_img(get, &mlx);
/*  mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
  //mlx_key_hook(mlx_id.mlx_win, esc_hook, &mlx_id);
  //mlx_hook(mlx_id.mlx_win, 5, 1<<, function, param dont a potentielment besoin functiojn)
  hello_bye_mouse(&mlx);
  mlx.ptr = mlx.ptr;
  mlx.win = mlx.win;
  mlx_loop_hook(mlx.ptr, render_next_frame, &mlx);*/
  mlx_loop(mlx.ptr);// A loop to keep the connection up
}

int ft_mlx_win_img(t_get *get, t_data *mlx)
{
  mlx_get_screen_size(mlx->ptr, &get->screen_rx, &get->screen_ry);// recupere la resolution de l'ecran
  get->rx = (get->rx > get->screen_rx) ? get->screen_rx : get->rx;
	get->ry = (get->ry > get->screen_ry) ? get->screen_ry : get->ry;
  mlx->win = mlx_new_window(mlx->ptr, get->rx, get->ry, "Cub3D");// Creating a new window and saving the ID of the window to mlx_window
  mlx->img = mlx_new_image(mlx->ptr, get->rx, get->ry);
  mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length,
                                &mlx->endian);
}
