/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:41:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/08 18:41:54 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_zero(size_t size)
{
	void	*s;

	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	ft_memset(s, '0', size + 1);
	return (s);
}

char	*ft_strnew_zero_f(char *str, size_t size)
{
	void	*s;

	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	ft_memset(s, '0', size + 1);
	free(str);
	return (s);
}
