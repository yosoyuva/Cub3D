/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:08:42 by ymehdi            #+#    #+#             */
/*   Updated: 2019/04/10 15:41:25 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*st;
	int		l;

	i = 0;
	if (s)
	{
		l = ft_strlen(s);
		if (!(st = (char *)malloc(sizeof(char) * (l + 1))))
			return (NULL);
	}
	if (s)
	{
		while (s[i])
		{
			st[i] = (*f)(s[i]);
			i++;
		}
		st[i] = '\0';
	}
	return (st);
}
