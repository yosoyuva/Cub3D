/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:19:20 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/25 22:23:39 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_is_char_map(char *str, int *i)
{
	if (str[*i] != ' ' && str[*i] != '0' && str[*i] != '1' \
		&& str[*i] != '2' && str[*i] != 'N' && str[*i] != 'S' \
		&& str[*i] != 'E' && str[*i] != 'W' && str[*i] != '\n'
		&& str[*i] != '\t')
	{
		return (0);
	}
	return (1);
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
