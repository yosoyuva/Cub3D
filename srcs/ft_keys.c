#include "../include/cub3d.h"

int ft_key_press(int keycode, t_get *get)
{
  if (keycode == FORWARD_W_Z)
		get->mlx.forward = 1;
	else if (keycode == BACK_S_S)
		get->mlx.back = 1;
	else if (keycode == LEFT_A_Q)
		get->mlx.left = 1;
	else if (keycode == RIGHT_D_D)
		get->mlx.right = 1;
	else if (keycode == ROTATE_LEFT)
		get->mlx.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		get->mlx.rotate_right = 1;
	else if (keycode == ESC_ESC)
		ft_exit(get);
	return (1);
}

int ft_key_release(int keycode, t_get *get)
{
  if (keycode == FORWARD_W_Z)
		get->mlx.forward = 0;
	else if (keycode == BACK_S_S)
		get->mlx.back = 0;
	else if (keycode == LEFT_A_Q)
		get->mlx.left = 0;
	else if (keycode == RIGHT_D_D)
		get->mlx.right = 0;
	else if (keycode == ROTATE_LEFT)
		get->mlx.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		get->mlx.rotate_right = 0;
	return (1);
}
