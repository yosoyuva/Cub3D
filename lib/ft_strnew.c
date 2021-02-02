/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:47:16 by ymehdi            #+#    #+#             */
/*   Updated: 2021/02/02 16:46:36 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_lib(size_t size)
{
	void	*s;

	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}
