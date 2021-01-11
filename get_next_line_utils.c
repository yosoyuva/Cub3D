/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:48:39 by ymehdi            #+#    #+#             */
/*   Updated: 2020/01/24 15:57:30 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dst[pos] = src[pos];
		pos++;
	}
	if (src[pos] == '\0')
		dst[pos] = '\0';
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	while (s1[j] != '\0')
		j++;
	i = 0;
	while (s2[i] != '\0')
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		return (ft_strnew(0, 1));
	}
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}
