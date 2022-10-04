/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:23:41 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 11:24:12 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strnew(int size, int a)
{
	void		*s;
	int			i;

	i = 0;
	if (a == 7)
		if (size < 1)
			return (NULL);
	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		((char *)s)[i] = '\0';
		i++;
	}
	return (s);
}
