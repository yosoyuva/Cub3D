/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 08:51:10 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 10:04:28 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_mlx(t_get *get)
{
	ft_init_sprites(get);
	ft_init_raycasting(get);
	if (!(get->mlx.ptr = mlx_init()))
		ft_error(get, "Mlx initialization failed\n");
	ft_mlx_win_img(get);
	if (get->save)
		ft_raycasting(get);
	mlx_hook(get->mlx.win, 33, 1L << 17, ft_exit_raycasting, get);
	mlx_hook(get->mlx.win, 2, 1L << 0, ft_key_press, get);
	mlx_loop_hook(get->mlx.ptr, ft_raycasting, get);
	mlx_hook(get->mlx.win, 3, 1L << 1, ft_key_release, get);
	mlx_loop(get->mlx.ptr);
	return (1);
}

void	ft_mlx_win_img(t_get *get)
{
	mlx_get_screen_size(get->mlx.ptr, &get->screen_rx, &get->screen_ry);
	get->rx_save = get->rx;
	get->ry_save = get->ry;
	get->rx = (get->rx > get->screen_rx) ? get->screen_rx : get->rx;
	get->ry = (get->ry > get->screen_ry) ? get->screen_ry : get->ry;
	ft_get_texture(get);
	if (get->save)
	{
		get->rx = get->rx_save;
		get->ry = get->ry_save;
	}
	else
		get->mlx.win = mlx_new_window(get->mlx.ptr, get->rx, get->ry, "Cub3D");
	get->mlx.img = mlx_new_image(get->mlx.ptr, get->rx, get->ry);
	get->mlx.addr = (int *)mlx_get_data_addr(get->mlx.img, \
		&(get->mlx.bits_per_pixel), &(get->mlx.line_length), \
		&(get->mlx.endian));
}

void	ft_get_texture(t_get *get)
{
	if (!(get->textures[0].img = mlx_xpm_file_to_image(get->mlx.ptr, \
		get->no, &(get->textures[0].width), \
		&(get->textures[0].height))))
		ft_error(get, "Texture NO\n");
	if (!(get->textures[1].img = mlx_xpm_file_to_image(get->mlx.ptr, \
		get->so, &(get->textures[1].width), &(get->textures[1].height))))
		ft_error(get, "Texture SO\n");
	if (!(get->textures[2].img = mlx_xpm_file_to_image(get->mlx.ptr, \
		get->we, &(get->textures[2].width), &(get->textures[2].height))))
		ft_error(get, "Texture EA\n");
	if (!(get->textures[3].img = mlx_xpm_file_to_image(get->mlx.ptr,
					get->ea, &(get->textures[3].width),
					&(get->textures[3].height))))
		ft_error(get, "Texture WE\n");
	if (!(get->textures[4].img = mlx_xpm_file_to_image(get->mlx.ptr, \
		get->s, &(get->textures[4].width), &(get->textures[4].height))))
		ft_error(get, "Texture S\n");
	ft_get_texture_addr(get);
}

void	ft_get_texture_addr(t_get *get)
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
