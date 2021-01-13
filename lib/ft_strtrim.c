/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:26:17 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/01 14:27:01 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && ft_isset(s1[i], set))
		i += 1;
	j = ft_strlen(&s1[i]) - 1;
	while (s1[i] && ft_isset(s1[j + i], set))
		j -= 1;
	if (!(str = ft_strnew(j + 1)))
		return (NULL);
	ft_strncpy(str, (s1 + i), (j + 1));
	return (str);
}
