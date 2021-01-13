/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:18:34 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/14 16:36:07 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlength_hex_long(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

int		ft_nlength_hex_long_p(unsigned long int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_hex_long(unsigned int nb)
{
	int				i;
	char			*s;

	s = ft_strnew(ft_nlength_hex_long(nb));
	i = ft_nlength_hex_long(nb) - 1;
	s[i] = '\0';
	while (i >= 0 && s[i] != '-')
	{
		if (nb % 16 < 10)
		{
			s[i] = nb % 16 + 48;
			nb = nb / 16;
		}
		else
		{
			s[i] = (nb % 16) % 10 + 'a';
			nb = nb / 16;
		}
		i--;
	}
	return (s);
}

char	*ft_itoa_hex_long_m(unsigned int nb)
{
	int				i;
	char			*s;

	s = ft_strnew(ft_nlength_hex_long(nb));
	i = ft_nlength_hex_long(nb) - 1;
	s[i] = '\0';
	while (i >= 0 && s[i] != '-')
	{
		if (nb % 16 < 10)
		{
			s[i] = nb % 16 + 48;
			nb = nb / 16;
		}
		else
		{
			s[i] = (nb % 16) % 10 + 'A';
			nb = nb / 16;
		}
		i--;
	}
	return (s);
}

char	*ft_itoa_hex_long_p(unsigned long int nb)
{
	int				i;
	char			*s;

	s = ft_strnew(ft_nlength_hex_long_p(nb));
	i = ft_nlength_hex_long_p(nb) - 1;
	s[i] = '\0';
	while (i >= 0 && s[i] != '-')
	{
		if (nb % 16 < 10)
		{
			s[i] = nb % 16 + 48;
			nb = nb / 16;
		}
		else
		{
			s[i] = (nb % 16) % 10 + 'a';
			nb = nb / 16;
		}
		i--;
	}
	return (s);
}
