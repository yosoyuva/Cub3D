/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:46:23 by ymehdi            #+#    #+#             */
/*   Updated: 2021/04/27 11:24:00 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

int		ft_aux(char **red, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (red[fd][i] != '\n' && red[fd][i] != '\0')
		i++;
	if (red[fd][i] == '\n')
	{
		if (((*line = ft_strsub(red[fd], 0, i)) == NULL))
			return (-1);
		tmp = ft_strsub(red[fd], i + 1, ft_strlen(red[fd]));
		free(red[fd]);
		red[fd] = tmp;
		if (red[fd][0] == '\0')
			ft_strdel(&red[fd]);
	}
	else if (red[fd][i] == '\0')
	{
		if ((*line = ft_strsub(red[fd], 0, ft_strlen(red[fd]))) == NULL)
			return (-1);
		ft_strdel(&red[fd]);
		return (0);
	}
	return (1);
}

int		ft_del_static(t_get *get, char **red, int fd)
{
	if (get->error)
	{
		ft_strdel(&red[fd]);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line, t_get *get)
{
	static char			*red[1024];

	if (ft_del_static(get, red, fd) == 1)
		return (0);
	if (fd < 0 || line == NULL || !(get->var.buf = ft_strnew(BUFFER_SIZE, 7)))
		return (-1);
	while ((get->var.ret = read(fd, get->var.buf, BUFFER_SIZE)) > 0)
	{
		get->var.buf[get->var.ret] = '\0';
		if (red[fd] == NULL)
			if (!(red[fd] = ft_strnew(1, 1)))
				return (-1);
		get->var.tmp = ft_strjoin(red[fd], get->var.buf);
		free(red[fd]);
		red[fd] = get->var.tmp;
		if (ft_strchr(get->var.buf, '\n'))
			break ;
	}
	if (get->var.ret < 0 || BUFFER_SIZE < 1)
		return (-1);
	else if (get->var.ret == 0 && (red[fd] == NULL || red[fd][0] == '\0'))
		*line = ft_strnew(0, 1);
	free(get->var.buf);
	return (get->var.ret == 0 && (red[fd] == NULL || red[fd][0] == '\0')) \
	? (0) : (ft_aux(red, line, fd));
}
