#include "../include/cub3d.h"

int ft_check_save(char *str)
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

void ft_create_bmp(t_get *get)
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
    ft_exit(get);
}

void ft_bmp_header(t_get *get, int fd)
{
  int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * get->rx * get->ry; // file size
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);// 2 reserved bytes
	write(fd, &tmp, 2);//
	tmp = 54; //combined total value of the bitmap headers in bytes
	write(fd, &tmp, 4);
	tmp = 40; // size of the bitmapinfoheader part
	write(fd, &tmp, 4);
	write(fd, &get->rx, 4);// image height and width
	write(fd, &get->ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);//always one (planes)
	write(fd, &get->mlx.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);//default
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}
