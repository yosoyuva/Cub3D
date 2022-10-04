/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cub_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:03:13 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 15:42:57 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_get_cub_info_aux(t_get *get, char *read, int *i)
{
	if (read[*i] == 'R')
	{
		ft_resolution(get, read, i);
		return (1);
	}
	else if (read[*i] == 'N' && read[*i + 1] == 'O')
	{
		ft_texture_no(get, read, i);
		return (1);
	}
	else if (read[*i] == 'S' && read[*i + 1] == 'O')
	{
		ft_texture_so(get, read, i);
		return (1);
	}
	else if (read[*i] == 'W' && read[*i + 1] == 'E')
	{
		ft_texture_we(get, read, i);
		return (1);
	}
	return (0);
}

void	ft_get_cub_info(t_get *get, char *read)
{
	int	i;

	i = 0;
	if (read[i])
	{
		ft_iswhite_space(&i, read);
		if (ft_get_cub_info_aux(get, read, &i))
			i = i + 0;
		else if (read[i] == 'E' && read[i + 1] == 'A')
			ft_texture_ea(get, read, &i);
		else if (read[i] == 'S' && read[i + 1] != 'O')
			ft_texture_sprite(get, read, &i);
		else if (read[i] == 'F')
			ft_color_floor(get, read, &i);
		else if (read[i] == 'C')
			ft_color_ceiling(get, read, &i);
		else if (read[i] == '1')
			ft_map(get, read, &i);
		else if (read[i] == '\n' && (get->linesize > 0 || get->nblines > 0))
			get->error = 10;
		else
			get->error = 1;
		ft_iswhite_space(&i, read);
	}
}

void	ft_get_depart(t_get *get)
{
	int	i;
	int	j;

	i = 0;
	while (get->map[i])
	{
		j = 0;
		while (get->map[i][j])
		{
			if (get->map[i][j] == 'N' || get->map[i][j] == 'S' \
				|| get->map[i][j] == 'E' || get->map[i][j] == 'W')
			{
				get->dx = i;
				get->dy = j;
				get->depart = get->map[i][j];
				get->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

char	*ft_get_path(char *str, int *i, t_get *get)
{
	char	*path;
	int		j;

	j = -1;
	*i = ft_iswhite_space(i, str);
	if (str[*i] == '.' && str[*i + 1] == '/')
	{
		if (!(path = malloc(sizeof(char) * (ft_strlen2(str) + 1))))
			ft_error(get, "malloc path");
		while (++j <= ft_strlen2(str))
			path[j] = 0;
		j = 0;
		while (str[*i] != '\0')
		{
			path[j] = str[*i];
			j++;
			(*i)++;
		}
		j--;
		while (ft_iswhite_spaces(&j, path))
			path[j--] = 0;
		return (path);
	}
	return (NULL);
}
