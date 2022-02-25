/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:30:17 by shan              #+#    #+#             */
/*   Updated: 2022/02/25 23:10:31 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

char	*ft_read(int fd, char *save)
{
	char	*buf;
	int		bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buff[0] = '\0';
	bytes = 1;
	while (!(ft_strchr(buf, '\n')) && bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (*save)
	{
		while (save[i] && save[i] != '\n')
			i++;
		line = malloc(sizeof(char) * (i + 2));
		if (!line)
			return (NULL);
		line = ft_strcpy(line, save);
	}
	save = ft_save(save);
	return (line);
}
