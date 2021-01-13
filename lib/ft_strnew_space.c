/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:47:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/12 22:07:57 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_space(size_t size)
{
	char	*s;

	if ((s = malloc(sizeof(s) * (size + 2))) == NULL)
		return (NULL);
	ft_memset(s, ' ', size + 1);
	s[size + 1] = '\0';
	return (s);
}

char	*ft_strnew_space_f(char *str, size_t size)
{
	char	*s;

	if ((s = malloc(sizeof(s) * (size + 2))) == NULL)
		return (NULL);
	ft_memset(s, ' ', size + 1);
	free(str);
	s[size + 1] = '\0';
	return (s);
}
