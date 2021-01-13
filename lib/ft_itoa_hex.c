/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:49:06 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/09 13:17:05 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_nlength_hex(int n)
{
	int							size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

void			ft_itoa_hex_a(int *i, unsigned int *nb, char **s)
{
	while (*i >= 0 && (*s)[*i] != '-')
	{
		if (*nb % 16 < 10)
		{
			(*s)[*i] = (*nb % 16) % 16 + 48;
			*nb = *nb / 16;
		}
		else
		{
			(*s)[*i] = *nb % 10 + 'a';
			*nb = *nb / 16;
		}
		(*i)--;
	}
}

char			*ft_itoa_hex(int n)
{
	int				i;
	unsigned	int nb;
	char			*s;

	s = ft_strnew(ft_nlength_hex(n) + 1);
	i = ft_nlength_hex(n) - 1;
	s[i] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;
	ft_itoa_hex_a(&i, &nb, &s);
	return (s);
}
