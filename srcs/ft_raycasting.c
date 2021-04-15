#include "../include/cub3d.h"

int ft_mlx(t_get *get)
{
  //t_mlx_id mlx_id;
  //t_data mlx;
  //t_mystruct mystruct;

  get->mlx.i = 1;
  ft_init_raycasting(get);
  if (!(get->mlx.ptr = mlx_init()))// Connecting to the minilibx and save the ID connection to mlx_ptr
    ft_error(get, "Mlx initialization failed\n");
  ft_mlx_win_img(get);
/*  mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
  //mlx_key_hook(mlx_id.mlx_win, esc_hook, &mlx_id);
  //mlx_hook(mlx_id.mlx_win, 5, 1<<, function, param dont a potentielment besoin functiojn)
  hello_bye_mouse(&mlx);
  mlx.ptr = mlx.ptr;
  mlx.win = mlx.win;
  mlx_loop_hook(mlx.ptr, render_next_frame, &mlx);*/
  //mlx_loop(get->mlx.ptr);// A loop to keep the connection up

  mlx_hook(get->mlx.win, 33, 1L << 17, ft_exit, get);// destroy windowwhen clicking on the cross
	mlx_hook(get->mlx.win, 2, 1L << 0, ft_key_press, get);
	mlx_loop_hook(get->mlx.ptr, ft_raycasting, get);
	mlx_hook(get->mlx.win, 3, 1L << 1, ft_key_release, get);
	mlx_loop(get->mlx.ptr);
  return (1);
}

void ft_raycasting(t_get *get)
{
  get->ray.x = 0;// on initialise
  while (get->ray.x < get->rx)
  {
    ft_init_raycasting2(get);
    ft_dda(get);
  }
}

void ft_dda(t_get *get)
{
  while (get->ray.hit == 0)
  {
    if (get->ray.sidedistx < get->ray.sidedisty)
    {
      get->ray.sidedistx = get->ray.sidedistx + get->ray.deltadistx;
      get->ray.mapx = get->ray.mapx + get->ray.stepx;
      get->ray.side = 0; // ns
    }
    else
    {
      get->ray.sidedisty = get->ray.sidedisty + get->ray.deltadisty;
      get->ray.mapy = get->ray.mapy + get->ray.stepy;
      get->ray.side = 1; // ew
    }
    if (get->map[get->ray.mapx][get->ray.mapy] == '1')
      hit = 1;
    ft_dist(get);
  }
}

void ft_dist(t_get *get)
{
  /* preuve par thalles */
  if (get->ray.side == 0)
    get->ray.perpwalldist = (get->ray.mapx - get->ray.posx + \
      (1 - get->ray.stepx) / 2) / get->ray.raydirx;
  else
    get->ray.perpwalldist = (get->ray.mapy - get->ray.posy + \
      (1 - get->ray.stepy) / 2) / get->ray.raydiry;
  /* Calculate height of line to draw on screen */
  get->ray.lineheight = (int)(get->ry / get->ray.perpwalldist);
  /* Calculate lowest and highest pixel to fill in current stripe */
  get->ray.drawstart = get->ry / 2 - get->ray.lineheight / 2;
  if (get->ray.drawstart < 0)
    get->ray.drawstart = 0;
  get->ray.drawend = get->ry / 2 + get->ray.lineheight / 2;
  if (get->ray.drawend >= get->ry || get->ray.drawend < 0)
    get->ray.drawend = get->ry - 1;
}

void ft_mlx_win_img(t_get *get)
{
  mlx_get_screen_size(get->mlx.ptr, &get->screen_rx, &get->screen_ry);// recupere la resolution de l'ecran
  get->rx = (get->rx > get->screen_rx) ? get->screen_rx : get->rx;
	get->ry = (get->ry > get->screen_ry) ? get->screen_ry : get->ry;
  ft_get_texture(get);
  get->mlx.win = mlx_new_window(get->mlx.ptr, get->rx, get->ry, "Cub3D");// Creating a new window and saving the ID of the window to mlx_window
  get->mlx.img = mlx_new_image(get->mlx.ptr, get->rx, get->ry);
  get->mlx.addr = mlx_get_data_addr(get->mlx.img, &(get->mlx.bits_per_pixel), &(get->mlx.line_length),
                                &(get->mlx.endian));
}


void ft_get_texture(t_get *get)
{
  if (!(get->texture[0].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->no, &(get->texture[0].width),
					&(get->texture[0].height))))
		ft_error(get, "Texture SO\n");
	if (!(get->texture[1].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->so, &(get->texture[1].width),
					&(get->texture[1].height))))
		ft_error(get, "Texture NO\n");
	if (!(get->texture[2].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->we, &(get->texture[2].width),
					&(get->texture[2].height))))
		ft_error(get, "Texture EA\n");
	if (!(get->texture[3].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->ea, &(get->texture[3].width),
					&(get->texture[3].height))))
		ft_error(get, "Texture WE\n");
	if (!(get->texture[4].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->s, &(get->texture[4].width),
					&(get->texture[4].height))))
		ft_error(get, "Texture S\n");
	ft_get_texture_addr(get);
}

void ft_get_texture_addr(t_get *get)
{
  get->texture[0].addr = (int *)mlx_get_data_addr(get->texture[0].img,
			&get->texture[0].bits_per_pixel,
			&get->texture[0].line_length, &get->texture[0].endian);
	get->texture[1].addr = (int *)mlx_get_data_addr(get->texture[1].img,
			&get->texture[1].bits_per_pixel,
			&get->texture[1].line_length, &get->texture[1].endian);
	get->texture[2].addr = (int *)mlx_get_data_addr(get->texture[2].img,
			&get->texture[2].bits_per_pixel,
			&get->texture[2].line_length, &get->texture[2].endian);
	get->texture[3].addr = (int *)mlx_get_data_addr(get->texture[3].img,
			&get->texture[3].bits_per_pixel,
			&get->texture[3].line_length, &get->texture[3].endian);
	get->texture[4].addr = (int *)mlx_get_data_addr(get->texture[4].img,
			&get->texture[4].bits_per_pixel,
			&get->texture[4].line_length, &get->texture[4].endian);
}
