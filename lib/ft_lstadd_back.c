/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:46:05 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/10 15:20:05 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return ;
	list = *alst;
	if (new && alst && *alst)
	{
		while (list->next)
			list = list->next;
		list->next = new;
		new->next = NULL;
	}
	if (*alst == NULL)
		*alst = new;
}
