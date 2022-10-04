/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:02:43 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 10:09:19 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_save(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && str[i - 3] == 'a' &&
		str[i - 4] == 's' && str[i - 5] == '-' && str[i - 6] == '-'
		&& ft_strlen(str) < 7)
		return (1);
	return (0);
}

void	ft_create_bmp(t_get *get)
{
	int	fd;
	int	x;
	int	y;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_error(get, "BMP file creation failed\n");
	system("chmod 777 image.bmp");
	ft_bmp_header(get, fd);
	y = get->ry;
	while (y >= 0)
	{
		x = 0;
		while (x < get->rx)
		{
			write(fd, &get->mlx.addr[y * get->rx + x], 4);
			x++;
		}
		y--;
	}
	ft_exit_raycasting(get);
}

/*
** file size
** 2 reserved bytes
** combined total value of the bitmap headers in bytes
** size of the bitmapinfoheader part
** image height and width
** always one (planes)
** default
*/

void	ft_bmp_header(t_get *get, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * get->rx * get->ry;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &get->rx, 4);
	write(fd, &get->ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &get->mlx.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}
