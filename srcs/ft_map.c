/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:21:00 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 08:51:40 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** check si de description de map est conforme (sinon get-error = 2)
**et recupere le nombre de ligne et la taille de la plus grande
*/

int		ft_map(t_get *get, char *str, int *i)
{
	get->map_on = 1;
	if (str[*i] != '1')
	{
		get->error = 2;
		return (0);
	}
	if (ft_is_char_map(str, i))
	{
		if (ft_check_line_fencing(&str[*i]) == 0)
		{
			get->error = 6;
			return (0);
		}
	}
	else
	{
		get->error = 6;
		return (0);
	}
	if ((int)ft_strlen(str) > get->linesize)
		get->linesize = ft_strlen(str) + 1;
	get->nblines = get->nblines + 1;
	return (1);
}

void	ft_copy_map_aux2(int *i, t_get *get)
{
	while (*i < get->nblines)
	{
		if (!(get->map[*i] = malloc(sizeof(char) * (get->linesize + 1))))
			ft_error(get, "malloc map");
		ft_bzero(get->map[*i], sizeof(char) * (get->linesize + 1));
		*i = *i + 1;
	}
	*i = 0;
}

int		ft_copy_map(char *file, char *read, t_get *get)
{
	int	fd;
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	fd = open(file, O_RDONLY);
	if (!(get->map = malloc(sizeof(char *) * (get->nblines + 1))))
		ft_error(get, "malloc map");
	ft_bzero(get->map, sizeof(char *) * (get->nblines + 1));
	ft_copy_map_aux2(&i, get);
	while (ret != 0)
	{
		ret = get_next_line(fd, &read, get);
		if (ft_is_map(read))
		{
			ft_copy_map_aux(read, get->map[i]);
			i++;
		}
		free(read);
	}
	close(fd);
	ft_verify(get);
	return (1);
}

void	ft_copy_map_aux(char *str, char *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		map[i] = str[i];
		i++;
	}
	map[i] = '\0';
}
