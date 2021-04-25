#include "../include/cub3d.h"

void ft_printf_map(t_get *get)
{
  int i;

  i = 0;
  while (get->map[i])
  {
    printf("%s\n", get->map[i]);
    i++;
  }
}

void ft_parsing_check_errors(char *file, t_get *get)
{
	int fd;
	int ret;
	char *read;

	ret = 1;
  read = NULL;
	if ((fd = open(file, O_DIRECTORY)) != -1)
		ft_error(get, "Invalid : is a directory\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(get, "Invalid .cub file\n");
	while (ret != 0)
	{
		ret = get_next_line(fd, &read, get);
		if (get->error > 0)
		{
			free(read);
			ft_error(get, "error while parsing");
		}
		ft_get_cub_info(get, read);
		free(read);
		if (get->error > 0)
			ft_error(get, "error in getting map info");
	}
	close(fd);
	ft_copy_map(file, read, get);
}

int ft_cub3d(char *str, t_get *get)
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
			ft_error(get, "Map's name invalid no '.'\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing_check_errors(str, get);
	else
		ft_error(get, "Map's name invalid\n");
  ft_get_depart(get);
  if (get->ry <= 0 || get->rx <= 0)
    ft_error(get, "Bad resolution");
  if (get->f == -1 || get->c == -1)
    ft_error(get, "Bad color");
  ft_mlx(get);
  return (1);
}

int main(int ac, char** av)
{
  t_get get;

	ft_init(&get);
	if (ac == 2 || (ac == 3 && ft_check_save(av[2])))
	{
		if (ac == 3 && ft_check_save(av[2]))
			get.save = 1;
		ft_cub3d(av[1], &get);
	}
	else
	{
  	write(1, "Invalid args\n", 12);
    return (0);
  }
  return (1);
}
