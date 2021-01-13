/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:11:42 by ymehdi            #+#    #+#             */
/*   Updated: 2019/04/06 17:14:51 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	pos;

	pos = 0;
	while (pos < len && src[pos] != '\0')
	{
		dst[pos] = src[pos];
		pos++;
	}
	while (pos < len)
	{
		dst[pos] = '\0';
		pos++;
	}
	return (dst);
}
