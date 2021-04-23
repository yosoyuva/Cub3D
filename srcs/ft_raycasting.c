#include "../include/cub3d.h"

int ft_mlx(t_get *get)
{
  //t_mlx_id mlx_id;
  //t_data mlx;
  //t_mystruct mystruct;

  get->mlx.i = 1;
  get->c = 2552030;
  get->f = 338238976;
  printf("c = %d, f = %d \n", get->c, get->f);
  ft_init_sprites(get);
  ft_init_raycasting(get);
  printf("init raycasting part\n");
  if (!(get->mlx.ptr = mlx_init()))// Connecting to the minilibx and save the ID connection to mlx_ptr
    ft_error(get, "Mlx initialization failed\n");
  ft_mlx_win_img(get);
  printf("hook part\n");
/*  mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
  //mlx_key_hook(mlx_id.mlx_win, esc_hook, &mlx_id);
  //mlx_hook(mlx_id.mlx_win, 5, 1<<, function, param dont a potentielment besoin functiojn)
  hello_bye_mouse(&mlx);
  mlx.ptr = mlx.ptr;
  mlx.win = mlx.win;
  mlx_loop_hook(mlx.ptr, render_next_frame, &mlx);*/
  //mlx_loop(get->mlx.ptr);// A loop to keep the connection up

  /*get->mlx.img2 = mlx_new_image(get->mlx.ptr, get->rx, get->ry);
	get->mlx.addr2 = (int *)mlx_get_data_addr(get->mlx.img2, &get->
			mlx.bits_per_pixel, &get->mlx.line_length, &get->mlx.endian);*/


  mlx_hook(get->mlx.win, 33, 1L << 17, ft_exit, get);// destroy windowwhen clicking on the cross
	mlx_hook(get->mlx.win, 2, 1L << 0, ft_key_press, get);
	mlx_loop_hook(get->mlx.ptr, ft_raycasting, get);
	mlx_hook(get->mlx.win, 3, 1L << 1, ft_key_release, get);
	mlx_loop(get->mlx.ptr);
  return (1);
}

int ft_raycasting(t_get *get)
{
  get->ray.x = 0;// on initialise
  while (get->ray.x < get->rx)
  {
    ft_init_raycasting2(get);
    ft_dda(get);
    ft_draw_color(get);
    get->sprite.zbuffer[get->ray.x] = get->ray.perpwalldist;
    (get->ray.x)++;
  }
  //printf("boucle while raycasting\n");
  ft_sprite(get);
  mlx_put_image_to_window(get->mlx.ptr, get->mlx.win, get->mlx.img, 0, 0);
  ft_forward_back(get);
	ft_left_right(get);
  ft_rotate_right_left(get);



/*  void *tmp;

	tmp = get->mlx.img;
	get->mlx.img = get->mlx.img2;
	get->mlx.img2 = tmp;
	tmp = get->mlx.addr;
	get->mlx.addr = get->mlx.addr2;
	get->mlx.addr2 = tmp; */



  return (1);
}

void ft_draw_color(t_get *get)
{
  int y;

  y = 0;
  get->ray.drawend = get->ry - get->ray.drawstart;
  while (y < get->ray.drawstart)
  {
    get->mlx.addr[y * get->rx + get->ray.x] = get->c;
    y++;
  }
  if (y <= get->ray.drawend)
    ft_draw(get, y);
  y = get->ray.drawend + 1;
  while (y < get->ry)
  {
    get->mlx.addr[y * get->rx + get->ray.x] = get->f;
    y++;
  }
}

void ft_draw(t_get *get, int y)
{
  y = get->ray.drawstart;
  ft_init_texture(get);
  get->text.texx = (int)(get->text.wallx * (double)get->textures
			[get->text.texface].width);
	if (get->ray.side == 0 && get->ray.raydirx > 0)
		get->text.texx = get->textures[get->text.texface].width -
			get->text.texx - 1;
	if (get->ray.side == 1 && get->ray.raydiry < 0)
		get->text.texx = get->textures[get->text.texface].width -
			get->text.texx - 1;
  get->text.step = 1.0 * get->textures[0].height / get->ray.lineheight;
  get->text.texpos = (get->ray.drawstart - get->ry / 2 + \
    get->ray.lineheight / 2) * get->text.texpos;
  while (y <= get->ray.drawend)
  {
    get->text.texy = (int)get->text.texpos &
			(get->textures[get->text.texface].height - 1);
		get->text.texpos += get->text.step;
  	if (y < get->ry && get->ray.x < get->rx)
			get->mlx.addr[y * get->rx + get->ray.x] =
				get->textures[get->text.texface].addr[get->text.texy *
					get->textures[get->text.texface].line_length / 4 + get->text.texx];
    y++;
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
      get->ray.hit = 1;
    //ft_dist(get);
  }
  ft_dist(get);
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
  get->mlx.addr = (int *)mlx_get_data_addr(get->mlx.img, &(get->mlx.bits_per_pixel), &(get->mlx.line_length),
                                &(get->mlx.endian));
}


void ft_get_texture(t_get *get)
{
  if (!(get->textures[0].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->no, &(get->textures[0].width),
					&(get->textures[0].height))))
		ft_error(get, "Texture SO\n");
	if (!(get->textures[1].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->so, &(get->textures[1].width),
					&(get->textures[1].height))))
		ft_error(get, "Texture NO\n");
	if (!(get->textures[2].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->we, &(get->textures[2].width),
					&(get->textures[2].height))))
		ft_error(get, "Texture EA\n");
	if (!(get->textures[3].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->ea, &(get->textures[3].width),
					&(get->textures[3].height))))
		ft_error(get, "Texture WE\n");
	if (!(get->textures[4].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->s, &(get->textures[4].width),
					&(get->textures[4].height))))
		ft_error(get, "Texture S\n");
	ft_get_texture_addr(get);
}

void ft_get_texture_addr(t_get *get)
{
  get->textures[0].addr = (int *)mlx_get_data_addr(get->textures[0].img,
			&get->textures[0].bits_per_pixel,
			&get->textures[0].line_length, &get->textures[0].endian);
	get->textures[1].addr = (int *)mlx_get_data_addr(get->textures[1].img,
			&get->textures[1].bits_per_pixel,
			&get->textures[1].line_length, &get->textures[1].endian);
	get->textures[2].addr = (int *)mlx_get_data_addr(get->textures[2].img,
			&get->textures[2].bits_per_pixel,
			&get->textures[2].line_length, &get->textures[2].endian);
	get->textures[3].addr = (int *)mlx_get_data_addr(get->textures[3].img,
			&get->textures[3].bits_per_pixel,
			&get->textures[3].line_length, &get->textures[3].endian);
	get->textures[4].addr = (int *)mlx_get_data_addr(get->textures[4].img,
			&get->textures[4].bits_per_pixel,
			&get->textures[4].line_length, &get->textures[4].endian);
}
