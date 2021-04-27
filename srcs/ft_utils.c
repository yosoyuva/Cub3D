/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:19:20 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 00:27:58 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_is_char_map(char *str, int *i)
{
	int	j;

	j = *i;
	while (!(str[*i] != ' ' && str[*i] != '0' && str[*i] != '1' \
		&& str[*i] != '2' && str[*i] != 'N' && str[*i] != 'S' \
		&& str[*i] != 'E' && str[*i] != 'W' && str[*i] != '\n'
		&& str[*i] != '\t'))
	{
		*i = *i + 1;
		//return (0);
	}
	if (str[*i] == 0)
	{
		*i = j;
		return (1);
	}
	return (0);
}

int		ft_is_map(char *str)
{
	int	i;

	i = 0;
	ft_iswhite_space(&i, str);
	if (str[i] == '1')
		return (1);
	return (0);
}

int		ft_rest_is_wspace(char *str, int *i)
{
	int	j;

	j = *i;
	ft_iswhite_space(&j, str);
	if (str[j] != '\n' && str[j] != '\0')
		return (0);
	return (1);
}

int		ft_create_rgb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int		ft_strlen2(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '.')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}
