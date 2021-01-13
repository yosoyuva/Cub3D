/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:10:27 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/09 13:17:18 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_nlength(int n)
{
	int						size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char						*ft_itoa(int n)
{
	int				i;
	unsigned	int nb;
	char			*s;

	s = ft_strnew(ft_nlength(n) + 1);
	i = ft_nlength(n);
	s[i] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	else
		while (--i >= 0)
		{
			s[i] = n % 10 + 48;
			n = n / 10;
		}
	while (--i > 0)
	{
		s[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (s);
}

int							ft_nlength_u(unsigned int n)
{
	int						size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char						*ft_itoa_u(unsigned int n)
{
	int						i;
	char					*s;

	s = ft_strnew(ft_nlength_u(n) + 1);
	i = ft_nlength_u(n);
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
