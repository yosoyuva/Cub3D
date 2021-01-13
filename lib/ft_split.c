/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:25:38 by ymehdi            #+#    #+#             */
/*   Updated: 2019/11/19 12:08:50 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char			*ft_word(const char *s, char c, int *i)
{
	char	*str;
	int		k;

	if (!(str = (char *)malloc(sizeof(str) * (ft_strlen(s)))))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char				**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wrd = ft_count_words(s, c);
	if (!(str = (char **)malloc(sizeof(str) * (ft_count_words(s, c) + 2))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < wrd && s[i])
	{
		str[j] = ft_word(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
