/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:48:53 by yong-lee          #+#    #+#             */
/*   Updated: 2021/01/13 11:46:47 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_newline(char *s1)
{
	int		i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *s1)
{
	int		i;
	char	*res;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_save(char *s1)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (0);
	}
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) - i + 1))))
		return (0);
	i++;
	while (s1[i])
	{
		res[j++] = s1[i++];
	}
	res[j] = '\0';
	free(s1);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[32];
	char			*buf;
	int				read_byte;

	read_byte = 1;
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!is_newline(save[fd]) && read_byte != 0)
	{
		if ((read_byte = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[read_byte] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	free(buf);
	*line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	if (read_byte == 0)
		return (0);
	return (1);
}
